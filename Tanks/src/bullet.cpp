#include "bullet.hpp"
#include "cmath"
#include "tank.hpp"

Bullet::Bullet(const Tank& origin) : origin(origin) {
    this->x = origin.GetX();
    this->y = origin.GetY();
    this->speed = 8.0f;
    this->radius = 5.0f;
    this->color = origin.GetCannonColor();
    this->angle = origin.GetCannonRotation() * (M_PI / 180.0f); // Convert degrees to radians
}

void Bullet::Update() {
    x++;
    y = x * tan(angle) - (9.8 * x * x) / (2 * speed * speed * cos(angle));
    // x += speed * cos(angle);
    // y += speed * sin(angle);
    Draw();
}

void Bullet::Draw() {
    DrawCircle(x, y, radius, color);
}
