#include "Character.hpp"

Character::Character(char nSymbol, int nColor, Location L)
{
    symbol = nSymbol; 
    color = nColor;
    l = L;
}

void Character::draw(WINDOW * w)
{
    wattron(w,COLOR_PAIR(color));
    mvwaddch(w,l.x,l.y,symbol);
}

void Character::action(vector <Character> men)
{
        if(order == "wander")
        {
            Location Lo;
            int r = rand()%15+1; 
            if(r==1)
            {
                Lo.x = l.x+1;
                Lo.y = l.y;
            }
            else if(r==2)
            {
                Lo.x = l.x-1;
                Lo.y = l.y;
            }
            else if(r==3)
            {
                Lo.x = l.x; 
                Lo.y = l.y+1;
            }
            else if(r==4)
            {
                Lo.x = l.x; 
                Lo.y = l.y-1;
            }
            else if(r==5)
            {
                Lo.x = l.x+1; 
                Lo.y = l.y+1;
            }
            else if(r==6)
            {
                Lo.x = l.x-1; 
                Lo.y = l.y-1;
            }
            else if(r==7)
            {
                Lo.x = l.x+1; 
                Lo.y = l.y-1;
            }
            else if(r==8)
            {    
                Lo.x = l.x-1; 
                Lo.y = l.y+1;
            }
            else
                Lo = l;
            
            if(check(Lo,men))
                move(Lo);
        }
}

bool Character::check(Location L, vector <Character> men)
{
    for(int i = 0; i < 10; i++) 
        if(L.x == men[i].getLocation().x && L.y == men[i].getLocation().y)
            return false;

    return true;
}
