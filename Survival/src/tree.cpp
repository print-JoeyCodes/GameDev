#include "tree.hpp"
#include <vector>

Tree::Tree(Vector2 position) : position(position) {
    hitbox = { position.x, position.y, 103.5f, 200.5f};

}


void Tree::Draw(Texture2D spriteSheet) {
    DrawTexturePro(spriteSheet, {0,0, 414, 802}, {position.x, position.y, hitbox.width, hitbox.height},{0,0}, 0,RAYWHITE);
    //DrawRectangleLinesEx(hitbox, 5, RED);
}
