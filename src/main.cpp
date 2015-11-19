#include "main.hpp"

int main()
{
    Screen s;

    Frame map("scripts/map.txt",0,0);
    Frame view(map,s.getHeight(),s.getWidth(),0,0);
    List L;

    Character cursor('X',3,map.getHeight()/2,map.getWidth()/2);

    map.fillWindow();
    cursor.draw(map.getWin());
    //view.center(cursor);
    L.draw(map.getWin());
    view.refresh(); 
    
    while(true)
    {
        char c = getch();

        if	(c == 'h')
		map.add(cursor,cursor.getRow(),cursor.getCol()-1);
        else if	(c == 'l')
            	map.add(cursor,cursor.getRow(),cursor.getCol()+1);
        else if	(c == 'k')
            	map.add(cursor,cursor.getRow()-1,cursor.getCol());
        else if	(c == 'j')
            	map.add(cursor,cursor.getRow()+1,cursor.getCol());
        else if	(c == 'q')
            	break;

        view.center(cursor);
        view.refresh();
        map.fillWindow();
        cursor.draw(map.getWin());
        L.draw(map.getWin());
    }

    return 0;
}
