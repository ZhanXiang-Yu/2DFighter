#include "spawner.hpp"

//maybe better spawn enemy method, so far this is good

Spawner::Spawner(std::vector<Texture2D> &textures)
{
    Vector2 startingPos = this->randomize(screenWidth, screenHeight);
    Enemy* elem = new Enemy(textures, startingPos);
    this->enemiesOnScreen.push_back(elem);
}

Vector2 Spawner::randomize(const int width, const int height)
{
    //TODO: spawn multiple and make sure no overlap exists
    //adjust spawn box later
    int directionToAppear = rand() % 3;
    int spawnWidth;
    int lowerBound, upperBound, range;
    switch(directionToAppear)
    {
        case 0:
            lowerBound = 0;
            upperBound = width / 4;
            range = upperBound - lowerBound;
            spawnWidth = rand() % range + lowerBound + 1;
            break;
        case 1:
            lowerBound = width / 4;
            upperBound = width / 2;
            range = upperBound - lowerBound;
            spawnWidth = rand() % range + lowerBound + 1;
            break;
        case 2:
            lowerBound = width / 2;
            upperBound = width / 4 * 3;
            range = upperBound - lowerBound;
            spawnWidth = rand() % range + lowerBound + 1;
            break;
        default:
            break;
    }
    
    int spawnHeight = rand() % (height / 10);
    Vector2 rval = {(float)spawnWidth, (float)spawnHeight};
    return rval;

    //TODO: multiple at random no overlap with bounds specify by dimensions / 10
}

void Spawner::drawAll()
{
    for(int i = 0; i < this->enemiesOnScreen.size(); i++)
        {
            this->enemiesOnScreen.at(i)->draw();
        }
    for(int i = 0; i < this->bulletsOnScreen.size(); i++)
    {
        this->bulletsOnScreen.at(i)->draw();
    }
}

Spawner::~Spawner()
{
    std::cout << "destructor called" << std::endl;
    for(int i = 0; i < this->enemiesOnScreen.size(); i++)
    {
        delete this->enemiesOnScreen.at(i);
    }
    std::cout << "enemies on screen freed" << std::endl;
    for(int i = 0; i < this->bulletsOnScreen.size(); i++)
    {
        delete this->bulletsOnScreen.at(i);
    }
    std::cout << "bullets on screen freed" << std::endl;
}
