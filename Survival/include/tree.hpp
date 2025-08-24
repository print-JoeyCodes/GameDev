#pragma once
#include "/opt/homebrew/opt/raylib/include/raylib.h"

class Tree {
public:
    Tree(Vector2 position);
    void Draw();
    Rectangle GetHitbox() const { return hitbox; }

private:
    Vector2 position;
    Rectangle hitbox;
};