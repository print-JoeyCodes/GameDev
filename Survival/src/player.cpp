#include "player.hpp"
#include "inventory.hpp"
#include <vector>

Player::Player(Vector2 position)
    : position(position), speed(200.0f), playerInventory(5) {
    hitbox = { position.x, position.y, 50.0f, 50.0f };
}

void Player::Update(std::vector<Tree>& trees, std::vector<Stone>& stones) {
    Vector2 input = {0, 0};
    if (IsKeyDown(KEY_W)||IsKeyDown(KEY_UP)) input.y -= 1;
    if (IsKeyDown(KEY_S)||IsKeyDown(KEY_DOWN)) input.y += 1;
    if (IsKeyDown(KEY_A)||IsKeyDown(KEY_LEFT)) input.x -= 1;
    if (IsKeyDown(KEY_D)||IsKeyDown(KEY_RIGHT)) input.x += 1;

    if (input.x != 0 || input.y != 0) {
        float length = sqrtf(input.x * input.x + input.y * input.y);
        input.x /= length;
        input.y /= length;
    }

    Vector2 proposedPosition = position;
    proposedPosition.x += input.x * speed * GetFrameTime();
    proposedPosition.y += input.y * speed * GetFrameTime();

    if (IsKeyPressed(KEY_Q)) {
        if(!inventory.empty()) {
            inventory.pop_back();
            playerInventory.RemoveItem(inventory.size());
        }
    }

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
    if(inventory.size() < 5) {
        for (auto it = trees.begin(); it != trees.end(); ++it) {
            if (CheckCollisionCircleRec(
                    {position.x + hitbox.width / 2, position.y + hitbox.height / 2}, // center of player
                    interactionRadius,
                    it->GetHitbox())
                && IsKeyPressed(KEY_E)) {
                    if(it->woodAmount > 0) {
                        it->woodAmount -= 1;
                        inventory.push_back(1);
                        playerInventory.AddItem(1);
                    }
                    if(it->woodAmount <= 0){
                        trees.erase(it);
                    }
                    break;
                }
        }

        for (auto it = stones.begin(); it != stones.end(); ++it) {
            if (CheckCollisionCircleRec(
                    {position.x + hitbox.width / 2, position.y + hitbox.height / 2}, // center of player
                    interactionRadius,
                    it->GetHitbox())
                && IsKeyPressed(KEY_E)) {
                if(it->stoneAmount > 0) {
                        it->stoneAmount -= 1;
                        inventory.push_back(2);
                        playerInventory.AddItem(2);
                    }
                    if(it->stoneAmount <= 0){
                        stones.erase(it);
                    }
                    break;
                break;
            }
        }
    };

    if (position.x <= 0) position.x = 0;
    if (position.y <= 0) position.y = 0;
    if (position.x + hitbox.width > GetScreenWidth()) position.x = GetScreenWidth() - hitbox.width;
    if (position.y + hitbox.height > GetScreenHeight()) position.y = GetScreenHeight() - hitbox.height;
    
    hitbox.x = position.x;
    hitbox.y = position.y;
}

void Player::Draw(int screenWidth,int screenHeight) {
    //DrawCircle(position.x + hitbox.width / 2, position.y + hitbox.height / 2, interactionRadius, Fade(GREEN, 0.4f));
    DrawRectangleRec(hitbox, BLUE);
    playerInventory.Draw(screenWidth,screenHeight);
}
