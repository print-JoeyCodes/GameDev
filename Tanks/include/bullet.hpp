#pragma once
#include "/opt/homebrew/opt/raylib/include/raylib.h"

class Tank;


class Bullet {
    public:
        Bullet(const Tank& origin);
        void Update();
        void Draw();

    private:
        const Tank& origin;
        float x;
        float y;
        float speed;
        float radius;
        float angle;
        Color color;
};