#include "player.hpp"
#include <vector>

Player::Player(Vector2 position) : position(position), speed(200.0f) {
    hitbox = { position.x, position.y, 50.0f, 50.0f };
}

void Player::Update(std::vector<Tree>& trees) {
    if (IsKeyDown(KEY_UP)) position.y -= speed * GetFrameTime();
    if (IsKeyDown(KEY_DOWN)) position.y += speed * GetFrameTime();
    if (IsKeyDown(KEY_LEFT)) position.x -= speed * GetFrameTime();
    if (IsKeyDown(KEY_RIGHT)) position.x += speed * GetFrameTime();

    CheckCollisions(hitbox);

    hitbox.x = position.x;
    hitbox.y = position.y;

    for (auto it = trees.begin(); it != trees.end(); ++it) {
        CheckCollisions(it->GetHitbox());
        if (isColliding && IsKeyPressed(KEY_E)) {
            trees.erase(it);
            woodCollected += 1;
            break;
        }
    }

    Draw();
}

void Player::Draw() {
    DrawRectangleRec(hitbox, BLUE);
}

void Player::CheckCollisions(Rectangle obstacle) {
    if (position.x <= 0) position.x = 0;
    if (position.y <= 0) position.y = 0;
    if (position.x + hitbox.width > GetScreenWidth()) position.x = GetScreenWidth() - hitbox.width;
    if (position.y + hitbox.height > GetScreenHeight()) position.y = GetScreenHeight() - hitbox.height;

    if (CheckCollisionRecs(hitbox, obstacle)) {
        isColliding = true;
    }
    else {
        isColliding = false;
    }
}
