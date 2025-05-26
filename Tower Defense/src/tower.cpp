#include "tower.h"
#include "projectile.h"

Tower::Tower(int x, int y, int size) {
    this->x = x;
    this->y = y;
    this->size = size;
}

void Tower::CanUpdate(Rock& rock) {
    if (updateCycle >= updateInterval) {
        Attack(rock);
        updateCycle = 0;
        ChangeColor();
    } else {
        updateCycle++;
    }

    for (auto it = projectiles.begin(); it != projectiles.end(); ) {
        it->Update();
        if (abs(rock.x - it->x) < 20 && abs(rock.y - it->y) < 20) {
            it = projectiles.erase(it);
        } else {
            ++it;
        }
    }
}

void Tower::Attack(Rock& rock) {
    projectiles.emplace_back(x + (size/2), y + (size/2), 10, damage, RED, &rock);
}

void Tower::Draw() {
    DrawRectangle(x, y, size, size, color);
    for (auto& projectile : projectiles) {
        projectile.Draw();
    }
}

void Tower::ChangeColor() {
    if(colorNum == 1) {
        color = BLUE;
        colorNum = 2;
        return;
    }
    else if (colorNum == 2) {
        color = GREEN;
        colorNum = 1;
        return;
    };
}

