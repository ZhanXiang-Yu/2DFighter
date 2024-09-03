#ifndef SPAWNER_HPP
#define SPWANER_HPP

#include "raylib.h"
#include "Enemy.hpp"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <Enemy.hpp>

extern const int screenWidth;
extern const int screenHeight;

class Spawner
{
    public:
        //constructor
        Spawner(std::vector<Texture2D> &textures);
        Vector2 randomize(const int width, const int height); //spawn randomly at fixed part of screen, no overlap

        //draw existing assets on screen at each frame
        void drawAll();

        //collision
        bool isCollision(Rectangle &first, Rectangle &second); //collision check either toward player by bullet or enemy, or toward enemy by player bullet


        //destructor
        ~Spawner();
    
    private:
        //int enemyNum;
        std::vector<Enemy*> enemiesOnScreen;
        std::vector<Bullet*> bulletsOnScreen;
};


#endif