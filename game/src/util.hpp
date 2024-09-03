#ifndef UTIL_HPP
#define UTIL_HPP

#include "raylib.h"
#include <iostream>
#include <vector>
#include <string>


/*
load all textures and store it in vector in the beginning, pass by reference of vector var to this function and return to the referenced vector var
texture loaded on the heap, referenced vector var stores pointer of texture allocated on heap
*/
std::vector<Texture2D>& loadHostilesTextures(const int allTexturesNum, const std::string type, std::vector<Texture2D>& textures);

/*
unload all textures using UnloadTexture(Texture2D texture)
delete each ptr as element of vector iteratively
*/
void unloadHostilesTextures(std::vector<Texture2D>& textures);

/*

*/
Rectangle resize(const int &screenWidth, const int &screenHeight);


//transitions of diff. screens
enum screens
{
    Start = 0,
    Ingame,
    End
};

//timer stuff
struct Timer{
    float lifetime;
};

void startTimer(Timer& timer, float lifetime);
void updateTimer(Timer& timer);
bool timerDone(Timer& timer);
#endif
