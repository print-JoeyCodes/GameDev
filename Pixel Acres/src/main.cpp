#include "/opt/homebrew/opt/raylib/include/raylib.h"
#include "farmland.hpp"
#include <vector>

int main () {
    const int screenWidth = 800;
    const int screenHeight = 600;

    const int tilesX = 7;
    const int tilesY = 5;

    int cropCollected = 0;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth,screenHeight,"Pixel Acres");
    SetTargetFPS(60);

    std::vector<Farmland*> farmlandArray;

    

    for(int i = 0; i < tilesX; i++){
        for(int j = 0; j < tilesY; j++){
            farmlandArray.push_back(new Farmland(100 + i * 90, 100 + j * 90));
        };
    }

    while(WindowShouldClose() == false){
        BeginDrawing();

        ClearBackground(WHITE);
        
        for (auto farmland : farmlandArray) {
            farmland->Update();
        }

        if  (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            Vector2 mousePosition = GetMousePosition();
            float mouseX = mousePosition.x;
            float mouseY = mousePosition.y;
            for (auto farmland : farmlandArray){
                cropCollected += (farmland->CheckClick(mouseX, mouseY));
            }
        }

        DrawText(("Crop Collected: " + std::to_string(cropCollected)).c_str(), 10, 10, 20, BLACK);
        
        EndDrawing();
    };

    CloseWindow();
    return 0; 
};