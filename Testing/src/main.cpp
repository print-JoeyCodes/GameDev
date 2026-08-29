#include "/opt/homebrew/opt/raylib/include/raylib.h"
#include "tile.hpp"
#include <vector>




int main () {
    const int screenWidth = 800;
    const int screenHeight = 600;

    int orginX = 400;
    int orginY = 300;

    int gridSize = 4;
    int tileSize = 40;

    InitWindow(screenWidth,screenHeight,"Pixel Acres");
    SetTargetFPS(60);


    std::vector<Tile*> tileArray;

    std::vector<Color> colors = {BLACK,RED,GREEN,BLUE,PURPLE,ORANGE,BROWN};
    int colorNum = 0;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            if(i%2 == 0){
                tileArray.push_back(new Tile(orginX + tileSize * 4 * i, orginY + tileSize * 2 * j,tileSize,colors[colorNum]));
            }
            else{
                tileArray.push_back(new Tile(orginX + tileSize * i + tileSize * 1, orginY + tileSize * j,tileSize,colors[colorNum]));
            }

            colorNum++;
        };
    };


    while(WindowShouldClose() == false){
        BeginDrawing();
        ClearBackground(RAYWHITE);

       for (auto tile : tileArray) {
            tile->Update();
        }

        EndDrawing();
    }
    CloseWindow();
    return 0; 
}