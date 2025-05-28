#include "boat.h"
#include "/opt/homebrew/opt/raylib/include/raymath.h"


Boat::Boat(int right, int left, int up, int down, Color color) {
    this->color = color;
    this->right = right;
    this->left = left;
    this->up = up;
    this->down = down;
    Reset();
}

Vector2 RotatePoint(Vector2 point, Vector2 center, float angle) {
    Vector2 translated = {point.x - center.x, point.y - center.y };
    Vector2 rotated = Vector2Rotate(translated, angle);
    return {rotated.x + center.x, rotated.y + center.y };
}

void Boat::Draw() {
    DrawRectanglePro({center.x, center.y, width, deckHeight}, {width/2, centerYoffset}, rotation, color);
    DrawTriangle(rotatedVertice1, rotatedVertice2, rotatedVertice3, color);
    //DrawCircleV(center, 5, RED);
}

void Boat::HandleInput() {
    if(IsKeyDown(right)) {
        rotationSpeed += RotationMultiplier();
        if (rotationSpeed > 1) rotationSpeed = 1;
    }
    else if(IsKeyDown(left)) {
        rotationSpeed -= RotationMultiplier();
        if (rotationSpeed < -1) rotationSpeed = -1;
    }
    if(IsKeyDown(up)) {
        speed += 0.2f;
        if (speed > 10) speed = 10;
    }
    if(IsKeyDown(down)) {
        speed -= 0.2f;
        if (speed < -10) speed = -10;
    }
    if(IsKeyPressed(KEY_R)) {
        Reset();
    }
}

void Boat::Update() {
    HandleInput();
    rotationSpeed -= rotationSpeed * .08f;

    rotation += rotationSpeed;
    if (rotation > 360) rotation = 0;
    if (rotation < 0) rotation = 360;

    speed -= speed * resistance;
    if (speed < 0.1f && speed > -0.1f) speed = 0;
    if (rotationSpeed < 0.1f && rotationSpeed > -0.1f) rotationSpeed = 0;

    centerYoffset = -0.026f * powf(speed, 3) -1.9 * (speed) + (deckHeight / 2);
    
    center.x += sinf(rotation * DEG2RAD) * speed;
    center.y -= cosf(rotation * DEG2RAD) * speed;
    
    vertice1 = {center.x - width / 2, center.y - centerYoffset};
    vertice2 = {center.x + width / 2, center.y - centerYoffset};
    vertice3 = {center.x, center.y - centerYoffset- tipHeight};
    
    rotatedVertice1 = RotatePoint(vertice1, center, rotation * DEG2RAD);
    rotatedVertice2 = RotatePoint(vertice2, center, rotation * DEG2RAD);
    rotatedVertice3 = RotatePoint(vertice3, center, rotation * DEG2RAD);
    
    Draw();
}

int Boat::RotationMultiplier() {
    const int rotationSpeed = abs(speed);
    if (rotationSpeed <= 0) {
        return 0;
    }
    else if (rotationSpeed > 0 && rotationSpeed < 4) {
        return (-.56 * powf((rotationSpeed - 4), 2))/9 + 1;
    }
    else if (rotationSpeed >= 4) {
        return 1;
    }
    return 0;
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
    rotationSpeed = 0;
    center = {x + width / 2, y + deckHeight / 2};
    centerYoffset = deckHeight / 2;
}
