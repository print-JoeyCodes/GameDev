#include "boatScene.hpp"

BoatScene::BoatScene(int screenWidth, int screenHeight)
    : background(screenWidth)
{
    camera = { 0 };
    camera.target = {0, 0};
    camera.offset = { screenWidth/2.0f, screenHeight/2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    
}

void BoatScene::Draw() {
    background.Reset(GetScreenWidth());

    BeginDrawing();
        ClearBackground(oceanBlue);
        background.Draw(camera, GetScreenWidth(), GetScreenHeight());
        DrawText("Loading",(GetScreenWidth()/2) - 200,(GetScreenHeight()/2)-200,100,BLACK);
    EndDrawing();
}