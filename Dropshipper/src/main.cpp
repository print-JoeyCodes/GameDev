#include "/opt/homebrew/opt/raylib/include/raylib.h"
#include "boat.h"
#include "background.h"

Color oceanBlue = {87, 217, 250, 255};
Color brown = {67, 47, 33, 255};
 

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    const char *windowTitle = "Dropshipper";
    InitWindow(screenWidth, screenHeight, windowTitle);
    SetTargetFPS(60);
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    Boat boat(KEY_RIGHT, KEY_LEFT, KEY_UP, KEY_DOWN, brown);  
    
    Vector2 boatPosition = boat.GetCenter();
    // Create camera
    Camera2D camera = { 0 };
    camera.target = boatPosition;
    camera.offset = { screenWidth/2.0f, screenHeight/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    Background background(screenWidth);

    while (!WindowShouldClose()) {
        background.Reset(GetScreenWidth());
        boat.Update();
        
        Rectangle deadzone = {GetScreenWidth()/4.0f, GetScreenHeight()/4.0f, GetScreenWidth()/2.0f, GetScreenHeight()/2.0f};

        // Convert deadzone from screen space to world space
        Vector2 dzTopLeft = GetScreenToWorld2D({deadzone.x, deadzone.y}, camera);
        Vector2 dzBottomRight = GetScreenToWorld2D({deadzone.x + deadzone.width, deadzone.y + deadzone.height}, camera);
        Rectangle deadzoneWorld = {dzTopLeft.x, dzTopLeft.y, dzBottomRight.x - dzTopLeft.x, dzBottomRight.y - dzTopLeft.y};

        Vector2 boatCenter = boat.GetCenter();

        // Only move camera if boat is outside deadzone
        if (boatCenter.x < deadzoneWorld.x) {
            camera.target.x -= (deadzoneWorld.x - boatCenter.x);
        } else if (boatCenter.x > deadzoneWorld.x + deadzoneWorld.width) {
            camera.target.x += (boatCenter.x - (deadzoneWorld.x + deadzoneWorld.width));
        }
        if (boatCenter.y < deadzoneWorld.y) {
            camera.target.y -= (deadzoneWorld.y - boatCenter.y);
        } else if (boatCenter.y > deadzoneWorld.y + deadzoneWorld.height) {
            camera.target.y += (boatCenter.y - (deadzoneWorld.y + deadzoneWorld.height));
        }

        BeginDrawing();
        BeginMode2D(camera);
            ClearBackground(oceanBlue);
            background.Draw(camera, GetScreenWidth(), GetScreenHeight());
            boat.Draw();
        EndMode2D();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}