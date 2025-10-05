#pragma once
#include "/opt/homebrew/opt/raylib/include/raylib.h"
#include "tree.hpp"
#include "stone.hpp"
#include "inventory.hpp"
#include <vector>

class Player {
public:
    Player(Vector2 position);
    void Update(std::vector<Tree>& trees, std::vector<Stone>& stones);
    std::vector<int> inventory = {};
    void Draw(int screenWidth, int screenHeight);
    int GetItemType(int index) const { return inventory[index];}
    void RemoveItem(int index) { 
        if(index >= 0 && index < inventory.size()) {
            inventory[index] = 0;
            playerInventory.RemoveItem(index);
        }
    }

private:
    Vector2 position;
    float speed;
    Rectangle hitbox;
    float interactionRadius = 40.0f;
    Vector2 lastSafePosition;
    Inventory  playerInventory;
};
