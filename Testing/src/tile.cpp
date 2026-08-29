#include "tile.hpp"

Tile::Tile(int x, int y, int size, Color color) {
    this->x = x;
    this->y = y;
    this->size = size;
    this->color = color;
}

void Tile::Update() {
    Draw();
}

void Tile::Draw() {
    DrawLine(x - 2 * size, y, x, y - size, color);
    DrawLine(x, y - size, x + 2 * size, y, color);
    DrawLine(x + 2 * size, y, x, y + size, color);
    DrawLine(x, y + size, x - 2 * size, y, color);
}
