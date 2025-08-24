#include "/opt/homebrew/opt/raylib/include/raylib.h"
#include "player.hpp"
#include "tree.hpp"
#include <vector>

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    Player player({100.0f, 100.0f});
    std::vector<Tree> trees;

    InitWindow(screenWidth, screenHeight, "Survival Game");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        BeginDrawing();

        ClearBackground(RAYWHITE);

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            trees.emplace_back(GetMousePosition());
        }

        for (auto& tree : trees) {
            tree.Draw();
        }
        player.Update(trees);

        DrawText(("Wood Collected: " + std::to_string(player.woodCollected)).c_str(), 10, 10, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}