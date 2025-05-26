#pragma once
#include "/opt/homebrew/opt/raylib/include/raylib.h"
#include "rock.h"
#include "projectile.h"
#include <vector>

class Tower {
    public:
        Tower(int x, int y, int size);
        void Draw();
        void CanUpdate(Rock& rock);
        
    private:
        void Attack(Rock& rock); 
        void ChangeColor();
        int updateCycle = 0;
        int updateInterval = 50;
        int x;
        int y;
        int size;
        int damage = 1;
        Color color = BLUE; 
        int colorNum = 1;
        std::vector<Projectile> projectiles;
};