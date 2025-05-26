#include "rock.h"

Rock::Rock(int x, int y, int size, int shape, Color color) {
    this->x = x;
    this->y = y;
    this->size = size;
    this->shape = shape;
    this->color = color;
    this->targetX = x;
    this->targetY = y;
}

void Rock::Draw() {
    DrawRectangle(x, y, size, size, color);
}

void Rock::CanUpdate() {
    if (updateCycle >= updateInterval) {
        MoveToTarget();
        updateCycle = 0;
    } else {
        updateCycle++;
    }
}

void Rock::SetTarget(int targetX, int targetY) {
    this->targetX = targetX;
    this->targetY = targetY;
}

void Rock::TakeDamage(int damage) {
    health -= damage;
    if (health <= 0) {
        health = 0;
        color = GOLD;
        return;
    };
}

void Rock::MoveToTarget() {
    if (targetX - x < 20 && targetX - x > -20 ) {
        x = targetX;
    };
    if (targetY - y < 20 && targetY - y > -20) {
        y = targetY;
    };
    if ( x < targetX) {
        x += 20;
    }
    else if (x > targetX) {
        x -= 20;
    };
    if ( y < targetY) {
        y += 20;
    } 
    else if (y > targetY) {
        y -= 20;
    };
}

Rock::~Rock() {
    // Destructor logic if needed
}

