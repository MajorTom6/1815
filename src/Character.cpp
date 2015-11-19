#include "Character.hpp"

Character::Character(char nSymbol, int nRow, int nCol)
{
    symbol = nSymbol;
    row = nRow;
    col = nCol;
}

void Character::move(int nRow, int nCol)
{
    row = nRow;
    col = nCol;
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
