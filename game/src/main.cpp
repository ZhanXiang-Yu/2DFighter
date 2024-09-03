/*
bugs:
*/

/*
TODO:
add explosion animation
change shooting sound
add enemy obj return to origin movement pattern
add ram toward player movement for enemy
resizer for differnet screens 
*/

#include "raylib.h"
#include <string>
#include <iostream>
#include "util.hpp"
#include "Enemy.hpp"
#include "Spawner.hpp"
#include <vector>
#include <time.h>

//window dimension global
const int screenWidth = 1980;
const int screenHeight = 1020;

int main()
{
    srand(time(0));

    //window init.
    InitWindow(screenWidth, screenHeight, "Fighter");

    //init audio
    InitAudioDevice();
    Sound shootLaser = LoadSound("resources/laser1.wav");   // Load button sound
    //load screen buttons
    Texture2D playButton = LoadTexture("resources/PLAY.png");
    Texture2D retryButton = LoadTexture("resources/RETRY.png");
    Texture2D menuButton = LoadTexture("resources/MENU.png");
    Texture2D gameOver = LoadTexture("resources/GAMEOVER.png");

    //set icon
    Image icon = LoadImage("resources/icon.png");
    SetWindowIcon(icon); 

    //set background
    Texture2D background = LoadTexture("resources/background.png");
    float scrollingBack = 0.0f;

    SetTargetFPS(60);

    //vector to hold all game assets and load
    std::vector<Texture2D> texturesEnemies;
    const std::string enemyDirID = "enemy";
    const int enemyNum = 6;
    std::vector<Texture2D> texturesBullets;
    const std::string bulletDirID = "bullet";
    const int bulletNum = 6;
    //load all enemy assets
    loadHostilesTextures(enemyNum, enemyDirID, texturesEnemies);
    //load all bullet assets
    loadHostilesTextures(bulletNum, bulletDirID, texturesBullets);

    //states of buttons
    bool playBtnState = false;
    bool retryBtnState = false;
    bool menuBtnState = false;

    // Define button bounds on screens
    Rectangle playBtnBounds = {screenWidth/2.0f - playButton.width/2.0f, screenHeight/2.0f - playButton.height/2.0f, (float)playButton.width, (float)playButton.height};
    Rectangle retryBtnBounds = {screenWidth/2.0f - retryButton.width/2.0f, screenHeight/3.0f * 2.0f - retryButton.height/3.0f, (float)retryButton.width, (float)retryButton.height};
    Rectangle menuBtnBounds = {screenWidth/2.0f - menuButton.width/2.0f, screenHeight/3.0f * 2.5f - menuButton.height/3.0f, (float)menuButton.width, (float)menuButton.height};

    //load spaceship
    Texture2D spaceship = LoadTexture("resources/spaceship.png");
    //cursor position for drawing
    Vector2 posXY = {0.0f, 0.0f};
    //rectangle range for spaceship
    Rectangle spaceshipSize = {0.0f, 0.0f, 0.0f, 0.0f};

    //cursor position for shooting
    Vector2 cockpitPos = {0.0f, 0.0f};

    //params. for diff. textures
    Vector2 backgroundPos1 = {0.0f, 0.0f};
    Vector2 backgroundPos2 = {0, 0.0f};
    Vector2 playButtonPos = {playBtnBounds.x, playBtnBounds.y};
    Vector2 menuButtonPos = {menuBtnBounds.x, menuBtnBounds.y};
    Vector2 retryButtonPos = {retryBtnBounds.x, retryBtnBounds.y};
    Vector2 gameOverPos = {screenWidth/2.0f- gameOver.width/2.0f, screenHeight/3.0f - gameOver.height/3.0f};

    //screen transition var
    screens currScreen = Start;

    //testing
    Spawner* test = new Spawner(texturesEnemies);

    HideCursor();
    while (!WindowShouldClose())
    {
        
        //update scrolling
        scrollingBack += 1.5f;
        // with respect to scaling
        if (scrollingBack >= background.height*2) scrollingBack = 0;

        backgroundPos1 = {0, scrollingBack};
        backgroundPos2 = {0, -background.height*2 + scrollingBack};

        //get cursor position and align in the middle of cursor to draw spaceship
        posXY = {GetMousePosition().x, GetMousePosition().y};
        spaceshipSize = {posXY.x, posXY.y, (float)spaceship.width, (float)spaceship.height};

        //get cursor position with respect to front of spaceship for game operations
        cockpitPos = {GetMousePosition().x - 75, GetMousePosition().y};

        // Check play button state to advance to next screen
        if (CheckCollisionPointRec(cockpitPos, playBtnBounds))
        {
           if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
           {
                playBtnState = true;
           }
        }

        // Check retry button state to advance to next screen
        if (CheckCollisionPointRec(cockpitPos, retryBtnBounds))
        {
           if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
           {
                retryBtnState = true;
           }
        }

        // Check menu button state to advance to next screen
        if (CheckCollisionPointRec(cockpitPos, menuBtnBounds))
        {
           if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
           {
                menuBtnState = true;
           }
        }

        switch(currScreen)
        {
            case Start:
                if (playBtnState)
                {
                    //scene transition to playing the game
                    std::cout << "start playing!!!" << std::endl;
                    playBtnState = false;
                    currScreen = Ingame;
                }
                break;
            case Ingame: //m1 to advance for now, before implement
                if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
                {
                    std::cout << "UR HIT!!!" << std::endl;
                    currScreen = End;
                }
                break;
            case End:
                if (retryBtnState)
                {
                    //scene transition to playing the game
                    std::cout << "retry to in game" << std::endl;
                    retryBtnState = false;
                    currScreen = Ingame;
                }
                if (menuBtnState)
                {
                    //scene transition to playing the game
                    std::cout << "go back to start menu" << std::endl;
                    menuBtnState = false;
                    currScreen = Start;
                }
                break;
            default:
                break;
        }
        
        //mouse pressed
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            PlaySound(shootLaser);
            //TODO: spawn bullets
            //TODO: add delay
        }

        //----------------------------------------------------------------------------------
        BeginDrawing();
            ClearBackground(GetColor(0x18151BFF));

            //draw background
            DrawTextureEx(background, backgroundPos1, 0.0f, 2.0f, WHITE);
            DrawTextureEx(background, backgroundPos2, 0.0f, 2.0f, WHITE);
            
            switch(currScreen)
            {
                case Start:
                    DrawTextureEx(playButton, playButtonPos, 0.0f, 1.0f, WHITE);
                    break;
                case Ingame:
                    test->drawAll();
                    break;
                case End:
                    DrawTextureEx(gameOver, gameOverPos, 0.0f, 1.0f, WHITE);
                    DrawTextureEx(retryButton, retryButtonPos, 0.0f, 1.0f, WHITE);
                    DrawTextureEx(menuButton, menuButtonPos, 0.0f, 1.0f, WHITE);
                    break;
                default:
                    break;
            }
            //DrawTextureEx(playButton, playButtonPos, 0.0f, 1.0f, WHITE);

            //draw spaceship as new cursor
            DrawTexture(spaceship, (int)posXY.x, (int)posXY.y, WHITE);

        EndDrawing();
    }
    UnloadTexture(spaceship);
    UnloadImage(icon);
    UnloadTexture(playButton);
    UnloadTexture(retryButton);
    UnloadTexture(menuButton);
    UnloadTexture(gameOver);
    UnloadSound(shootLaser);

    //unload hostiles
    unloadHostilesTextures(texturesEnemies);
    unloadHostilesTextures(texturesBullets);

    //testing
    delete test;

    CloseAudioDevice();
    CloseWindow();
    return 0;
}