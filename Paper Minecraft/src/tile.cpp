#include "tile.hpp"

Tile::Tile(int x, int y, int type, Texture2D texture) {
    this->x = x;
    this->y = y;
    this->type = type;
    this->texture = texture;
}

void Tile::Update() {
    Draw();
}

void Tile::Draw() {
    DrawTexture(texture,x,y,WHITE);
}
