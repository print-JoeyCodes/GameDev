#include "/opt/homebrew/opt/raylib/include/raylib.h"
#include "tank.hpp"
#include "bullet.hpp"

Color skyBlue = {126, 209, 241, 255};
Color groundBrown = {92, 58, 19, 255};
Color tankRed = {234, 77, 61, 255};
Color tankBlue = {41, 95, 244, 255};
Color cannonRed = {195, 78, 61, 255};
Color cannonBlue = {47, 81, 205, 255};

int  main() {
    InitWindow(800, 600, "Tanks");
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    SetTargetFPS(60);

    Tank tank1(100, (2 * GetScreenHeight()) / 3 + 10, tankBlue, cannonBlue);
    Tank tank2(700, (2 * GetScreenHeight()) / 3 + 10, tankRed, cannonRed);

    Bullet* bullet = nullptr;

    while (!WindowShouldClose()) {

        if (IsWindowResized()) {
            tank1.MoveTank(100, (2 * GetScreenHeight()) / 3 + 10);
            tank2.MoveTank(GetScreenWidth() - 100, (2 * GetScreenHeight()) / 3 + 10);
        };

        
        BeginDrawing();
        ClearBackground(skyBlue);
        // Launch bullet on space press if not already active
        if (IsKeyPressed(KEY_SPACE) && bullet == nullptr) {
            bullet = new Bullet(tank1);
        }
        if (IsKeyPressed(KEY_R) && bullet != nullptr) {
            delete bullet;
            bullet = nullptr;
        };


        // Update and draw bullet if it exists
        if (bullet != nullptr) {
            bullet->Update();
        };
        tank1.MoveCannon(KEY_A, KEY_D);
        tank1.Draw();
        tank2.MoveCannon(KEY_LEFT, KEY_RIGHT);
        tank2.Draw();
        DrawRectangle(0, (2 * GetScreenHeight()) / 3, GetScreenWidth(), GetScreenHeight() / 3 + 50, groundBrown);
        EndDrawing();
    };

    if (bullet != nullptr) delete bullet;

    CloseWindow();

    return 0;
}