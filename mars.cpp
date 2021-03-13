#include "Mars.h"
#include <iostream>
#include <iomanip> //for setw()
#include <cstdlib>
#include <vector>
#include <thread>
#include <chrono>
#include <ctime> //for time() in srand( time(NULL) );
#include <windows.h> //for Sleep()
#define RESET   "\033[0m"   // to reset the colour
#define RED     "\033[31m"  // Red  
#define YELLOW  "\033[33m"  // Yellow 
using namespace std;

void Mars::resize()
{
    char objects[] = {' ', ' ', ' ', ' ', ' ', ' ',
                      ' ', ' ', ' ', ' ', ' ', ' ',
                      'X', 'X',
                      '#'};
    int noOfObjects = 15; //number of objects in the objects array

    //create dynamic 2D array using vector
    map.resize(dimY);           //create rows
    displayMap.resize(dimY);

    for (int i=0; i<dimY; ++i)
    {
        map[i].resize(dimX);    //resize each rows
        displayMap[i].resize(dimX);
    }
    
    //put random chars into the vector array
    for (int i=0; i<dimY; ++i)
    {
        for (int j=0; j<dimX; ++j)
        {
            int objNo = rand() % noOfObjects;
            if(!isMidOfMap(i,j))
                map[i][j] = objects[ objNo ];
            else
                map[i][j] = ' ';
            displayMap[i][j] = '?';
        }
    }
}

void Mars::display()
{
    system("cls");
    char hill = 178;
    cout << YELLOW << " --__--__--__--__--__--__--__--_" << endl;
    cout << " =" << RESET << " Curiosity, welcome to Mars!" << YELLOW << " =" << endl;
    cout << " __--__--__--__--__--__--__--__-" << RESET << endl;

    for (int i=0; i<dimY; ++i)
    {
        cout << "  ";
        for (int j=0; j<dimX; ++j)
        {
            cout << RED << "+-";
        }
        cout << "+" << RESET << endl;
        cout << setw(2) << (dimY-i);
        for (int j=0; j<dimX; ++j)
        {
            cout << RED << "|" << RESET;

            if ( displayMap[i][j] == 'X')
                cout << hill;
            else 
                cout << displayMap[i][j];
        }
        cout << RED << "|" << RESET << endl;
    }

    cout << "  ";
    for (int j=0; j<dimX; ++j)
    {
        cout << RED << "+-";
    }
    cout << "+" << RESET << endl;

    cout << "  ";
    for (int j=0; j<dimX; ++j)
    {
        int digit = (j+1)/10;
        cout << " ";
        if (digit==0)
            cout << " ";
        else
            cout << digit;
    }
    cout << endl;

    cout << "  ";
    for (int j=0; j<dimX; ++j)
    {
        cout << " " << (j+1)%10;
    }
    cout << endl << endl;
}

void Mars::displayTreassure()
{
    char hill = 178;
    cout << YELLOW << " --__--__--__--__--__--__--__--_" << endl;
    cout << " =" << RESET << " Curiosity, welcome to Mars! " << YELLOW << "=" << endl;
    cout << " __--__--__--__--__--__--__--__-" << RESET << endl;

    for (int i=0; i<dimY; ++i)
    {
        cout << "  ";
        for (int j=0; j<dimX; ++j)
        {
            cout << RED << "+-";
        }
        cout << "+" << RESET << endl;
        cout << setw(2) << (dimY-i);
        for (int j=0; j<dimX; ++j)
        {
            cout << RED << "|" << RESET;

            if ( map[i][j] == 'X')
                cout << hill;
            else 
                cout << map[i][j];
        }
        cout << RED << "|" << RESET << endl;
    }

    cout << "  ";
    for (int j=0; j<dimX; ++j)
    {
        cout << RED << "+-";
    }
    cout << RED <<  "+" << RESET << endl;

    cout << "  ";
    for (int j=0; j<dimX; ++j)
    {
        int digit = (j+1)/10;
        cout << " ";
        if (digit==0)
            cout << " ";
        else
            cout << digit;
    }
    cout << endl;

    cout << "  ";
    for (int j=0; j<dimX; ++j)
    {
        cout << " " << (j+1)%10;
    }
    cout << endl << endl;
}

int Mars::getDimX()const
{
    return dimX;
}

int Mars::getDimY()const
{
    return dimY;
}

char Mars::getObject(int x, int y)
{
    if ((x>=1 && y>=1)&&(x<=dimX && y<=dimY))
        return map[dimY-y][x-1];
}

void Mars::setObject(int x, int y, char letter)
{
    if ((x>=1 && y>=1)&&(x<=dimX && y<=dimY))
        map[dimY-y][x-1] = letter;
}

void Mars::setObjectDisplay(int x, int y, char letter)
{
    if ((x>=1 && y>=1)&&(x<=dimX && y<=dimY))
        displayMap[dimY-y][x-1] = letter;
}

bool Mars::isEmpty(int x, int y)
{
    if (map[dimY-y][x-1] == ' ')
        return true;
    else
        return false;
}

bool Mars::isInsideMap(int x, int y)
{
    if ((x>=1 && x<=dimX) &&
        (y>=1 && y<=dimY))
          return true;
    else
          return false;
}

bool Mars::isMidOfMap(int a, int b)
{
    int x = (getDimX() + 1) / 2;

    int y = (getDimY() + 1) / 2;

    if (a == x && b == y)
          return true;
    else
          return false;
}

bool Mars::isGold(int x, int y)
{
    if (map[dimY-y][x-1] == '$')
        return true;
    else
        return false;
}

bool Mars::isHill(int x, int y)
{
    if (map[dimY-y][x-1] == 'X')
        return true;
    else
        return false;
}

bool Mars::isTrap (int x, int y)
{
    if (map[dimY-y][x-1] == '#')
        return true;
    else
        return false;
}


