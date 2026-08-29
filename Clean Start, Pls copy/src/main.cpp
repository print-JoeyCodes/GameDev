#include "/opt/homebrew/opt/raylib/include/raylib.h"

int main () {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth,screenHeight,"Pixel Acres");
    SetTargetFPS(60);

    while(WindowShouldClose() == false){
        BeginDrawing();

        ClearBackground(RAYWHITE);

        EndDrawing();
    }
    CloseWindow();
    return 0; 
}