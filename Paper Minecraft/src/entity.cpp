#include "entity.hpp"

Entity::Entity(int x, int y, int type, Texture2D textureLeft, Texture2D textureRight) {
    this->x = x;
    this->y = y;
    this->type = type;
    this->textureLeft = textureLeft;
    this->textureRight = textureRight;
    this->horizon = 331;
}

void Entity::Update() {
    if(y < horizon) {
        velcityY += 1;
    }
    else {
        velcityY = 0;
    }
    Move();
    Draw();
}

void Entity::Draw() {
    if(facingLeft == true) {
        DrawTexture(textureLeft,x,y,WHITE);
    }
    if(facingLeft == false) {
        DrawTexture(textureRight,x,y,WHITE);
    }
}

void Entity::Move() {
    if(IsKeyDown(KEY_LEFT)) {
        facingLeft = true;
        x -= 2.5;
    }
    if(IsKeyDown(KEY_RIGHT)) {
        facingLeft = false;
        x += 2;
    }
    if(IsKeyDown(KEY_UP)) {
        if(jumping == false){
            jumping = true;
            velcityY -= 15;
        };
    }
    y += velcityY;
    if(y>horizon) {
        y = horizon;
    }
    if(y == horizon){
        jumping = false;
    }
}
