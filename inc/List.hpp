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
        List();
        void draw(WINDOW * w);
        void actions();
    private:
        vector <Character> men;
};

#endif
