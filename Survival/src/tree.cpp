#include "tree.hpp"
#include <vector>

Tree::Tree(Vector2 position) : position(position) {
    hitbox = { position.x, position.y, 25.0f, 40.0f };

}

void Tree::Draw() {
    DrawRectangleRec(hitbox, BROWN);
    DrawTriangle(
        {hitbox.x + hitbox.width/2, hitbox.y - 25},
        {hitbox.x + hitbox.width/2 - 20, hitbox.y},
        {hitbox.x + hitbox.width/2 + 20, hitbox.y},
        DARKGREEN
    );
}
