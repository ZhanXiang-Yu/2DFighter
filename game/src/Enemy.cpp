/*
reference header file
*/
#include "Enemy.hpp"
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
#include <vector>
#include "raylib.h"


Enemy::Enemy(std::vector<Texture2D> &textures, Vector2 startingPos)
{
    this->texturesNum = textures.size();
    this->pos = startingPos;
    this->load(textures);
}

void Enemy::load(std::vector<Texture2D> &textures)
{

}

int Enemy::randomize(int range)
{
    return 0;
}
