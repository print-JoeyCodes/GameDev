#include "background.hpp"
#include <cmath>

Background::Background(int width) {
    this->width = width;
}

void Background::Draw(const Camera2D& camera, float screenWidth, float screenHeight) {
    // Calculate the visible world area based on camera
    Vector2 screenCenter = { screenWidth/2.0f, screenHeight/2.0f };
    Vector2 worldTopLeft = GetScreenToWorld2D({0, 0}, camera);
    Vector2 worldBottomRight = GetScreenToWorld2D({screenWidth, screenHeight}, camera);
    
    // Add margin of two squares on all sides to guarantee coverage
    int firstStripeY = ((int)std::floor(worldTopLeft.y / stripeHeight) - 2) * stripeHeight;
    int lastStripeY = ((int)std::ceil(worldBottomRight.y / stripeHeight) + 2) * stripeHeight;
    int firstStripeX = ((int)std::floor(worldTopLeft.x / stripeHeight) - 2) * stripeHeight;
    int lastStripeX = ((int)std::ceil(worldBottomRight.x / stripeHeight) + 2) * stripeHeight;

    // Draw checkered pattern
    for (int y = firstStripeY; y <= lastStripeY; y += stripeHeight) {
        for (int x = firstStripeX; x <= lastStripeX; x += stripeHeight) {
            int xIndex = (int)std::floor((float)x / stripeHeight);
            int yIndex = (int)std::floor((float)y / stripeHeight);
            Color color = ((xIndex + yIndex) % 2 == 0) ? oceanBlue : lightBlue;
            DrawRectangle(x, y, stripeHeight, stripeHeight, color);
        }
    }
}

void Background::Reset(int width) {
    this->width = width;
}
