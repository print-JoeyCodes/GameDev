#pragma once
#include "/opt/homebrew/opt/raylib/include/raylib.h"

class Tile {
    public:
        Tile(int x, int y, int type, Texture2D texture);
        void Update();

    private:
        int x;
        int y;
        int type;
        Texture2D texture;
        void Draw();

};