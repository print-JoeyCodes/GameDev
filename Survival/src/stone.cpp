#include "stone.hpp"
#include <vector>

Stone::Stone(Vector2 position) : position(position) {
    hitbox = { position.x, position.y, 70.0f, 80.0f };

}


void Stone::Draw(Texture2D spriteSheet) {
    DrawTexturePro(spriteSheet, {220,0, 330, 300}, {position.x, position.y, hitbox.width, hitbox.height},{0,0}, 0,RAYWHITE);
    DrawRectangleLinesEx(hitbox, 5, RED);
}
