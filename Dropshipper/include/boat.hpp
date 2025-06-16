#pragma once
#include "/opt/homebrew/opt/raylib/include/raylib.h"

class Boat {
    public:
        Boat(int right, int left, int up, int down, Color color);
        void Update();
        Color color;
        Vector2 GetCenter() { return center; }
        void Draw();
        float x;
        float y;
        float width;
        float height;
        float speed;
        float rotationSpeed;
        Vector2 rotatedVertice1;
        Vector2 rotatedVertice2;
        Vector2 rotatedVertice3;
        Rectangle base;
        float rotation;
    
    private:
        int right, left, up, down;
        void HandleInput();
        void Reset();
        int RotationMultiplier();
        float deckHeight;
        float tipHeight;
        double resistance = .008f;
        Vector2 center;
        float centerYoffset;
        Vector2 vertice1;
        Vector2 vertice2;
        Vector2 vertice3;
};