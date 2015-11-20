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

        if	(c == 'h')
		cursor.move(cursor.getRow(),cursor.getCol()-1);
        else if	(c == 'l')
            	cursor.move(cursor.getRow(),cursor.getCol()+1);
        else if	(c == 'k')
            	cursor.move(cursor.getRow()-1,cursor.getCol());
        else if	(c == 'j')
            	cursor.move(cursor.getRow()+1,cursor.getCol());
        else if	(c == 'q')
            	break; 

        map.fillWindow();
        L.draw(map.getWin());
        cursor.draw(map.getWin());
        view.center(cursor);
    }

    return 0;
}
