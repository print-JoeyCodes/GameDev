#pragma once
#include "/opt/homebrew/opt/raylib/include/raylib.h"

class Stone {
public:
    Stone(Vector2 position);
    void Draw(Texture2D spriteSheet);
    Rectangle GetHitbox() const { return hitbox; }

private:
    Vector2 position;
    Rectangle hitbox;
};