#include "boat.h"
#include "/opt/homebrew/opt/raylib/include/raymath.h"

Color brown = {67, 47, 33, 255};

Boat::Boat() {
    x = 200;
    y = 200;
    width = 80;
    tipHeight = 60;
    deckHeight = 150;
    height = tipHeight + deckHeight;
    rotation = 0;
    speed = 0;
    center = {x + width / 2, y + deckHeight / 2};
    vertice1 = {center.x - width / 2, center.y - deckHeight / 2};
    vertice2 = {center.x + width / 2, center.y - deckHeight / 2};
    vertice3 = {center.x, center.y - deckHeight / 2 - tipHeight};
}

Vector2 RotatePoint(Vector2 point, Vector2 center, float angle) {
    Vector2 translated = {point.x - center.x, point.y - center.y };
    Vector2 rotated = Vector2Rotate(translated, angle);
    return {rotated.x + center.x, rotated.y + center.y };
}

void Boat::Draw() {
    DrawRectanglePro({center.x, center.y, width, deckHeight}, {width/2, deckHeight/2}, rotation, brown);
    DrawTriangle(rotatedVertice1, rotatedVertice2, rotatedVertice3, brown);
    DrawCircleV(center, 5, RED);
}

void Boat::HandleInput() {
    if(IsKeyDown(KEY_RIGHT)) {
        rotation += 1;
        if (rotation > 360) rotation = 0;
    }
    else if(IsKeyDown(KEY_LEFT)) {
        rotation -= 1;
        if (rotation < 0) rotation = 360;
    }
    if(IsKeyDown(KEY_UP)) {
        speed += 0.2f;
        if (speed > 10) speed = 10;
    }
    if(IsKeyDown(KEY_DOWN)) {
        speed -= 0.2f;
        if (speed < -10) speed = -10;
    }
    if(IsKeyPressed(KEY_R)) {
        Reset();
    }
}

void Boat::Update() {
    HandleInput();
    speed -= speed * resistance;
    if (speed < 0.1f && speed > -0.1f) speed = 0;
    center.x += sinf(rotation * DEG2RAD) * speed;
    center.y -= cosf(rotation * DEG2RAD) * speed;

    vertice1 = {center.x - width / 2, center.y - deckHeight / 2};
    vertice2 = {center.x + width / 2, center.y - deckHeight / 2};
    vertice3 = {center.x, center.y - deckHeight / 2 - tipHeight};

    rotatedVertice1 = RotatePoint(vertice1, center, rotation * DEG2RAD);
    rotatedVertice2 = RotatePoint(vertice2, center, rotation * DEG2RAD);
    rotatedVertice3 = RotatePoint(vertice3, center, rotation * DEG2RAD);

    Draw();
}

void Boat::Reset() {
    x = 200;
    y = 200;
    width = 80;
    tipHeight = 60;
    deckHeight = 150;
    height = tipHeight + deckHeight;
    rotation = 0;
    speed = 0;
    center = {x + width / 2, y + deckHeight / 2};
    vertice1 = {center.x - width / 2, center.y - deckHeight / 2};
    vertice2 = {center.x + width / 2, center.y - deckHeight / 2};
    vertice3 = {center.x, center.y - deckHeight / 2 - tipHeight};
}
