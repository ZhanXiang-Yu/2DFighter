#include "util.hpp"
#include "raylib.h"
#include <iostream>
#include <string>

std::vector<Texture2D>& loadAllTextures(const int allTexturesNum, const std::string type, std::vector<Texture2D> &textures)
{
    /*
    file path is resources/Enemy or Bullet/enemy or bullet + number
    */
    const char* cstr = nullptr;
    const std::string firstDir = "resources";
    const std::string separator = "/";
    const std::string format = ".png";
    int incInt = 1;

    textures.clear();
    for(int i = 0; i < allTexturesNum; i++)
    {
        char incChar = incInt + 48; //manually convert to char ascii
        std::string filePath = firstDir + separator + type + separator + type + incChar + format;
        std::cout << filePath << std::endl; //testing
        cstr = filePath.c_str();
        textures.push_back(LoadTexture(cstr));
    }    

    return textures;
}

void unloadAllTextures(std::vector<Texture2D*> &textures)
{
    for(int i = 0; i < textures.size(); i++)
    {
        UnloadTexture(*(textures.at(i)));
        delete textures.at(i); // unsure about how unloadtexture work I might be double free
    }
}
