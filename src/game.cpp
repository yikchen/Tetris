#include "game.h"
#include <stdlib.h>

/*
    Constructor of game class setting up neccessary atrribute for the game to run 
    Score to be set at zero
*/
Game::Game(){
    grid = Grid(); // Grid for the game board
    blocks = GetAllBlocks(); // getting a list of blocks to choose from 
    currentBlock = GetRandomBlock(); // getting a new block 
    nextBlock = GetRandomBlock(); // getting nextBlock
    gameOver = false; // state of game being unfinished
    score = 0; 
    InitAudioDevice(); //init audio for the game
    music = LoadMusicStream("Sounds/music.mp3"); // load bg music
    PlayMusicStream(music); // play bg music
    rotateSound = LoadSound("Sounds/rotate.mp3"); // load sounds effect for rotated
    clearSound = LoadSound("Sounds/clear.mp3"); //load sounds effect for clearing a row
}

/*
    Deconstructor of a game
    unload attribute and close neccessary function
*/
Game::~Game(){
    UnloadSound(rotateSound);//unload SFX
    UnloadSound(clearSound); // unload SFX
    UnloadMusicStream(music); // unload bgm
    CloseAudioDevice(); // close audio
}

/*
    Method to randomly get a block from a list of blocks
    once a block is choose it is not longer in the list until other blocks all being used
*/
Block Game::GetRandomBlock(){
    if(blocks.empty()){
        blocks = GetAllBlocks();
    }

    int randomindex = rand() % blocks.size();
    Block block = blocks[randomindex];
    blocks.erase(blocks.begin() + randomindex);
    return block;
}

// The list of blocks that exist
std::vector<Block> Game::GetAllBlocks(){
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

/*
    Method to for the game to draw the currentblock on the grid board and the nextBlock on the nextBlock preview
*/
void Game::Draw(){
    grid.Draw();
    currentBlock.Draw(11,11);
    switch(nextBlock.id){
        case 3:
            nextBlock.Draw(255,290);
            break;
        case 4:
            nextBlock.Draw(255,280);
            break;
        default:
            nextBlock.Draw(270,270);
    }
}
/*
    Game's logical to handle keyboard event
    pressing up arrow key to rotate
    pressing left arrow key to move left
    pressing right arrow key to move right
    pressing down arrow key to move down
*/
void Game::HandleInput(){
    int keyPressed = GetKeyPressed();
    if(gameOver && keyPressed != 0){
        gameOver = false;
        Reset();
    }
    switch(keyPressed){
        case KEY_LEFT:
            MoveBlockLeft();
            break;
        case KEY_RIGHT:
            MoveBlockRight();
            break;
        case KEY_DOWN:
            MoveBlockDown();
            UpdateScore(0,1);
            break;
        case KEY_UP:
            RotateBlock();
            break;
    }
}

/*
    Method to move block left if the space is avaliable
*/
void Game::MoveBlockLeft(){
    if (!gameOver){
        currentBlock.move(0,-1);
        if(IsBlockOutisde() || BlocksFits() == false){
            currentBlock.move(0,1);
        }
    }
    
}

/*
    Method to move block right if the space is avaliable
*/
void Game::MoveBlockRight(){
    if(!gameOver){
        currentBlock.move(0,1);
        if(IsBlockOutisde() || BlocksFits() == false){
            currentBlock.move(0,-1);
        }
    }
}

/*
    Method to move block down if the space is avaliable
    and lock the block inplace when it collide with other block or reach the end of the grid
*/
void Game::MoveBlockDown(){
    if (!gameOver){
        currentBlock.move(1, 0);
        if(IsBlockOutisde() || BlocksFits() == false){
            currentBlock.move(-1, 0);
            LockBlock();
        }
    }
}

/*
    Method to determine whether or not a block is outside of th grid
*/
bool Game::IsBlockOutisde()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for (Position item: tiles){
        if(grid.IsCellOutside(item.row, item.col)){
            return true;
        }
    }
    return false;
}

/*
    Method to determine whether or not the current block is colliding with other existing blocks
*/
bool Game::BlocksFits(){
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position item: tiles){
        if(grid.IsCellEmpty(item.row, item.col) == false){
            return false;
        }
    }
    return true;
}

/*
    Method to rotate the block in clockwise direction
*/
void Game::RotateBlock(){
    if (!gameOver){
        currentBlock.Rotate();
        if(IsBlockOutisde() || BlocksFits() == false){
            currentBlock.UndoRotate();
        }
        else{
            PlaySound(rotateSound);
        }
    }
}

/*
    Locking a block in place after it reach the end of grid of collided with other blocks
    change the currentblock to nextBlock
    check for row cleared
*/
void Game::LockBlock(){
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position item: tiles){
        grid.grid[item.row][item.col] = currentBlock.id;
    }
    currentBlock = nextBlock;
    if(BlocksFits() == false){
        gameOver = true;
    }
    nextBlock = GetRandomBlock();
    int rowCleared = grid.ClearFullRows();
    if(rowCleared > 0){
        PlaySound(clearSound);
        UpdateScore(rowCleared, 0);
    }
    
}

/*
    Method to reset the game to initial state for more game to play
*/
void Game::Reset(){
    grid.Initialize();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    score = 0;
}

/*
    Method to updating score for the game
*/
void Game::UpdateScore(int lineClear, int moveDownPoints){
    if (lineClear == 1){
        score += 100;
    }
    else if (lineClear == 2){
        score +=300;
    }
    else if (lineClear >= 3){
        score += 500;
    }

    score += moveDownPoints;
}
