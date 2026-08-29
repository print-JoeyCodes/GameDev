#pragma once
#include <vector>
#include <random>

class Farmland {
    public:
        Farmland(int x, int y);
        void Update();
        int CheckClick(float mouseX, float mouseY);

        
    private:
        int x;
        int y;
        int size = 75;
        int type = 0;
        bool growing = false;
        int timer = 0;
        int timerLength = 0;
        std::vector<Color> colors = {{176,131,82,255},{140,79,26,255},{123,173,116,255},{237,183,72,255}};

        void Draw();
        int HandleClick();
        int SetTimer();

};
