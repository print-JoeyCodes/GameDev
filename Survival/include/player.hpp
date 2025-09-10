#pragma once
#include "/opt/homebrew/opt/raylib/include/raylib.h"
#include "tree.hpp"
#include "stone.hpp"
#include <vector>

class Player {
public:
    Player(Vector2 position);
    void Update(std::vector<Tree>& trees, std::vector<Stone>& stones);
    int woodCollected = 0;
    int stoneCollected = 0;

private:
    void Draw();
    Vector2 position;
    float speed;
    Rectangle hitbox;
    float interactionRadius = 40.0f;
    Vector2 lastSafePosition;
};
