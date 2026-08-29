#include "/opt/homebrew/opt/raylib/include/raylib.h"
#include "farmland.hpp"

Farmland::Farmland(int x, int y) {
    this->x = x;
    this->y = y;
}

void Farmland::Update() {
    Draw();
    if(growing == true) {
        timer++;
        if(timer >= timerLength){
            growing = false;
            timer = 0;
            type = 3;
        }
    }
}

int Farmland::CheckClick(float mouseX, float mouseY) {
    if(mouseX >= x && mouseX <= x + size && mouseY > y && mouseY <= y + size){
        return HandleClick();
    }
    return 0;
}

void Farmland::Draw() {
    DrawRectangle(x, y, size, size, colors[type]);
}

int Farmland::HandleClick() {
    switch (type)
    {
    case 0:
        type = 1;
        return 0;
        break;
    case 1:
        type = 2;
        growing = true;
        timerLength = SetTimer();
        return 0;
        break;
    case 3:
        type = 0;
        return 1;
        break;
    default:
        return 0;
        break;
    }
}

int Farmland::SetTimer() {
    static std::mt19937 gen(std::random_device{}()); // Only seeded once
    std::uniform_int_distribution<> distr(0, 25);
    if(type == 0){
        return ((distr(gen) + 25)*100);
    }
    if(type == 1){
        return ((distr(gen) + 10)*100);
    };
    return 0;
}
