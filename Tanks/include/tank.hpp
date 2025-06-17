#pragma once
#include "/opt/homebrew/opt/raylib/include/raylib.h"

class Tank {
    public:
        Tank(float x, float y, Color color);
        void Draw();
        void MoveCannon(KeyboardKey left, KeyboardKey right);
        void MoveTank(float x, float y);
        float GetRadius() const { return radius; };

    private:
        float x;
        float y;
        float radius = 55.0f;
        float cannonRotation = 310.0f;
        Rectangle cannon;
        Color color;
};