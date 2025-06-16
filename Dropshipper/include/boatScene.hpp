#pragma once
#include "/opt/homebrew/opt/raylib/include/raylib.h"
#include "background.hpp"


class BoatScene {
    public:
        BoatScene(int screenWidth, int screenHeight);
        void Draw();
    
    private:
        Background background;
        Camera2D camera;
        Color oceanBlue = {87, 217, 250, 255};
};