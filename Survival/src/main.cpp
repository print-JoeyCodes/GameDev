#include "/opt/homebrew/opt/raylib/include/raylib.h"
#include "player.hpp"
#include "tree.hpp"
#include "stone.hpp"
#include "inventory.hpp"
#include <vector>

int main() {
    int screenWidth = 800;
    int screenHeight = 600;
    bool craftingOpen = false;

    Player player({100.0f, 100.0f});
    std::vector<Tree> trees;
    std::vector<Stone> stones;
    Color GRASS_GREEN = {148,196,104,255};
    Inventory craftingInventory(3);

   
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "Survival Game");



    Texture2D spriteSheet = LoadTexture("Tree-Stone-sprites.png");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        BeginDrawing();

        ClearBackground(GRASS_GREEN);
        if(IsKeyPressed(KEY_C)) {
                craftingOpen ? craftingOpen = false : craftingOpen = true;
            }
        if(!craftingOpen) {   
            if(IsKeyPressed(KEY_T)) {
                for(int i = 0; i < 5; i++) {
                    trees.emplace_back(Vector2{static_cast<float>(GetRandomValue(0, GetScreenWidth() - 50)), static_cast<float>(GetRandomValue(0, GetScreenHeight() - 80))});
                }
                for(int i = 0; i < 3; i++) {
                    stones.emplace_back(Vector2{static_cast<float>(GetRandomValue(0,  GetScreenWidth() - 50)), static_cast<float>(GetRandomValue(0, GetScreenHeight() - 80))});
                }
            }
            
            player.Update(trees, stones);
        }
        
        for (auto& stone : stones) {
            stone.Draw(spriteSheet);
        }
        for (auto& tree : trees) {
            tree.Draw(spriteSheet);
        }

        player.Draw(GetScreenWidth()/2-225,GetScreenHeight()-100);

        if(craftingOpen) {
            DrawRectangle(100, 50, GetScreenWidth() - 200, GetScreenHeight() - 250, GRAY);
            DrawText("Crafting Menu (Press C to close)", 120, 120, 20, DARKGRAY);
            craftingInventory.Draw(120,180);
            if(IsKeyPressed(KEY_ONE)) {
                if(player.GetItemType(0) != 0) {
                    craftingInventory.AddItem(player.GetItemType(0));
                    player.RemoveItem(0);
                }
            }
            if(IsKeyPressed(KEY_TWO)) {
                if(player.GetItemType(1) != 0) {
                    craftingInventory.AddItem(player.GetItemType(1));
                    player.RemoveItem(1);
                }
            }
            if(IsKeyPressed(KEY_THREE)) {
                if(player.GetItemType(2) != 0) {
                    craftingInventory.AddItem(player.GetItemType(2));
                    player.RemoveItem(2);
                }
            }
            if(IsKeyPressed(KEY_FOUR)) {
                if(player.GetItemType(3) != 0) {
                    craftingInventory.AddItem(player.GetItemType(3));
                    player.RemoveItem(3);
                }
            }
            if(IsKeyPressed(KEY_FIVE)) {
                if(player.GetItemType(4) != 0) {
                    craftingInventory.AddItem(player.GetItemType(4));
                    player.RemoveItem(4);
                }
            }
        }


        EndDrawing();
    }

    UnloadTexture(spriteSheet);
    CloseWindow();
    return 0;
}