#pragma once
#include "/opt/homebrew/opt/raylib/include/raylib.h"


class Background {
    public:
        Background(int width);
        void Draw(const Camera2D& camera, float screenWidth, float screenHeight);
        void Reset(int width);

    private:
        int stripeHeight = 100;
        Color oceanBlue = {87, 217, 250, 255};
        Color lightBlue = {105, 221, 250, 255};
        int width;
};