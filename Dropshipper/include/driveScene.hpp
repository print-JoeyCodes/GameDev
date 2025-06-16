#pragma once
#include "/opt/homebrew/opt/raylib/include/raylib.h"
#include "boat.hpp"
#include "background.hpp"
#include "island.hpp"


class DriveScene {
    public:
        DriveScene(int screenWidth, int screenHeight);
        void Draw();
    
    private:
        Boat boat;
        Island island;
        Island island2;
        Background background;
        Color oceanBlue = {87, 217, 250, 255};
        Color brown = {67, 47, 33, 255};
        Camera2D camera;
};