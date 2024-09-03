#include "Enemy.hpp"

Enemy::Enemy(std::vector<Texture2D> &textures, Vector2 startingPos)
{
    this->texturesNum = textures.size();
    this->pos = startingPos;
    this->isInit = true;
    this->incX = 0;
    this->incY = 0;

    //movement patterns init.
    this->moves.push_back(std::bind(&Enemy::moveDiagonal,this));
    this->moves.push_back(std::bind(&Enemy::moveRamSlow,this));
    this->moves.push_back(std::bind(&Enemy::moveRamFast,this));
    //pushes the rest later when timer is implemented in movement

    startTimer(this->timer, moveChange);
    this->load(textures);
}

void Enemy::load(std::vector<Texture2D> &textures)
{
    int randomIndex = randomize();
    this->texture = textures.at(randomIndex);
    this->hitbox = {this->pos.x, this->pos.y, (float)this->texture.width, (float)this->texture.height};
}

void Enemy::draw()
{
    if(this->isInit)
    {
        DrawTextureEx(this->texture, this->pos, 0.0f, 1.0f, WHITE);
        this->selectMove();
        this->isInit = false;
        updateTimer(this->timer);
    }
    //testing
    if(this->isBoundary())
    {
        std::cout << "touching" << std::endl;
    }
    
    if(timerDone(this->timer))
    {
        std::cout << "timer done" << std::endl;
    }
    
    if(!(timerDone(this->timer))) //    
    {
        std::cout << "normal case" << std::endl;
        DrawTextureEx(this->texture, this->pos, 0.0f, 1.0f, WHITE);
        updateTimer(this->timer);
        //run the selected functions from moves vector member
        this->moves[this->currMove]();

    }
    else
    {
        //this->returnToRelativeOrigin();
        startTimer(this->timer, moveChange);
        this->selectMove();
    }
}

void Enemy::selectMove()
{
    //select random move by random index of moves vector member 
    this->currMove = rand() % this->moves.size();
}

Enemy::~Enemy()
{
    std::cout << "enemy destructor called" << std::endl;
}

int Enemy::randomize()
{
    int randomIndex = rand() % this->texturesNum;
    return randomIndex;
}


void Enemy::moveZigZag()
{

}

void Enemy::moveDiagonal()
{
    if( !(this->isBoundary()) )
    {
        this->incX = 10;
        this->pos.x += this->incX;
        this->incY = 10;
        this->pos.y += this->incY;
    }
    else
    {
        this->incX = -10;
        this->pos.x += this->incX;
        this->incY = -10;
        this->pos.y += this->incY;
    }
    
}

void Enemy::moveADSlow()
{

}

void Enemy::moveADFast()
{

}

void Enemy::moveRamSlow()
{
    if( !(this->isBoundary()) )
    {
        this->incY = 5;
        this->pos.y += this->incY;
    }
    else
    {
        this->incY = -5;
        this->pos.y += this->incY;
    }
}

void Enemy::moveRamFast()
{
    if( !(this->isBoundary()) )
    {
        this->incY = 15;
        this->pos.y += this->incY;
    }
    else
    {
        this->incY = -15;
        this->pos.y += this->incY;
    }
}

bool Enemy::isBoundary()
{
    return (this->pos.x + this->texture.width >= screenWidth || this->pos.x <= 0 || this->pos.y + this->texture.height >= screenHeight || this->pos.y <= 0);
}

void Enemy::returnToRelativeOrigin()
{
    //testing
    std::cout << "return to orig in" << std::endl;

    int directionToAppear = rand() % 3;
    int lowerBound, upperBound, range;
    switch(directionToAppear)
    {
        case 0:
            lowerBound = 0;
            upperBound = screenWidth / 4;
            range = upperBound - lowerBound;
            this->pos.x = rand() % range + lowerBound + 1;
            break;
        case 1:
            lowerBound = screenWidth / 4;
            upperBound = screenWidth / 2;
            range = upperBound - lowerBound;
            this->pos.x = rand() % range + lowerBound + 1;
            break;
        case 2:
            lowerBound = screenWidth / 2;
            upperBound = screenWidth / 4 * 3;
            range = upperBound - lowerBound;
            this->pos.x = rand() % range + lowerBound + 1;
            break;
        default:
            break;
    }
    
    this->pos.y = rand() % (screenHeight / 10);
}



//bullet destructor
Bullet::~Bullet()
{
    std::cout << "bullet destructor called" << std::endl;
}