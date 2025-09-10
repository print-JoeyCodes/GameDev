#include "player.hpp"
#include <vector>

Player::Player(Vector2 position) : position(position), speed(200.0f) {
    hitbox = { position.x, position.y, 50.0f, 50.0f };
}

void Player::Update(std::vector<Tree>& trees, std::vector<Stone>& stones) {
    Vector2 proposedPosition = position;

    if (IsKeyDown(KEY_W)||IsKeyDown(KEY_UP)) proposedPosition.y -= speed * GetFrameTime();
    if (IsKeyDown(KEY_S)||IsKeyDown(KEY_DOWN)) proposedPosition.y += speed * GetFrameTime();
    if (IsKeyDown(KEY_A)||IsKeyDown(KEY_LEFT)) proposedPosition.x -= speed * GetFrameTime();
    if (IsKeyDown(KEY_D)||IsKeyDown(KEY_RIGHT)) proposedPosition.x += speed * GetFrameTime();

    Rectangle proposedHitbox = hitbox;
    proposedHitbox.x = proposedPosition.x;
    proposedHitbox.y = proposedPosition.y;

    bool collision = false;
    for (auto& tree : trees) {
        if (CheckCollisionRecs(proposedHitbox, tree.GetHitbox())) {
            collision = true;
            break;
        }
    }

     for (auto& stone : stones) {
        if (CheckCollisionRecs(proposedHitbox, stone.GetHitbox())) {
            collision = true;
            break;
        }
    }



    if (!collision) {
        lastSafePosition = position;
        position = proposedPosition;
    }

    for (auto it = trees.begin(); it != trees.end(); ++it) {
        if (CheckCollisionCircleRec(
                {position.x + hitbox.width / 2, position.y + hitbox.height / 2}, // center of player
                interactionRadius,
                it->GetHitbox())
            && IsKeyPressed(KEY_E)) {
            trees.erase(it);
            woodCollected += 1;
            break;
        }
    }

    for (auto it = stones.begin(); it != stones.end(); ++it) {
        if (CheckCollisionCircleRec(
                {position.x + hitbox.width / 2, position.y + hitbox.height / 2}, // center of player
                interactionRadius,
                it->GetHitbox())
            && IsKeyPressed(KEY_E)) {
            stones.erase(it);
            stoneCollected += 1;
            break;
        }
    }

    if (position.x <= 0) position.x = 0;
    if (position.y <= 0) position.y = 0;
    if (position.x + hitbox.width > GetScreenWidth()) position.x = GetScreenWidth() - hitbox.width;
    if (position.y + hitbox.height > GetScreenHeight()) position.y = GetScreenHeight() - hitbox.height;
    
    hitbox.x = position.x;
    hitbox.y = position.y;
    
    Draw();
}

void Player::Draw() {
    DrawCircle(position.x + hitbox.width / 2, position.y + hitbox.height / 2, interactionRadius, Fade(GREEN, 0.4f));
    DrawRectangleRec(hitbox, BLUE);
}
