#include "inventory.hpp"

Inventory::Inventory(int maxSize) : maxSize(maxSize) {
    for(int i = 0; i < maxSize; i++){
        items.push_back(0);
    };
}

bool Inventory::AddItem(int item){
    for(size_t i = 0; i < items.size(); i++){
        if(items[i] == 0){
            items[i] = item;
            return true;
        }
    }
    return false;
}

void Inventory::RemoveItem(int index){
    if(index >= 0 && index < items.size()) {
        items[index] = 0;
    }
}

void Inventory::Draw(int screenWidth, int screenHeight) {
    int xOffset = screenWidth;
    int yOffset = screenHeight;
    for(size_t i = 0; i < items.size(); i++){
        if(items[i] == 0){
            DrawRectangle(xOffset + (i * 95), yOffset, 75, 75, LIGHTGRAY);
        }
        if(items[i] == 1){
            DrawRectangle(xOffset + (i * 95), yOffset, 75, 75, BROWN);
        }
        if(items[i] == 2){
            DrawRectangle(xOffset + (i * 95), yOffset, 75, 75, DARKGRAY);
        }
    }
}