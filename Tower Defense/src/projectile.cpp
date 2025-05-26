#include "projectile.h"
#include "/opt/homebrew/opt/raylib/include/raylib.h"

Projectile::Projectile(int x, int y, int size, int damage, Color color, Rock* target)
    : x(x), y(y), size(size), damage(damage), color(color), target(target) {
}

void Projectile::Draw() {
    DrawCircle(x, y, size, color);
}

void Projectile::Update() {
    if (!target) return;
    if (target->x - x < 20 && target->x - x > -20 && 
        target->y - y < 20 && target->y - y > -20) {
        target->TakeDamage(damage);
        return;
    }
    if (target->x > x) {
        x += 1;
    } else if (target->x < x) {
        x -= 1;
    }
    if (target->y > y) {
        y += 1;
    } else if (target->y < y) {
        y -= 1;
    }
}
