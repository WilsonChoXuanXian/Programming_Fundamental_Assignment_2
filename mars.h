#ifndef MARS_H  // include guard.
#define MARS_H

#include <vector>
using namespace std;

class Mars
{
    private:
        vector < vector<char> > map;
        vector < vector<char> > displayMap;
        int dimX, dimY;

    public:
        Mars(int dimx, int dimy)
        {
            dimX = dimx;
            dimY = dimy;
        }
        //void init();
        void resize();
        void display();
        void displayTreassure();
        int getDimX() const;
        int getDimY() const;
        char getObject(int, int);
        void setObject(int, int, char);
        void setObjectDisplay(int, int, char);
        bool isEmpty(int, int);
        bool isInsideMap(int, int);
        bool isMidOfMap(int, int);
        bool isHill (int x, int y);
        bool isTrap (int x, int y);
        bool isGold (int x, int y);

};

#endif