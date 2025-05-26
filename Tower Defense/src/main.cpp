#include "/opt/homebrew/opt/raylib/include/raylib.h"
#include "rock.h"
#include "tower.h"

int main() {
    int screenWidth = 800;
    int screenHeight = 450;
    
    InitWindow(screenWidth, screenHeight, "Gold Miner");
    SetTargetFPS(60);

    Rock rock(100, 100, 50, 1, DARKGRAY);
    Tower tower(200, 200, 50);

    while (!WindowShouldClose()) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            int mouseX = GetMouseX();
            int mouseY = GetMouseY();
            rock.SetTarget(mouseX, mouseY);
        };

        BeginDrawing();
        ClearBackground(RAYWHITE);
        rock.CanUpdate();
        tower.Draw();
        tower.CanUpdate(rock);
        rock.Draw();
        EndDrawing();
    };
    CloseWindow();

    return 0;
}