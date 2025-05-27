#include "/opt/homebrew/opt/raylib/include/raylib.h"
#include "boat.h"

Color oceanBlue = {87, 217, 250, 255};

 

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    const char *windowTitle = "Dropshipper";
    InitWindow(screenWidth, screenHeight, windowTitle);
    SetTargetFPS(60);
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    Boat boat;
    
    while (!WindowShouldClose()) {
        BeginDrawing();
        boat.Update();
    
        ClearBackground(oceanBlue);


        EndDrawing();
    }

    CloseWindow();

    return 0;
}