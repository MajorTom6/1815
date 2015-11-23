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
        men[i].action(men);
}
