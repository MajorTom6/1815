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

void Character::action(vector <Character> men, vector <Location> impassable)
{
        if(order == "wander")
        { 
            int r = rand()%15+1; 
            bool stay = false;
            Location L;
            if(r==1)
                L = Location(l.x+1,l.y);
            else if(r==2)
                L = Location(l.x-1,l.y);
            else if(r==3)
                L = Location(l.x,l.y+1);
            else if(r==4)
                L = Location(l.x,l.y-1);
            else if(r==5)
                L = Location(l.x+1,l.x+1);
            else if(r==6)
                L = Location(l.x-1,l.y-1);
            else if(r==7)
                L = Location(l.x+1,l.y-1);
            else if(r==8)
                L = Location(l.x-1,l.y+1);
            else
                stay = true;
            
            if (!stay)
                if(check(L,men,impassable))
                    move(L);
        }
}

bool Character::check(Location L, vector <Character> men, vector <Location> impassable)
{
    for(int i = 0; i < men.size(); i++) 
        if(L.x == men[i].getLocation().x && L.y == men[i].getLocation().y)
            return false;
    
    for(int i = 0; i < impassable.size(); i++)
        if(L.x == impassable[i].x && L.y == impassable[i].y)
            return false;
    
    return true;
}
