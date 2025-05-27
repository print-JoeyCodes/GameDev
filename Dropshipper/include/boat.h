#pragma once
#include "/opt/homebrew/opt/raylib/include/raylib.h"

class Boat {
    public:
        Boat();
        void Update();
        
    private:
        void HandleInput();
        void Draw();
        void Reset();
        float x;
        float y;
        float width;
        float deckHeight;
        float tipHeight;
        float height;
        int rotation;
        float speed;
        double resistance = .01;
        Vector2 center;
        Vector2 vertice1;
        Vector2 vertice2;
        Vector2 vertice3;
        Vector2 rotatedVertice1;
        Vector2 rotatedVertice2;
        Vector2 rotatedVertice3;
};