#pragma once
#include "/opt/homebrew/opt/raylib/include/raylib.h"
#include <vector>

class Rock {
    public:
        Rock(int x, int y, int size, int shape, Color color);
        ~Rock();
        void Draw();
        void CanUpdate();
        void SetTarget(int targetX, int targetY);
        void TakeDamage(int damage);
        int x;
        int y;
        
    private:
        void MoveToTarget();
        int updateCycle = 0;
        int updateInterval = 50;
        int size;
        int shape;
        int targetX;
        int targetY;
        int health = 1;
        Color color;
};