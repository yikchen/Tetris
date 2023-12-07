#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>

double lastUpdateTime  = 0;

//fucntion for event triggering happen every interval
bool EventTriggered(double interval){
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval){
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{   
    //setting up the window
    InitWindow(500, 620, "raylib Tetris");
    //setting up the fps of the game
    SetTargetFPS(60);

    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);// loading font to be use in interface

    Game game = Game(); // intialize game

    //Gameloop for the game
    while(WindowShouldClose() == false){ // while window is open run the game logic
        UpdateMusicStream(game.music);//update music
        game.HandleInput();//check for input and handle it

        if(EventTriggered(0.2)){ // every interval move the block down
            game.MoveBlockDown();
        }
        
        BeginDrawing(); // start drawing 
        ClearBackground(darkBlue); // setting bg for the game
        DrawTextEx(font, "Score", {365,15}, 38, 2, WHITE); // draw socre on interface
        DrawTextEx(font, "Next", {370,175}, 38, 2, WHITE); // draw Next on interface
        if(game.gameOver){ // if gameOver state is reached display game over!
            DrawTextEx(font, "GAME OVER", {320,450}, 38, 2, WHITE);
        }
        
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue); // drawing rectangle for displaying socre

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);


        DrawTextEx(font, scoreText, {320 + (170 - textSize.x)/2, 65}, 38, 2, WHITE); // drawing score with center align
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue); // drawing rectangle for displaying nextBlock
        game.Draw(); // drawing blocks and nextblock 
        EndDrawing(); // close drawing
    }

    CloseWindow();  // close window
}