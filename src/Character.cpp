#include "Character.hpp"

Character::Character(char nSymbol, int nColor, int nRow, int nCol)
{
    symbol = nSymbol;
    row = nRow;
    col = nCol;
    color = nColor;
}

void Character::move(int nRow, int nCol)
{
    row = nRow;
    col = nCol;
}

void Character::draw(WINDOW * w)
{
    wattron(w,COLOR_PAIR(color));
    mvwaddch(w,row,col,symbol);
}

int Character::getRow()
{
    return row;
}

int Character::getCol()
{
    return col;
}

char Character::getSymbol()
{
    return symbol;
}
