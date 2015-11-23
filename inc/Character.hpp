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
        Location action(vector <Character> men);
        bool check(Location L, vector <Character> men);        
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
