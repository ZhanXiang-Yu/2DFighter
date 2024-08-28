#ifndef SPAWNER_HPP
#define SPWANER_HPP

#include "raylib.h"
#include "Enemy.hpp"
#include <iostream>
#include <vector>
#include <Enemy.hpp>

/*
spawn enemy on screen, enemy spawn bullets, spawner also keep tracks of bullets -> data members vectors for enemies and bullets
spawn limit -> check enemies spawned on screen <= fixed num

*/

class Spawner
{
    public:
        //constructor
        Spawner();

        Vector2 randomize(float restrictionX, float restrictionY); //spawn randomly at fixed part of screen

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