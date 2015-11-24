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
        void move(Location L){l=L;}
        void draw(WINDOW * w);
        void action(vector <Character> men, vector <Location> impassable);
        bool check(Location L, vector <Character> men, vector <Location> impassable);        
        void astar(vector <Character> men, vector <Location> impassable);
        void wander(vector <Character> men, vector <Location> impassable);
        Location getLocation(){return l;}
        char getSymbol(){return symbol;}

    private:
        string order = "wander";
        Location l; // current location
        Location d; // destination
        char symbol;
        int row;
        int col;
        int color;
};

#endif
