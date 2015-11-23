#ifndef frame_h
#define frame_h

#include <ncurses.h>
#include "Character.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class Frame
{
    public: 
        Frame(string location, int nRow, int nCol); // main window with seeded map
        Frame(Frame &super, int rows, int cols, int nRow, int nCol); // viewport
        ~Frame();
        WINDOW * getWin(){return w;}
        WINDOW * getSuper(){return super;}
        bool getHasSuper(){return hasSuper;}
        int getHeight(){return height;}
        int getWidth(){return width;}
        int getRow(){return row;}
        int getCol(){return col;}
        void fillWindow();
        void refresh();
        void move(int nRow, int nCol);
        void center(Character &ch);
        vector <Location> getImpassable(){return impassable;}

    private:
        int height, width;
        int row, col;
        bool hasSuper;
        bool filled;
        WINDOW * w;
        WINDOW * super;
        vector <string> m;
        vector <Location> impassable;
};

#endif
