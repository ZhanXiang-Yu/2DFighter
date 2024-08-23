/*
bugs:
play button disappear to a smaller version of background -> fix scene transition issue
*/

#include "raylib.h"
#include <string>
#include <iostream>
#include "util.hpp"
#include "Enemy.hpp"

int main()
{
    //window size
    const int screenWidth = 1980;
    const int screenHeight = 1020;
    InitWindow(screenWidth, screenHeight, "Fighter");

    //init audio
    InitAudioDevice();
    Sound shootLaser = LoadSound("resources/laser1.wav");   // Load button sound
    Texture2D playButton = LoadTexture("resources/PLAY.png"); // Load button texture

    //set icon
    Image icon = LoadImage("resources/icon.png");
    SetWindowIcon(icon); 

    //set background
    Texture2D background = LoadTexture("resources/background.png");
    float scrollingBack = 0.0f;

    SetTargetFPS(60);


    //play button states and animation frames set
    bool btnState = false;         // Button action should be activated

    // Define frame rectangle for drawing
    //Rectangle sourceRec = { 0, 0, (float)playButton.width, float(playButton.height) };

    // Define button bounds on screen
    Rectangle btnBounds = {screenWidth/2.0f - playButton.width/2.0f, screenHeight/2.0f - playButton.height/2.0f, (float)playButton.width, (float)playButton.height };

    //load cursor image
    Texture2D spaceship = LoadTexture("resources/spaceship.png");
    //pos x y
    int posx = 0;
    int posy = 0;

    //cursor position for shooting
    Vector2 cockpitPos = {0.0f, 0.0f};

    //params. for diff. textures
    Vector2 backgroundPos1 = {0.0f, 0.0f};
    Vector2 backgroundPos2 = {0, 0.0f};
    Vector2 playButtonPos = {btnBounds.x, btnBounds.y};

    HideCursor();
    if(IsAudioDeviceReady())
    {
        std::cout << "audio device initialized" << std::endl;
    }
    while (!WindowShouldClose())
    {
        
        //update scrolling
        scrollingBack += 0.9f;
        // with respect to scaling
        if (scrollingBack >= background.height) scrollingBack = 0;

        backgroundPos1 = {0, scrollingBack};
        backgroundPos2 = {0, -background.height + scrollingBack};

        //get cursor position and align in the middle of cursor to draw spaceship
        posx = GetMousePosition().x - 75;
        posy = GetMousePosition().y - 75;

        //get cursor position with respect to front of spaceship for game operations
        cockpitPos = {GetMousePosition().x - 75, GetMousePosition().y};
        // Check button state
        if (CheckCollisionPointRec(cockpitPos, btnBounds))
        {
           if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
           {
                btnState = true;
           }
        }

        if (btnState)
        {
            //scene transition to playing the game
            std::cout << "start playing!!!" << std::endl;
            UnloadTexture(playButton);
            btnState = false;
            //todo: enemy spawn and so on

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
            
            DrawTextureEx(playButton, playButtonPos, 0.0f, 1.0f, WHITE);

            //draw spaceship as new cursor
            DrawTexture(spaceship, posx, posy, WHITE);

        EndDrawing();
    }
    //UnloadFont(playFont); 
    UnloadTexture(spaceship);
    UnloadImage(icon);
    UnloadTexture(playButton);
    UnloadSound(shootLaser);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}