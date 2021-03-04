#include "Mars.h"
#include "Rover.h"
#include <iostream>
#include <iomanip> //for setw()
#include <cstdlib>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <ctime> //for time() in srand( time(NULL) );
#include <windows.h> //for Sleep()
using namespace std;

int Rover::goldCollection()
{
    return collected_gold;
}

void Rover::land(Mars& mars)
{
    char possibleHeading[] = {'^', '>', '<', 'v'};

    x = mars.getDimX();
    if(x%2 == 1)
        x = x/2 + 1;
    else
        x = x/2;

    y = mars.getDimY();
    if(y%2 == 1)
        y = y/2 + 1;
    else
        y = y/2;
    
    heading = possibleHeading[ rand() % 4 ];
    mars.setObjectDisplay(x,y,heading);
}

void Rover::turnLeft(Mars& mars)
{
    if(heading == '^')
        heading = '<';
    else if(heading == '>')
        heading = '^';
    else if(heading == '<')
        heading = 'v';
    else if(heading == 'v')
        heading = '>';

    mars.setObjectDisplay(x,y,heading);
}

void Rover::turnRight(Mars& mars)
{
    if(heading == '^')
        heading = '>';
    else if(heading == '>')
        heading = 'v';
    else if(heading == '<')
        heading = '^';
    else if(heading == 'v')
        heading = '<';

    mars.setObjectDisplay(x,y,heading);
}

void Rover::move(Mars& mars)
{
    mars.setObjectDisplay(x,y,' ');

    if(heading == '^')
        y += 1;
    else if(heading == '>')
        x += 1;
    else if(heading == '<')
        x -= 1;
    else if(heading == 'v')
        y -= 1;
    if(mars.isInsideMap(x,y))
    {
        if (mars.isEmpty(x,y))
            mars.setObjectDisplay(x,y,heading);
        else if (mars.isTrap(x,y))
        {
            mars.setObjectDisplay(x,y,'@');
            gameOver = true;
            return;
        }
        else if (mars.isGold(x,y))
        {
            mars.setObject(x,y,' ');
            mars.setObjectDisplay(x,y,heading);
            collected_gold += 1;
        }
        else if (mars.isHill(x,y))
        {
            if(heading == '^')
                y -= 1;
            if(heading == '>')
                x -= 1;
            if(heading == '<')
                x += 1;
            if(heading == 'v')
                y += 1;
            mars.setObjectDisplay(x,y,heading);
            mars.display();
            cout << "Route is BLOCKED, please turn left or right..." << endl;
            system("pause");
        }
    }
    else
    {
        if(heading == '^')
            y -= 1;
        if(heading == '>')
            x -= 1;
        if(heading == '<')
            x += 1;
        if(heading == 'v')
            y += 1;
        mars.setObjectDisplay(x,y,heading);
        mars.display();
        cout << "You are moving out of Mars, please turn left or right!!!" << endl;
        system("pause");
    }
}

void Rover::generateGolds(Mars& mars,int golds){
    land(mars);
    int gold_generated = 0;

    do{
        int action = rand() % 15;

        if(action <= 1){
            if(heading == '^')
                heading = '<';
            else if(heading == '>')
                heading = '^';
            else if(heading == '<')
                heading = 'v';
            else if(heading == 'v')
                heading = '>';
        }
        else if(action <= 3){
            if(heading == '^')
                heading = '>';
            else if(heading == '>')
                heading = 'v';
            else if(heading == '<')
                heading = '^';
            else if(heading == 'v')
                heading = '<';
        }
        else{
            int turn = rand()%2;
            int drop_gold = rand()%10;

            if(heading == '^')
            {
                if(mars.isInsideMap(x,y+1) && !mars.isHill(x,y+1) && !mars.isTrap(x,y+1))
                {
                    if(mars.isGold(x,y) || mars.isMidOfMap(x,y)){
                        y += 1;
                        continue;
                    }
                    
                    if(drop_gold == 0){
                        mars.setObject(x,y,'$');
                        gold_generated += 1;
                    }
                    y += 1;
                }
                else
                {
                    if (turn == 0)
                        heading = '<';
                    else
                        heading = '>';
                }
            }
            else if(heading == 'v')
            {
                if(mars.isInsideMap(x,y-1) && !mars.isHill(x,y-1) && !mars.isTrap(x,y-1))
                {
                    if(mars.isGold(x,y) || mars.isMidOfMap(x,y)){
                        y -= 1;
                        continue;
                    }

                    if(drop_gold == 0){
                        mars.setObject(x,y,'$');
                        gold_generated += 1;
                    }
                    y -= 1;
                }
                else
                {
                    if (turn == 0)
                        heading = '>';
                    else
                        heading = '<';
                }
            }
            else if(heading == '<')
            {
                if(mars.isInsideMap(x-1,y) && !mars.isHill(x-1,y) && !mars.isTrap(x-1,y))
                {
                    if(mars.isGold(x,y) || mars.isMidOfMap(x,y)){
                        x -= 1;
                        continue;
                    }

                    if(drop_gold == 0){
                        mars.setObject(x,y,'$');
                        gold_generated += 1;
                    }
                    x -= 1;
                }
                else
                {
                    if (turn == 0)
                        heading = 'v';
                    else
                        heading = '^';
                }
            }
            else if(heading == '>')
            {
                if(mars.isInsideMap(x+1,y) && !mars.isHill(x+1,y) && !mars.isTrap(x+1,y))
                {
                    if(mars.isGold(x,y) || mars.isMidOfMap(x,y)){
                        x += 1;
                        continue;
                    }

                    if(drop_gold == 0){
                        mars.setObject(x,y,'$');
                        gold_generated += 1;
                    }
                    x += 1;
                }
                else
                {
                    if (turn == 0)
                        heading = '^';
                    else
                        heading = 'v';
                }
            }
        }

    }while(gold_generated < golds);
}

void Rover::displayMapper(Mars& mars)
{
    if(heading == '^'){
        mars.setObjectDisplay(x,(y+1),(mars.getObject((x),(y+1))));
        mars.setObjectDisplay((x+1),(y+1),(mars.getObject((x+1),(y+1))));
        mars.setObjectDisplay((x-1),(y+1),(mars.getObject((x-1),(y+1))));
    }
    else if(heading == 'v')
    {
        mars.setObjectDisplay(x,(y-1),(mars.getObject((x),(y-1))));
        mars.setObjectDisplay((x+1),(y-1),(mars.getObject((x+1),(y-1))));
        mars.setObjectDisplay((x-1),(y-1),(mars.getObject((x-1),(y-1))));
    }
    else if(heading == '>')
    {
        mars.setObjectDisplay((x+1),y,(mars.getObject((x+1),y)));
        mars.setObjectDisplay((x+1),(y+1),(mars.getObject((x+1),(y+1))));
        mars.setObjectDisplay((x+1),(y-1),(mars.getObject((x+1),(y-1))));
    }
    else if(heading == '<')
    {
        mars.setObjectDisplay((x-1),y,(mars.getObject((x-1),y)));
        mars.setObjectDisplay((x-1),(y+1),(mars.getObject((x-1),(y+1))));
        mars.setObjectDisplay((x-1),(y-1),(mars.getObject((x-1),(y-1))));
    }
}