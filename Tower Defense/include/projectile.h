#pragma once
#include "rock.h"

class Projectile {
    public: 
        Projectile(int x, int y, int size, int damage, Color color, Rock* target); // pointer
        void Update();
        void Draw();
        int x;
        int y;
        
    private:
        int size;
        Color color;
        Rock* target;
        int damage;
};