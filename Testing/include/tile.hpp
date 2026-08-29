#pragma once
#include "/opt/homebrew/opt/raylib/include/raylib.h"
#include <vector>

class Tile {
    public:
        Tile(int x, int y, int size, Color color);
        void Update();

    private:
        int x;
        int y;
        int size;
        Color color;

        void Draw();

};