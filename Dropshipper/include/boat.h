#pragma once
#include "/opt/homebrew/opt/raylib/include/raylib.h"

class Boat {
    public:
        Boat(int right, int left, int up, int down, Color color);
        void Update();
        Color color;
    
    private:
        int right, left, up, down;
        void Draw();
        void HandleInput();
        void Reset();
        int RotationMultiplier();
        float x;
        float y;
        float width;
        float deckHeight;
        float tipHeight;
        float height;
        float rotation;
        float speed;
        float rotationSpeed;
        double resistance = .008f;
        float centerYoffset;
        Vector2 center;
        Vector2 vertice1;
        Vector2 vertice2;
        Vector2 vertice3;
        Vector2 rotatedVertice1;
        Vector2 rotatedVertice2;
        Vector2 rotatedVertice3;
};