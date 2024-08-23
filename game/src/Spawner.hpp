#ifndef SPAWNER_HPP
#define SPWANER_HPP

#include "raylib.h"
#include "Enemy.hpp"
#include <vector>

class Spawner
{
    public:
        //constructor
        Spawner();

        Vector2 randomize(float restrictionX, float restrictionY); //spawn randomly at fixed part of screen

        //destructor
        ~Spawner();
    
    private:
        int enemyNum;
        std::vector<Enemy> hostiles;
};


#endif