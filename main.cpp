#include <iostream>
#include "/opt/homebrew/opt/raylib/include/raylib.h"

using namespace std;

class Ball{
    public:
        float x, y;
        int speedX, speedY;
        int radius;

        void Draw(){
            DrawCircle(x, y, radius, WHITE);
        }

        void Update(){
            x += speedX;
            y += speedY;
        }
};

Ball ball;
 
int main () {
    cout << "Starting the game" << endl;
    const int screenWidth = 1280;
    const int screenHeight = 800;

    InitWindow(screenWidth,screenHeight,"My Pong Game");
    SetTargetFPS(60);

    ball.radius = 20;
    ball.x = screenWidth/2;
    ball.y = screenHeight/2;
    ball.speedX = 7;
    ball.speedY = 7;

    while(WindowShouldClose() == false){
        BeginDrawing();

        ClearBackground(BLACK);
        DrawLine(screenWidth/2,0,screenWidth/2,screenHeight,WHITE);
        ball.Update();
        ball.Draw();
        DrawRectangle(10,screenHeight/2 - 60,25,125,WHITE);
        DrawRectangle(screenWidth - 35,screenHeight/2 - 60,25,125,WHITE);

        EndDrawing();
    }
    CloseWindow();
    return 0; 
}