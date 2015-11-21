#ifndef character_h
#define character_h

#include <ncurses.h>
#include <cstdlib>
#include <vector>
#include <string>
#include "Location.hpp"
using namespace std;

class Character
{
    public:
        Character(char nSymbol, int nColor,int nRow, int nCol);
        void move(Location L);
        void draw(WINDOW * w);
        bool action(vector <Location> occupied);
        bool check(Location L, vector <Location> occupied);
        int getRow();
        int getCol();
        Location getLocation(){return l;}
        char getSymbol();

    private:
        string order = "wander";
        Location l;
        char symbol;
        int row;
        int col;
        int color;
};

#endif
