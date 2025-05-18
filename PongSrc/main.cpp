#include <iostream>
#include "/opt/homebrew/opt/raylib/include/raylib.h"

using namespace std;

int playerScore = 0;
int cpuScore = 0;

Color Green = Color{38, 185, 154, 255};
Color Dark_Green = Color{20, 160, 133, 255};
Color Light_Green = Color{129, 204, 184, 255};
Color Yellow = Color{243, 213, 91, 255};


class Ball{
    public:
        float x, y;
        int speedX, speedY;
        int radius;

        void Draw(){
            DrawCircle(x, y, radius, Yellow);
        }

        void Update(){

            x += speedX;
            y += speedY;


            if(y + radius >= GetScreenHeight() || y - radius <= 0){
                speedY *= -1;
            }

            if(x + radius >= GetScreenWidth()){
                cpuScore++; 
                ResetBall();
            }
            else if(x - radius <= 0){
                playerScore++;
                ResetBall();
            }
        }

        void ResetBall(){
            x = GetScreenWidth()/2;
            y = GetScreenHeight()/2;

            int speedChoices[2] = {-1,1};
            speedX *= speedChoices[GetRandomValue(0,1)];
            speedY *= speedChoices[GetRandomValue(0,1)];
        }
};

class Paddle{
    protected:
        void LimitMovement(){
            if(y <= 0){
                y = 0;
            }
            else if(y + height >= GetScreenHeight()){
                y = GetScreenHeight() - height;
            }
        };

    public:
        float x, y;
        float width, height;
        int speed;

        void Draw(){
            DrawRectangleRounded(Rectangle{x, y, width, height}, 0.8, 0, WHITE);
        }

        void Update(int AI){
            if(AI == 0){
                if(IsKeyDown(KEY_UP)){
                    y -= speed;
                }
                else if(IsKeyDown(KEY_DOWN)){
                    y += speed;
                }
            }
            else if(AI == 1){
                if(IsKeyDown(KEY_W)){
                    y -= speed;
                }
                else if(IsKeyDown(KEY_S)){
                    y += speed;
                }
            }

            LimitMovement();
        }
};

class CpuPaddle: public Paddle{
    public:
        void Update(float ballY){
            if(y + height/2 > ballY){
                y -= speed;
            }
            else if(y + height/2 <= ballY){
                y += speed;
            }
            LimitMovement();
        }
};

Ball ball;
Paddle player;
Paddle cpu;
 
int main () {
    const int screenWidth = 1280;
    const int screenHeight = 800;

    InitWindow(screenWidth,screenHeight,"My Pong Game");
    SetTargetFPS(60);
    
    ball.radius = 20;
    ball.x = screenWidth/2;
    ball.y = screenHeight/2;
    ball.speedX = 7;
    ball.speedY = 7;

    player.width = 25;
    player.height = 125;
    player.x = 10;
    player.y = screenHeight/2;
    player.speed = 6;

    cpu.width = 25;
    cpu.height = 120;
    cpu.x = screenWidth - player.width - 10;
    cpu.y =screenHeight/2 - player.height/2;
    cpu.speed = 6;

    while(WindowShouldClose() == false){
        BeginDrawing();

        ClearBackground(Dark_Green);
        DrawRectangle(screenWidth/2,0, screenWidth/2, screenHeight, Green);
        DrawCircle(screenWidth/2, screenHeight/2, 150, Light_Green);
        DrawLine(screenWidth/2,0,screenWidth/2,screenHeight,WHITE);
        ball.Update();
        player.Update(1);
        cpu.Update(0);

        if(CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{player.x, player.y, player.width, player.height})){
            ball.speedX *= -1;
        }

        if(CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{cpu.x, cpu.y, cpu.width, cpu.height})){
            ball.speedX *= -1;
        };

        ball.Draw();
        player.Draw();
        cpu.Draw();
        DrawText(TextFormat("%i",cpuScore),screenWidth/4 - 20, 20, 80, WHITE);
        DrawText(TextFormat("%i",playerScore), 3 * screenWidth/4 - 20, 20, 80, WHITE);

        EndDrawing();
    }
    CloseWindow();
    return 0; 
}