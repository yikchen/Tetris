#include "block.h"
#include "position.h"

/*
    One variation of the block L shape with initial spawn position of 0,3 offset
*/
class LBlock :public Block{
    public:
        LBlock(){
            id = 1;
            cells[0] = {Position(0,2), Position(1,0), Position(1,1), Position(1,2)};
            cells[1] = {Position(0,1), Position(1,1), Position(2,1), Position(2,2)};
            cells[2] = {Position(1,0), Position(1,1), Position(1,2), Position(2,0)};
            cells[3] = {Position(0,0), Position(0,1), Position(1,1), Position(2,1)};
            move(0,3);
        }
};

/*
    One variation of the block J shape with initial spawn position of 0,3 offset
*/
class JBlock :public Block{
    public:
        JBlock(){
            id = 2;
            cells[0] = {Position(0,0), Position(1,0), Position(1,1), Position(1,2)};
            cells[1] = {Position(0,1), Position(0,2), Position(1,1), Position(2,1)};
            cells[2] = {Position(1,0), Position(1,1), Position(1,2), Position(2,2)};
            cells[3] = {Position(0,1), Position(1,1), Position(2,0), Position(2,1)};
            move(0,3);
        }
};

/*
    One variation of the block I shape with initial spawn position of -1,3 offset
*/
class IBlock :public Block{
    public:
        IBlock(){
            id = 3;
            cells[0] = {Position(1,0), Position(1,1), Position(1,2), Position(1,3)};
            cells[1] = {Position(0,2), Position(1,2), Position(2,2), Position(3,2)};
            cells[2] = {Position(2,0), Position(2,1), Position(2,2), Position(2,3)};
            cells[3] = {Position(0,1), Position(1,1), Position(2,1), Position(3,1)};
            move(-1,3);
        }
};

/*
    One variation of the block O shape with initial spawn position of 0,4 offset
*/
class OBlock :public Block{
    public:
        OBlock(){
            id = 4;
            cells[0] = {Position(0,0), Position(0,1), Position(1,0), Position(1,1)};
            cells[1] = {Position(0,0), Position(0,1), Position(1,0), Position(1,1)};
            cells[2] = {Position(0,0), Position(0,1), Position(1,0), Position(1,1)};
            cells[3] = {Position(0,0), Position(0,1), Position(1,0), Position(1,1)};
            move(0,4);
        }
};

/*
    One variation of the block S shape with initial spawn position of 0,3 offset
*/
class SBlock :public Block{
    public:
        SBlock(){
            id = 5;
            cells[0] = {Position(0,1), Position(0,2), Position(1,0), Position(1,1)};
            cells[1] = {Position(0,1), Position(1,1), Position(1,2), Position(2,2)};
            cells[2] = {Position(1,1), Position(1,2), Position(2,0), Position(2,1)};
            cells[3] = {Position(0,0), Position(1,0), Position(1,1), Position(2,1)};
            move(0,3);
        }
};

/*
    One variation of the block T shape with initial spawn position of 0,3 offset
*/
class TBlock :public Block{
    public:
        TBlock(){
            id = 6; 
            cells[0] =  {Position(0,1), Position(1,0), Position(1,1), Position(1,2)};
            cells[1] =  {Position(0,1), Position(1,1), Position(1,2), Position(2,1)};
            cells[2] =  {Position(1,0), Position(1,1), Position(1,2), Position(2,1)};
            cells[3] =  {Position(0,1), Position(1,0), Position(1,1), Position(2,1)};
            move(0,3);
        }
};

/*
    One variation of the block Z shape with initial spawn position of 0,3 offset
*/
class ZBlock :public Block{
    public:
        ZBlock(){
            id = 7;
            cells[0] = {Position(0,0), Position(0,1), Position(1,1), Position(1,2)};
            cells[1] = {Position(0,2), Position(1,1), Position(1,2), Position(2,1)};
            cells[2] = {Position(1,0), Position(1,1), Position(2,1), Position(2,2)};
            cells[3] = {Position(0,1), Position(1,0), Position(1,1), Position(2,0)};
            move(0,3);
        }
};