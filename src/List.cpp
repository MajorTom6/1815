#include "List.hpp"

List::List()
{
    for(int i = 0; i < 10; i++)
    {
        Character x ('@',4,150,150+i);
        men.push_back(x);
    } 
}

void List::draw(WINDOW * w)
{
    for(int i = 0; i < 10; i++)
        men[i].draw(w);
}
