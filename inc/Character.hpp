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
        Character(char nSymbol, int nColor, Location L);
        void move(Location L){l.x=L.x;l.y=L.y;}
        void draw(WINDOW * w);
        Location action(vector <Location> occupied);
        bool check(Location L, vector <Location> occupied);        
        Location getLocation(){return l;}
        char getSymbol(){return symbol;}

    private:
        string order = "wander";
        Location l;
        char symbol;
        int row;
        int col;
        int color;
};

#endif
