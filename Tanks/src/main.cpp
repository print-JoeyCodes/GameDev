#include "/opt/homebrew/opt/raylib/include/raylib.h"
#include "tank.hpp"

Color skyBlue = {126, 209, 241, 255};
Color groundBrown = {92, 58, 19, 255};
Color tankRed = {234, 77, 61, 255};

int  main() {
    InitWindow(800, 600, "Tanks");
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    SetTargetFPS(60);

    Tank tank1(100, (2 * GetScreenHeight()) / 3 + 10, tankRed);
    Tank tank2(700, (2 * GetScreenHeight()) / 3 + 10, tankRed);


    while (!WindowShouldClose()) {

        if (IsWindowResized()) {
            tank1.MoveTank(100, (2 * GetScreenHeight()) / 3 + 10);
            tank2.MoveTank(GetScreenWidth() - 100, (2 * GetScreenHeight()) / 3 + 10);
        };

        BeginDrawing();
        ClearBackground(skyBlue);
        tank1.MoveCannon(KEY_A, KEY_D);
        tank1.Draw();
        tank2.MoveCannon(KEY_LEFT, KEY_RIGHT);
        tank2.Draw();
        DrawRectangle(0, (2 * GetScreenHeight()) / 3, GetScreenWidth(), GetScreenHeight() / 3 + 50, groundBrown);
        EndDrawing();
    };

    CloseWindow();

    return 0;
}