#include "stone.hpp"
#include <vector>

Stone::Stone(Vector2 position) : position(position) {
    hitbox = { position.x, position.y, 137.5f, 99.75f };

}


void Stone::Draw(Texture2D spriteSheet) {
    DrawTexturePro(spriteSheet, {414,0, 550, 399}, {position.x, position.y, hitbox.width, hitbox.height},{0,0}, 0,RAYWHITE);
    //DrawRectangleLinesEx(hitbox, 5, RED);
}
