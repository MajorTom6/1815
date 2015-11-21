#include "List.hpp"

List::List()
{
    for(int i = 0; i < 10; i++)
    {
        Location L;
        L.x = 150;
        L.y = 150+i;
        Character x ('@',4,L);
        men.push_back(x);
        occupied.push_back(x.getLocation()); 
    } 
}

void List::draw(WINDOW * w)
{
    for(int i = 0; i < 10; i++)
        men[i].draw(w);
}

void List::action()
{
    for(int i = 0; i < 10; i++)
    {
        Location L = men[i].action(occupied);
        if (L.x != 0 && L.y != 0)
            occupied[i]=L;
    }
}
