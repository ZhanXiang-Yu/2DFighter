/*
player control fighter
fighter shoots bullet
enemy spawn randomly at other side of the map(top of screen)
enemy shoots bullet
fighter bullet touches enemy
enemy bullet touches fighter
health -> fighter/enemy die, UI/global system

make GUI for game to run
    user interactable window
    play button
    control as labels

*/

/*
bugs:

*/

#include "raylib.h"
#include <string>
#include <iostream>

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"


int main()
{
    //window size
    const int screenWidth = 1000;
    const int screenHeight = 1000;
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
    int btnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
    bool btnAction = false;         // Button action should be activated

    // Define frame rectangle for drawing
    float frameHeight = (float)playButton.height/3;
    Rectangle sourceRec = { 0, 0, (float)playButton.width, frameHeight };

    // Define button bounds on screen
    Rectangle btnBounds = { screenWidth/2.0f - playButton.width/2.0f, screenHeight/2.0f - playButton.height/3/2.0f, (float)playButton.width, frameHeight };

    //load cursor image
    Texture2D spaceship = LoadTexture("resources/spaceship.png");
    //pos x y
    int posx = 0;
    int posy = 0;

    //cursor position for shooting
    Vector2 cockpitPos = {0.0f, 0.0f};

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

        //get cursor position and align in the middle of cursor to draw spaceship
        posx = GetMousePosition().x - 75;
        posy = GetMousePosition().y - 75;

        //get cursor position with respect to front of spaceship for game operations
        cockpitPos = {GetMousePosition().x - 75, GetMousePosition().y};
        btnState = false;
        // Check button state
        if (CheckCollisionPointRec(cockpitPos, btnBounds))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState = 2;
            else btnState = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction = true;
        }
        else btnState = 0;

        if (btnAction)
        {
            // TODO: scene transition to playing the game

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
            DrawTextureEx(background, (Vector2){0, scrollingBack}, 0.0f, 1.0f, WHITE);
            DrawTextureEx(background, (Vector2){0, -background.height + scrollingBack}, 0.0f, 1.0f, WHITE);
            
            //DrawTexture(playButton, 375, 460, WHITE);
            DrawTextureRec(playButton, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE); // Draw button frame

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