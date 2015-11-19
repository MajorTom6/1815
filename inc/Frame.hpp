#ifndef frame_h
#define frame_h

#include <ncurses.h>
#include "Character.hpp"
#include <string>
#include <fstream>


class Frame
{
    public:
        //Frame(int rows, int cols, int nRow, int nCol); // main window test
        Frame(string location, int nRow, int nCol); // main window with seeded map
        Frame(Frame &super, int rows, int cols, int nRow, int nCol); // viewport
        ~Frame();
        WINDOW * getWin();
        WINDOW * getSuper();
        bool getHasSuper();
        int getHeight();
        int getWidth();
        int getRow();
        int getCol();
        void fillWindow();
        void refresh();
        void move(int nRow, int nCol);
        void add(Character &c);
        void add(Character &c, int nRow, int nCol);
        void erase(Character &c);
        void center(Character &ch);

    private:
        int height, width;
        int row, col;
        bool hasSuper;
        WINDOW * w;
        WINDOW * super;
        string m;
};

#endif
