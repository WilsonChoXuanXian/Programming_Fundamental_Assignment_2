#include "Mars.h"
#include <iostream>
#include <iomanip> //for setw()
#include <cstdlib>
#include <vector>
#include <thread>
#include <chrono>
#include <ctime> //for time() in srand( time(NULL) );
#include <windows.h> //for Sleep()
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
            map[i][j] = objects[ objNo ];
            displayMap[i][j] = '?';
        }
    }
}

void Mars::display()
{
    system("cls");
    char hill = 178;
    cout << " --__--__--__--__--__--__--__--_" << endl;
    cout << " = Curiosity, welcome to Mars! =" << endl;
    cout << " __--__--__--__--__--__--__--__-" << endl;

    for (int i=0; i<dimY; ++i)
    {
        cout << "  ";
        for (int j=0; j<dimX; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        cout << setw(2) << (dimY-i);
        for (int j=0; j<dimX; ++j)
        {
            cout << "|";

            if ( displayMap[i][j] == 'X')
                cout << hill;
            else 
                cout << displayMap[i][j];
        }
        cout << "|" << endl;
    }

    cout << "  ";
    for (int j=0; j<dimX; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;

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
    cout << " --__--__--__--__--__--__--__--_" << endl;
    cout << " = Curiosity, welcome to Mars! =" << endl;
    cout << " __--__--__--__--__--__--__--__-" << endl;

    for (int i=0; i<dimY; ++i)
    {
        cout << "  ";
        for (int j=0; j<dimX; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        cout << setw(2) << (dimY-i);
        for (int j=0; j<dimX; ++j)
        {
            cout << "|" ;

            if ( map[i][j] == 'X')
                cout << hill;
            else 
                cout << map[i][j];
        }
        cout << "|" << endl;
    }

    cout << "  ";
    for (int j=0; j<dimX; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;

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


