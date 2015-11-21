#include "Character.hpp"

Character::Character(char nSymbol, int nColor, int nRow, int nCol)
{
    symbol = nSymbol;
    row = nRow;
    col = nCol;
    color = nColor;
    l.x = row;
    l.y = col;
}

void Character::move(Location L)
{
    l.x = L.x;
    l.y = L.y;
}

void Character::draw(WINDOW * w)
{
    wattron(w,COLOR_PAIR(color));
    mvwaddch(w,l.x,l.y,symbol);
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

bool Character::action(vector <Location> occupied)
{
        if(order == "wander")
        {
            Location L;
            int r = rand()%15+1; 
            if(r==1)
            {
                L.x = l.x+1;
                L.y = l.y;
            }
            else if(r==2)
            {
                L.x = l.x-1;
                L.y = l.y;
            }
            else if(r==3)
            {
                L.x = l.x; L.y = l.y+1;
            }
            else if(r==4)
            {
                L.x = l.x; L.y = l.y-1;
            }
            else if(r==5)
            {
                L.x = l.x+1; L.y = l.y+1;
            }
            else if(r==6)
            {
                L.x = l.x-1; L.y = l.y-1;
            }
            else if(r==7)
            {
                L.x = l.x+1; L.y = l.y-1;
            }
            else if(r==8)
            {    L.x = l.x-1; L.y = l.y+1;
            
            }
            else
                return false;
            
            if(check(L,occupied))
                move(L);
            else
                return false;

            return true;
        }
}

bool Character::check(Location L, vector <Location> occupied)
{
    for(int i = 0; i < 10; i++)
        if(l.x == occupied[i].x && l.y == occupied[i].y)
            return true;
    return true;
}
