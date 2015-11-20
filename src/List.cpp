#include "List.hpp"

List::List()
{
    for(int i = 0; i < 10; i++)
    {
        Character x ('@',4,150,150+i);
        men.push_back(x);
    }
    srand(time(NULL));
}

void List::draw(WINDOW * w)
{
    for(int i = 0; i < 10; i++)
        men[i].draw(w);
}

void List::actions()
{
    for(int i = 0; i < 10; i++)
    {
        int x = men[i].getRow();
        int y = men[i].getCol();
        int r = rand()%15+1;
        if(r==1)
            men[i].move(x+1,y);
        else if(r==2)
            men[i].move(x-1,y);
        else if(r==3)
            men[i].move(x,y+1);
        else if(r==4)
            men[i].move(x,y-1);
        else if(r==5)
            men[i].move(x+1,y+1);
        else if(r==6)
            men[i].move(x-1,y-1);
        else if(r==7)
            men[i].move(x+1,y-1);
        else if(r==8)
            men[i].move(x-1,y+1);
        else
            continue;
    }

}
