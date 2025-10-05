#pragma once
#include "/opt/homebrew/opt/raylib/include/raylib.h"
#include <vector>

class Inventory {
    public:
        Inventory(int maxSize);
        bool AddItem(int item);
        void RemoveItem(int index);
        void Draw(int screenWidth, int screenHeight);
        int GetItemType(int index) const { return items[index]; }
        
    private:
        std::vector<int> items;
        int maxSize;
        int yOffset;
        int xOffset;
};