#ifndef character_h
#define character_h

#include <ncurses.h>

class Character
{
    public:
        Character(char nSymbol, int nColor,int nRow, int nCol);
        void move(int nRow, int nCol);
        void draw(WINDOW * w);
        int getRow();
        int getCol();
        char getSymbol();

    private:
        char symbol;
        int row;
        int col;
        int color;
};

#endif
