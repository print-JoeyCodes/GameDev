#pragma once
#include "/opt/homebrew/opt/raylib/include/raylib.h"
#include "boat.hpp"

class Island {
    public:
        Island(float x, float y, float width, float height, Color color);
        void Draw();
        void DrawPointer(Vector2 boatPosition, Camera2D camera, float screenWidth, float screenHeight);
        void CheckCollisons(Boat& boat);
        float x;
        float y;
        float width;
        float height;
        Rectangle bounds;
        float rotation = 0;

    private:
        Color color;
        Vector2 islandPosition;
};