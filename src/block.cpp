#include "block.h"

/*
    Initialize attribute for block class
    each block's cell has a size of 30
*/
Block::Block(){
    cellSize = 30;
    rotationState = 0;
    colors = GetCellColors();
    rowOffeset = 0;
    colOffeset = 0;
}

/*
    Draw method for Block class it should draw the corressponding triangle for each type of block
    the position of the block draw is depend on the x and y offset
*/
void Block::Draw(int offsetX, int offsetY){
    std::vector<Position> tiles = GetCellPositions();
    for(Position item: tiles){
        DrawRectangle(item.col * cellSize +offsetX, item.row * cellSize + offsetY, cellSize -1 , cellSize -1, colors[id]);
    }
}

/*
    Method to move the initialize position of the block to be draw
*/
void Block::move(int rows, int cols){
    rowOffeset += rows;
    colOffeset += cols;
}

/*
    Method to rotate the rotational state of a block
    how the block is rotated depend on its rotationState value

*/
void Block::Rotate(){
    rotationState++;
    if(rotationState == (int)cells.size()){
        rotationState = 0;
    }
}

/*
    Method to unrotate if the rotation is illegal (outside of grid or overlap with other block)
*/
void Block::UndoRotate(){
    rotationState -- ;
    if(rotationState == -1){
        rotationState = cells.size() - 1;
    }
}

/*
    Method to get new position of the block after offset x and y is set
*/
std::vector<Position> Block::GetCellPositions(){
    std::vector<Position> tiles = cells[rotationState];
    std::vector<Position> movedTiles;
    for( Position item: tiles){
        Position newPos = Position(item.row + rowOffeset, item.col+ colOffeset);
        movedTiles.push_back(newPos);
    }
    return movedTiles;
}