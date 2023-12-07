#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class Block{
    public:
        Block();
        void Draw(int offsetX, int offsetY);
        void move(int rows, int cols);
        void Rotate();
        void UndoRotate();
        std::vector<Position> GetCellPositions();
        int id;
        std::map<int, std::vector<Position>> cells;

    private:
        int cellSize;
        int rotationState;
        int rowOffeset;
        int colOffeset;
        std::vector<Color> colors;
};