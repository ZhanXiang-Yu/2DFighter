
#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "raylib.h"
#include <iostream>
#include <vector>

class Bullet; //forward declaration

/*
1 spwawn, 2 move, 3 spawn Bullet obj at fised interval, 
spawn bullets and keep track?
1
randomly select a texture(random index with range), spawn with a pos(randomly by spawner class), keep track of pos in member(hitbox), keep track of texture in member
    in load function, used in constructor
2
draw texture at diff positions based on randomizer -> (+randomVal1 * multiplier, +randomVal2 * multiplier), multiplier based on screen size, keep track of hitbox
    stop drawing when -> is collide(1), out of screen
3
instantiate bullet obj. at fixed delay, since bullet class inherit from enemy, same rule of disappearing apply

getters to communicate with spawner class
*/
class Enemy
{
    public:
        //constructor
        Enemy(std::vector<Texture2D> &textures, Vector2 startingPos);
        //randomly load a texture and assign values to class members, used in constructor
        void load(std::vector<Texture2D> &textures);
        int randomize(int range); //random enemy or bullet by randomize index val for textures vector

        //movement and upate
        Rectangle move();
        void update();
        float randomize(float multiplier); //random movement speed or bullet speed per frame

        //spawn bullet


        //gettters for pos and hitbox
        Rectangle getHitbox();
        Vector2 getPos();

        //destructor to delete textures and bullets -> despawn, likely not needed because util func to unload everything
        //~Enemy();

        private:
            Texture2D texture; //pointer elem in vector to reference texture
            Rectangle hitbox; //hitbox get from texture and keep updating
            Vector2 pos; //poistion of the texture that is updated each frame
            int texturesNum;
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