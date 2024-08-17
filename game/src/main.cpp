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
mouse cursor show on reenter to Window
*/

#include "raylib.h"
#include <string>
#include <iostream>

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"


int main()
{
    InitWindow(1000, 1000, "Fighter");
    //set icon
    Image icon = LoadImage("resources/icon.png");
    SetWindowIcon(icon); 

    SetTargetFPS(60);

    //load font
    Font playFont = LoadFontEx("resources/arcadeclassic/ARCADECLASSIC.ttf", 100, 0, 250);
    // Set bilinear scale filter for better font scaling
    SetTextureFilter(playFont.texture, TEXTURE_FILTER_BILINEAR);    
    SetTextLineSpacing(20);         // Set line spacing for multiline text (when line breaks are included '\n')
    //load font to GUI
    GuiSetFont(playFont);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 50);

    //set control style for widgets
    GuiSetStyle(BUTTON, TEXT_COLOR_NORMAL, 0xF8F8F8FF);
    GuiSetStyle(BUTTON, BASE_COLOR_FOCUSED, 0x18151BFF);
    GuiSetStyle(BUTTON, BASE_COLOR_PRESSED, 0x18151BFF);
    GuiSetStyle(BUTTON, BORDER_COLOR_FOCUSED, 0xF8F8F8FF);
    GuiSetStyle(BUTTON, BORDER_COLOR_PRESSED, 0xF8F8F8FF);

    bool showMessageBox = false;

    //load cursor image
    Texture2D spaceship = LoadTexture("resources/spaceship.png");
    //pos x y
    int posx = 0;
    int posy = 0;

    HideCursor();
    while (!WindowShouldClose())
    {
        if(!IsCursorHidden())
        {
            HideCursor();
        }
        //----------------------------------------------------------------------------------
        BeginDrawing();
            ClearBackground(GetColor(0x18151BFF));
            //get cursor position and align in the middle of cursor
            posx = GetMousePosition().x - 75;
            posy = GetMousePosition().y - 75;
            //draw spaceship as new cursor
            DrawTexture(spaceship, posx, posy, WHITE);
            //hide mouse
            
            if (GuiButton((Rectangle){ 375, 460, 250, 80 }, "PLAY!")) showMessageBox = true;

            if (showMessageBox)
            {
                int result = GuiMessageBox((Rectangle){ 85, 70, 250, 100 },
                    "#191#Message Box", "supposedly start playing", "Nice;Cool");

                if (result >= 0) showMessageBox = false;
            }
        EndDrawing();
    }
    UnloadFont(playFont); 
    UnloadTexture(spaceship);
    UnloadImage(icon);
    CloseWindow();
    return 0;
}