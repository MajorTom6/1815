#ifndef list_h
#define list_h

#include "Character.hpp"
#include <vector>
#include <ncurses.h>
#include <ctime>
#include <cstdlib>
using namespace std;

class List
{
    public:
        List(vector <Location> i);
        void draw(WINDOW * w);
        void action();
    private:
        vector <Character> men;
        vector <Location> impassable;
};

#endif
