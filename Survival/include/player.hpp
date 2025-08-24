#pragma once
#include "/opt/homebrew/opt/raylib/include/raylib.h"
#include "tree.hpp"
#include <vector>

class Player {
public:
    Player(Vector2 position);
    void Update(std::vector<Tree>& trees);
    int woodCollected = 0;

private:
    void Draw();
    void CheckCollisions(Rectangle obstacle);
    Vector2 position;
    float speed;
    Rectangle hitbox;
    bool isColliding = false;
};
