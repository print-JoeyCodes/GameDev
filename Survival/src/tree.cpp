#include "tree.hpp"
#include <vector>

Tree::Tree(Vector2 position) : position(position) {
    hitbox = { position.x, position.y, 50.0f, 80.0f };

}


void Tree::Draw(Texture2D spriteSheet) {
    DrawTexturePro(spriteSheet, {0,0, 220, 300}, {position.x, position.y, hitbox.width, hitbox.height},{0,0}, 0,RAYWHITE);
    DrawRectangleLinesEx(hitbox, 5, RED);
}
