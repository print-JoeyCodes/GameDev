#include "player.hpp"

Player::Player(Vector2 position) : position(position), speed(200.0f) {
    hitbox = { position.x, position.y, 50.0f, 50.0f };
}

void Player::Update() {
    if (IsKeyDown(KEY_UP)) position.y -= speed * GetFrameTime();
    if (IsKeyDown(KEY_DOWN)) position.y += speed * GetFrameTime();
    if (IsKeyDown(KEY_LEFT)) position.x -= speed * GetFrameTime();
    if (IsKeyDown(KEY_RIGHT)) position.x += speed * GetFrameTime();

    CheckCollisions();

    hitbox.x = position.x;
    hitbox.y = position.y;

    Draw();
}

void Player::Draw() {
    DrawRectangleRec(hitbox, BLUE);
}

void Player::CheckCollisions() {
    if (position.x <= 0) position.x = 0;
    if (position.y <= 0) position.y = 0;
    if (position.x + hitbox.width > GetScreenWidth()) position.x = GetScreenWidth() - hitbox.width;
    if (position.y + hitbox.height > GetScreenHeight()) position.y = GetScreenHeight() - hitbox.height;
}
