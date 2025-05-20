#pragma once
#include <vector>
#include "/opt/homebrew/opt/raylib/include/raylib.h"

class Grid {
    public:
        Grid();
        void Initialize();
        int grid[20][10];
        void Draw();
        bool IsCellOutside(int row, int column);
        bool IsCellEmpty(int row, int column);
        int ClearFullRows();

    private:
        int numRows;
        int numCols;
        int cellSize;
        std::vector<Color> colors;
        bool IsRowFull(int row);
        void ClearRow(int row);
        void MoveRowDown(int row, int numRows);
};