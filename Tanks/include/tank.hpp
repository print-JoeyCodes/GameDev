#pragma once
#include "/opt/homebrew/opt/raylib/include/raylib.h"
#include "bullet.hpp"

class Tank {
    public:
        Tank(float x, float y, Color tankColor, Color cannonColor);
        void Draw();
        void MoveCannon(KeyboardKey left, KeyboardKey right);
        void MoveTank(float x, float y);
        float GetRadius() const { return radius; };
        float GetX() const { return x; };
        float GetY() const { return y; };
        Color GetCannonColor() const { return cannonColor; };
        float GetCannonRotation() const { return cannonRotation; };
        void Launch();

    private:
        float x;
        float y;
        float radius = 55.0f;
        float cannonRotation = 310.0f;
        Rectangle cannon;
        Color tankColor;
        Color cannonColor;
};