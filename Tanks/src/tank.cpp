#include "tank.hpp"

Tank::Tank(float x, float y, Color color) {
    this->x = x;
    this->y = y;
    this->color = color;
    cannon = {x, y, 85, 25};
}

void Tank::Draw() {
    DrawRectanglePro(cannon, {0, 12.5}, cannonRotation, BLUE);
    DrawCircle(x, y, radius, color);
}

void Tank::MoveCannon(KeyboardKey left, KeyboardKey right) {
    if (IsKeyDown(left)) {
        cannonRotation -= 2;
    }

    if (IsKeyDown(right)) {
        cannonRotation += 2;
    }
    
    if (cannonRotation < 210) {
        cannonRotation = 210;
    } else if (cannonRotation >= 330) {
        cannonRotation = 330;
    }
}

void Tank::MoveTank(float x, float y) {
    this->x = x;
    this->y = y;
    cannon = {x, y, 85, 25};
}
