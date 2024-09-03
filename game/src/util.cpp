#include "util.hpp"

std::vector<Texture2D>& loadHostilesTextures(const int allTexturesNum, const std::string type, std::vector<Texture2D> &textures)
{
    /*
    file path is resources/Enemy or Bullet/enemy or bullet + number
    */
    const char* cstr = nullptr;
    const std::string firstDir = "resources";
    const std::string separator = "/";
    const std::string format = ".png";

    textures.clear();
    for(int i = 0; i < allTexturesNum; i++)
    {
        char incChar = i + 48 + 1; //manually convert to char ascii, +1 as assets start at 1
        std::string filePath = firstDir + separator + type + separator + type + incChar + format;
        std::cout << filePath << std::endl; //testing
        cstr = filePath.c_str();
        textures.push_back(LoadTexture(cstr));
    }    

    return textures;
}

void unloadHostilesTextures(std::vector<Texture2D> &textures)
{
    for(int i = 0; i < textures.size(); i++)
    {
        UnloadTexture((textures.at(i)));
    }
}

void startTimer(Timer& timer, float lifetime)
{
    timer.lifetime = lifetime;
}

void updateTimer(Timer& timer)
{
    
    timer.lifetime -= GetFrameTime();
}

bool timerDone(Timer& timer)
{
    return timer.lifetime <= 0;
}
