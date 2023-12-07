#include "grid.h"
#include <iostream>
#include "colors.h"

/*
    Initialize Grid window for the game with 20 rows, 10 cols and cellsize of 30
*/
Grid::Grid(){
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    Initialize();
    colors = GetCellColors();
}

/*
    setting up the grid to have default value of 0
*/
void Grid::Initialize(){
    for(int i = 0; i < numRows; i++){
        for(int j =0; j < numCols; j++){
            grid[i][j] = 0;
        }
    }
}

/*
    Method for printing the grid
*/
void Grid::Print(){
    for(int i = 0; i < numRows; i++){
        for(int j =0; j < numCols; j++){
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


/*
    Method to draw the grid with appropriate color depend value of the grid 
*/
void Grid::Draw(){
    for(int row = 0; row < numRows; row++){
        for(int col =0; col < numCols; col++){
            int cellValue = grid[row][col];
            DrawRectangle(col * cellSize+11, row * cellSize+11, cellSize-1, cellSize-1, colors[cellValue]);
        }
    }
}


/*
    Method to check whether or not a cell is outside of the grid
*/
bool Grid::IsCellOutside(int row, int col)
{
    if(row >= 0 && row < numRows && col >= 0 && col < numCols){
        return false;
    }
    return true;
}

/*
    Method to check whether or not the current cell of the grid is empty
*/
bool Grid::IsCellEmpty(int row, int col){
    if(grid[row][col] == 0){
        return true;
    }
    return false;
}

/*
    Method to clear a line of the grid when a row is filled
*/
int Grid::ClearFullRows(){
    int completed = 0;
    for(int row = numRows -1; row >= 0; row--){
        if(IsRowFull(row)){
            ClearRow(row);
            completed++;
        }
        else if (completed > 0){
            MoveRowDown(row, completed);
        }
    }
    return completed;
}

/*
    Method to tell whether or not a row is filled
*/
bool Grid::IsRowFull(int row){
    for(int col = 0; col < numCols; col++){
        if(grid[row][col] == 0){
            return false;
        }
    }
    return true;
}

/*
    Method to clear a row
*/
void Grid::ClearRow(int row){
    for(int col = 0; col < numCols; col ++){
        grid[row][col] == 0;
    }
}

/*
    Method to move a row down
*/
void Grid::MoveRowDown(int row, int numRows){
    for(int col = 0; col <numCols; col ++){
        grid[row + numRows][col] = grid[row][col];
        grid[row][col] = 0;
    }
}
