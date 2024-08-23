
#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "raylib.h"
/*
spawner to randomly spawn a enemy type with diff.bullet speed and movement pattern
*/
class Enemy
{
    public:
        //constructor
        Enemy();

        //load function to load a random enemy type and bullet type
        void load(const char* arry[], int index);
        //draw a texture
        Rectangle spawn(int index, Vector2 position);
        int randomize(); //random enemy or bullet
        float randomize(float multiplier); //random movement speed or bullet speed
        

        //destructor to delete textures and bullets -> despawn
        ~Enemy();

        private:
            Texture2D enemy;
            Texture2D bullet;
            Rectangle hitbox;
};

#endif