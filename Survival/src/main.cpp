#include "/opt/homebrew/opt/raylib/include/raylib.h"
#include "player.hpp"


int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    Player player({100.0f, 100.0f});
    
    InitWindow(screenWidth, screenHeight, "Survival Game");
    SetTargetFPS(60);
  
    while (!WindowShouldClose()) {

        BeginDrawing();

        ClearBackground(RAYWHITE);

        player.Update();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}