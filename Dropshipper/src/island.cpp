#include "island.hpp"
#include "/opt/homebrew/opt/raylib/include/raymath.h"

Island::Island(float x, float y, float width, float height, Color color) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->color = color;
    islandPosition = {x, y};
    bounds = {x, y, width, height};
    
}

void Island::Draw() {
    DrawRectangle(x, y, width, height, color);
}

void Island::DrawPointer(Vector2 boatPosition, Camera2D camera, float screenWidth, float screenHeight) {
    // Convert positions to screen space
    Vector2 boatScreenPos = GetWorldToScreen2D(boatPosition, camera);
    Vector2 islandScreenPos = GetWorldToScreen2D(islandPosition, camera);

    // Skip if island is visible on screen
    if (islandScreenPos.x >= 0 && islandScreenPos.x <= screenWidth && 
        islandScreenPos.y >= 0 && islandScreenPos.y <= screenHeight) {
        return;
    }

    // Calculate direction from boat to island (normalized)
    Vector2 dir = Vector2Normalize(Vector2Subtract(islandScreenPos, boatScreenPos));
    if (Vector2Length(dir) < 1e-3f) return; // Avoid division by zero

    // Find intersection with screen edges (with margin)
    float edgeMargin = 20.0f;
    float t = INFINITY;

    // Left/Right edges
    if (fabsf(dir.x) > 1e-3f) {
        if (dir.x > 0) t = fminf(t, (screenWidth - edgeMargin - boatScreenPos.x) / dir.x);  // Right edge
        else          t = fminf(t, (edgeMargin - boatScreenPos.x) / dir.x);                 // Left edge
    }

    // Top/Bottom edges
    if (fabsf(dir.y) > 1e-3f) {
        if (dir.y > 0) t = fminf(t, (screenHeight - edgeMargin - boatScreenPos.y) / dir.y); // Bottom edge
        else          t = fminf(t, (edgeMargin - boatScreenPos.y) / dir.y);                 // Top edge
    }

    if (!isfinite(t)) return; // Safety check

    // Calculate arrow position on screen edge
    Vector2 arrowPos = Vector2Add(boatScreenPos, Vector2Scale(dir, t));

    // Draw arrow (triangle pointing toward the island)
    float arrowSize = 15.0f;
    float angle = atan2f(dir.y, dir.x); // Angle in radians

    Vector2 arrowTip = arrowPos;
    Vector2 arrowBase1 = Vector2Add(arrowPos, Vector2Rotate({-arrowSize, -arrowSize}, angle));
    Vector2 arrowBase2 = Vector2Add(arrowPos, Vector2Rotate({-arrowSize, arrowSize}, angle));

    DrawTriangle(arrowTip, arrowBase1, arrowBase2, RED);
}

void Island::CheckCollisons(Boat& boat) {
    Vector2 boatCenter = boat.GetCenter();

    if (boatCenter.x + boat.width/2 >= x && boatCenter.x - boat.width/2 <= x + width && boatCenter.y + boat.height/2 >= y && boatCenter.y - boat.height/2 <= y + height) {
        const int reflectSpeed = -boat.speed;
        boat.speed = reflectSpeed;
    }
}
