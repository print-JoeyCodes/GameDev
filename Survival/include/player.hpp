#pragma once
#include "/opt/homebrew/opt/raylib/include/raylib.h"

class Player {
public:
    Player(Vector2 position);
    void Update();

private:
    void Draw();
    void CheckCollisions();
    Vector2 position;
    float speed;
    Rectangle hitbox;
};
