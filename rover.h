#ifndef ROVER_H
#define ROVER_H

#include "Mars.h"

class Rover
{
    private:
        int x,y;
        char heading;
        int collected_gold = 0;
        bool gameOver = false;

    public:
        Rover()
        {
        }
        void setGameOver(bool b)
        {
            gameOver = b;
        }
        bool getGameOver()
        {
            return gameOver;
        }

        void land(Mars& mars);
        void turnLeft(Mars& mars);
        void turnLeftWOsetObject(Mars& mars);
        void move(Mars& mars);
        void turnRight(Mars& mars);
        void turnRightWOsetObject(Mars& mars);
        void generateGolds(Mars& mars,int);
        void displayMapper(Mars& mars);

        int goldCollection();
};
#endif