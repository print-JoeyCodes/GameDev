#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game {
    public:
        Game();
        ~Game();
        void Draw();
        void HandleInPut();
        void MoveBlockDown();
        bool gameOver;
        int score;
        Music music;
        
    private:
        Grid grid;
        void MoveBlockLeft();
        void MoveBlockRight();
        Block GetRandomBlock();
        std::vector<Block> GetAllBlocks();
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;
        bool IsBlockOutside();
        bool BlockFits();
        void RotateBlock();
        void LockBlock();
        void Reset();
        void UpdateScore(int linesCleared, int moveDownPoints);
        Sound rotateSound;
        Sound clearSound;
};