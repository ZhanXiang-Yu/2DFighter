
#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "raylib.h"
#include <iostream>
#include <vector>

class Bullet; //forward declaration

/*
spawner to randomly spawn a enemy type with diff.bullet speed and movement pattern
*/
class Enemy
{
    public:
        //constructor
        Enemy();

        //load function to load a random enemy type or bullet type
        void load(const char* arry[], int index);
        //draw a texture
        Rectangle spawn(int index, Vector2 position);
        int randomize(); //random enemy or bullet
        float randomize(float multiplier); //random movement speed or bullet speed
        bool isCollision(Rectangle &first, Rectangle &second); //collision check either toward player by bullet or enemy, or toward enemy by player bullet
        

        //destructor to delete textures and bullets -> despawn, likely not needed because util func to unload everything
        ~Enemy();

        private:
            Texture2D texture;
            Rectangle hitbox;
            std::vector<Bullet> bullets;
};

class Bullet : public Enemy
{
    public:
        //constructor
        Bullet();
    
    private:
        ~Bullet();
};
#endif