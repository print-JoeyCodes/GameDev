#include "/opt/homebrew/opt/raylib/include/raylib.h"
#include "driveScene.hpp"
#include "boatScene.hpp"


 

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    const char *windowTitle = "Dropshipper";
    int scene = 0;

    InitWindow(screenWidth, screenHeight, windowTitle);
    SetTargetFPS(60);
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    DriveScene driveScene(GetScreenWidth(),GetScreenHeight());
    BoatScene boatScene(GetScreenWidth(),GetScreenHeight());

    while (!WindowShouldClose()) {
        if(scene == 0){
            boatScene.Draw();
        }
        else if (scene == 1) {
            driveScene.Draw();
        };
        if(IsKeyPressed(KEY_S)) {
            scene = 0;
        }
        else if(IsKeyPressed(KEY_A)) {
            scene = 1;
        }

    };

    CloseWindow();

    return 0;
}