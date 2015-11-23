#include "Frame.hpp"

Frame::Frame(string location, int nRow, int nCol)
{
    hasSuper = FALSE;
    super = NULL;
    filled = false;
    int i, j=0;
    string line;
    ifstream file (location);

    if(file.is_open())
    {
        getline(file,line);
        m.push_back(line);
        i=line.length();
        while(getline(file,line))
        {
            m.push_back(line);
            j++;
        }
    }

    w = newwin(j,i,nRow,nCol);
    height = j;
    width = i;
    row = nRow;
    col = nCol; 
}


Frame::Frame(Frame &sw, int rows, int cols, int nRow, int nCol)
{
    filled = false;
    hasSuper = TRUE;
    super = sw.getWin();
    w = derwin(super,rows,cols,nRow,nCol);
    height = rows;
    width = cols;
    row = nRow;
    col = nCol;
}

Frame::~Frame()
{
    delwin(w);
}

void Frame::center(Character &ch)
{
    if(hasSuper)
    {
        int rr = row;
        int cc = col;
        int hh, ww;
        int r = ch.getLocation().x - height/2;
        int c = ch.getLocation().y - width/2;

        getmaxyx(super, hh, ww);

        if(c + width >= ww)
        {
            int delta = ww - (c + width);
            cc = c + delta;
        }
        else
            cc = c;
        
        if(r + height >= hh)
        {
            int delta = hh - (r + height);
            rr = r + delta;
        }
        else
            rr = r;
        
        if(r < 0)
            rr = 0;
        
        if(c < 0)
            cc = 0;

        move(rr,cc);
    }
}

void Frame::refresh()
{
    if(hasSuper)
        touchwin(super);
    wrefresh(w);
}

void Frame::move(int nRow, int nCol)
{
    if(hasSuper)
    {
        mvderwin(w,nRow,nCol);
        row = nRow;
        col = nCol;
        refresh();
    }
}

void Frame::fillWindow()
{ 
    
    for(int i = 0; i < width; i++)
        for(int j = 0; j < height; j++)
        {
            if(m[j][i] == 'O' || m[j][i] == '0')
            {
                wattron(w,COLOR_PAIR(2));
                if(!filled)
                {
                    Location l(j,i);
                    impassable.push_back(l);
                }
            }
            else
                wattron(w,COLOR_PAIR(1));
    
            mvwaddch(w,j,i,m[j][i]);
        }
    
    wattron(w,COLOR_PAIR(3));
    for(int y = 0; y < height; ++y)
    {      
	mvwaddch(w, y, 0, '-');
	mvwaddch(w, y, width - 1, '-');
        if(!filled)
        {
            Location l1(y,0);
            Location l2(y,width-1);
            impassable.push_back(l1);
            impassable.push_back(l2);
        }
    }

    for(int x = 0; x < width; ++x) 
    {
	mvwaddch(w, 0, x, '|');
	mvwaddch(w, height - 1, x, '|');
        if(!filled)
        {
            Location l1(0,x);
            Location l2(height-1,x);
            impassable.push_back(l1);
            impassable.push_back(l2);
        }
    }
    wattroff(w,COLOR_PAIR(3));
    filled = true;
}
