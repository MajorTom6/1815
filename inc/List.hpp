#ifndef list_h
#define list_h

#include "Character.hpp"
#include <vector>
#include <ncurses.h>
using namespace std;

class List
{
    public:
        List();
        void draw(WINDOW * w);
    private:
        vector <Character> men;
};

#endif
