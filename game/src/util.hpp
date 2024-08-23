#ifndef util_HPP
#define SPAWNER_HPP

#include "raylib.h"
#include <iostream>
#include <vector>

/*
load all textures and store it in vector in the beginning, pass by reference of vector var to this function and return to the referenced vector var
texture loaded on the heap, referenced vector var stores pointer of texture allocated on heap
*/
std::vector<Texture2D>& loadAllTextures(const int allTexturesNum, const std::string type, std::vector<Texture2D>& textures);

/*
unload all textures using UnloadTexture(Texture2D texture)
delete each ptr as element of vector iteratively
*/
void unloadAllTextures(std::vector<Texture2D>& textures);

/*

*/
Rectangle resize(const int &screenWidth, const int &screenHeight);

#endif
