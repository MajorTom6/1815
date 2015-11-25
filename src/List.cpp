#include "List.hpp"

List::List(vector <Location> i)
{
    for(int i = 0; i < 3; i++)
    {
        Location L;
        L.x = 150;
        L.y = 150+i;
        Character x ('@',4,L);
        men.push_back(x); 
    } 
    impassable = i;
}

void List::draw(WINDOW * w)
{
    for(int i = 0; i < men.size(); i++)
        men[i].draw(w);
}

void List::action()
{
    for(int i = 0; i < men.size(); i++)
        men[i].action(men,impassable);
}
