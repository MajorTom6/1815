#include "List.hpp"

List::List()
{
    for(int i = 0; i < 10; i++)
    {
        Character x ('@',4,150,150+i);
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
        if(men[i].action(occupied))
        {
            //rows[i] = 0;
            //cols[i] = 0;
        }
}
