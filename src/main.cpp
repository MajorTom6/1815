#include "main.hpp"

int main()
{
    Screen s;

    Frame map("scripts/map.txt",0,0);
    Frame view(map,s.getHeight(),s.getWidth(),0,0);
    List L;

    Character cursor('X',3,map.getHeight()/2,map.getWidth()/2);

    map.fillWindow();
    L.draw(map.getWin());
    cursor.draw(map.getWin());

    while(true)
    {
        char c = getch();
        Location l = cursor.getLocation();
        if	(c == 'h')
            l.y = l.y-1;
        else if	(c == 'l')
            l.y = l.y+1;
        else if	(c == 'k')
            l.x = l.x+1;
        else if	(c == 'j')
            l.x = l.x-1;
        else if	(c == 'q')
            	break;

        cursor.move(l);
        L.action();
        map.fillWindow();
        L.draw(map.getWin());
        cursor.draw(map.getWin());
        view.center(cursor);
    }

    return 0;
}
