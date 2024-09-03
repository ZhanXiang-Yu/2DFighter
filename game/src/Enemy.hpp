
#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "raylib.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <util.hpp>
#include <functional>

extern const int screenWidth;
extern const int screenHeight;

class Bullet; //forward declaration

static const float moveChange = 2.0f;

class Enemy
{
    public:
        //constructor
        Enemy(std::vector<Texture2D> &textures, Vector2 startingPos);
        //randomly load a texture and assign values to class members, used in constructor
        void load(std::vector<Texture2D> &textures);
        int randomize(); //random enemy or bullet by randomize index val for textures vector

        //draw func
        void draw();

        //randomly select a movement
        void selectMove();

        //movement patterns, setters for incX and incY
        void moveZigZag();
        void moveDiagonal();
        void moveADSlow();
        void moveADFast();
        void moveRamSlow();
        void moveRamFast();
        //TODO ram toward player

        //boundary check, move back to inside screen, for elite/boss enemies
        bool isBoundary();
        void returnToRelativeOrigin();

        //spawn bullet


        //gettters for pos and hitbox
        //Rectangle getHitbox();
        //Vector2 getPos();

        ~Enemy();

        private:
            Texture2D texture; //pointer elem in vector to reference texture
            Rectangle hitbox; //hitbox get from texture and keep updating
            Vector2 pos; //poistion of the texture that is updated each frame
            int texturesNum;
            bool isInit;

            //movement stuff
            Timer timer;
            int incX;
            int incY;
            int currMove;
            std::vector<std::function<void()>> moves;

            int health; //TODO
};

class Bullet : public Enemy
{
    public:
        //constructor
        Bullet();

        ~Bullet();
    
    private:
        
};
#endif