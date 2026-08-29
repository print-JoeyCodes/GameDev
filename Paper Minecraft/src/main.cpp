#include "/opt/homebrew/opt/raylib/include/raylib.h"
#include "tile.hpp"
#include "entity.hpp"
#include <vector>

int main () {
    const int screenWidth = 855;
    const int screenHeight = 600;

    const int tilesWide = screenWidth/95;

    InitWindow(screenWidth,screenHeight,"Paper Minecraft");
    SetTargetFPS(60);

    Texture2D grass = LoadTexture("src/PM_Grass.png");
    Texture2D dirt = LoadTexture("src/PM_Dirt.png");
    Texture2D snifferRight = LoadTexture("src/PM_SnifferRight.png");
    Texture2D snifferLeft = LoadTexture("src/PM_SnifferLeft.png");

    std::vector<Tile> tilesArray;


    for(int i = 0; i < tilesWide; i++){
        tilesArray.push_back(Tile(i * 95,418,0,grass));
    };

    for(int i = 0; i < tilesWide; i++){
        tilesArray.push_back(Tile(i * 95,513,1,dirt));
    };
    
    Entity player(200,200,0,snifferLeft,snifferRight);

    while(WindowShouldClose() == false){
        BeginDrawing();

        ClearBackground({239,253,254,255});

        for (auto tile : tilesArray) {
            tile.Update();
        }

        player.Update();

        EndDrawing();
    }

    UnloadTexture(grass);
    UnloadTexture(dirt);
    UnloadTexture(snifferLeft);
    UnloadTexture(snifferRight);

    CloseWindow();
    return 0; 
}