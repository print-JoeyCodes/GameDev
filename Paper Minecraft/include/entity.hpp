#pragma once
#include "/opt/homebrew/opt/raylib/include/raylib.h"

class Entity {
    public:
        Entity(int x, int y, int type, Texture2D textureLeft, Texture2D textureRight);
        void Update();

    private:
        int x;
        int y;
        int velcityY = 0;
        int type;
        int horizon;
        bool jumping = false;
        bool facingLeft = true;
        Texture2D textureLeft;
        Texture2D textureRight;
        void Draw();
        void Move();
};