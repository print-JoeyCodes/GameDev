#pragma once
#include "/opt/homebrew/opt/raylib/include/raylib.h"

class Tree {
public:
    Tree(Vector2 position);
    void Draw(Texture2D spriteSheet);
    Rectangle GetHitbox() const { return hitbox; }
    int woodAmount = 3;

private:
    Vector2 position;
    Rectangle hitbox;
};