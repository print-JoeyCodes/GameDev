#include "driveScene.hpp"

DriveScene::DriveScene(int screenWidth, int screenHeight)
    : boat(KEY_RIGHT, KEY_LEFT, KEY_UP, KEY_DOWN, {67, 47, 33, 255}),
      island(100, 100, 100, 200, GRAY),
      island2(1000, 1000, 1000, 1000, GRAY),
      background(screenWidth)
{
    Vector2 boatPosition = boat.GetCenter();
    // Create camera
    camera = { 0 };
    camera.target = boatPosition;
    camera.offset = { screenWidth/2.0f, screenHeight/2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
}

void DriveScene::Draw() {
    background.Reset(GetScreenWidth());
        
        Rectangle deadzone = {GetScreenWidth()/6.0f, GetScreenHeight()/6.0f, GetScreenWidth()* 2/3.0f, GetScreenHeight()*2/3.0f};
        
        Vector2 dzTopLeft = GetScreenToWorld2D({deadzone.x, deadzone.y}, camera);
        Vector2 dzBottomRight = GetScreenToWorld2D({deadzone.x + deadzone.width, deadzone.y + deadzone.height}, camera);
        Rectangle deadzoneWorld = {dzTopLeft.x, dzTopLeft.y, dzBottomRight.x - dzTopLeft.x, dzBottomRight.y - dzTopLeft.y};
        
        Vector2 boatCenter = boat.GetCenter();
        
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
                island.Draw();
                island2.Draw();
                boat.Update();
                island.CheckCollisons(boat);
                island2.CheckCollisons(boat);
            EndMode2D();
            
            island2.DrawPointer(boatCenter, camera, GetScreenWidth(), GetScreenHeight());
            island.DrawPointer(boatCenter, camera, GetScreenWidth(), GetScreenHeight());

        EndDrawing();
}