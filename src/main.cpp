#include "main.hpp"

int main()
{
    Screen s;

    Frame map("scripts/map.txt",0,0);
    Frame view(map,s.getHeight(),s.getWidth(),0,0);
    List L;
    
    Location l;
    l.x =150;
    l.y =150;
    Character cursor('X',3,l);

    map.fillWindow();
    L.draw(map.getWin());
    cursor.draw(map.getWin());
    
    bool paused = false;
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
        else if (c == 'p')
        {
            if  (paused)
            {
                timeout(100);
                paused = false;
            }
            else
            {
                timeout(-1);
                paused = true;
            }
        }
        
        cursor.move(l);
        if (!paused)
            L.action();
        map.fillWindow();
        L.draw(map.getWin());
        cursor.draw(map.getWin());
        view.center(cursor);
    }

    return 0;
}
