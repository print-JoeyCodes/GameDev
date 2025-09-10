#include "/opt/homebrew/opt/raylib/include/raylib.h"
#include "player.hpp"
#include "tree.hpp"
#include "stone.hpp"
#include <vector>

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    Player player({100.0f, 100.0f});
    std::vector<Tree> trees;
    std::vector<Stone> stones;


    InitWindow(screenWidth, screenHeight, "Survival Game");


    Texture2D spriteSheet = LoadTexture("Survival Game Sprites.png");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        BeginDrawing();

        ClearBackground(RAYWHITE);

        if(IsKeyPressed(KEY_T)) {
            for(int i = 0; i < 10; i++) {
                trees.emplace_back(Vector2{static_cast<float>(GetRandomValue(0, screenWidth - 50)), static_cast<float>(GetRandomValue(0, screenHeight - 80))});
            }
        }


        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            stones.emplace_back(GetMousePosition());
        }

        for (auto& tree : trees) {
            tree.Draw(spriteSheet);
        }
        for (auto& stone : stones) {
            stone.Draw(spriteSheet);
        }
        player.Update(trees, stones);

        DrawText(("Wood Collected: " + std::to_string(player.woodCollected)).c_str(), 10, 10, 20, BLACK);
        DrawText(("Stone Collected: " + std::to_string(player.stoneCollected)).c_str(), 10, 30, 20, BLACK);

        EndDrawing();
    }

    UnloadTexture(spriteSheet);
    CloseWindow();
    return 0;
}