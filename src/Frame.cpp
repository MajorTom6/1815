#include "Frame.hpp"

Frame::Frame(string location, int nRow, int nCol)
{
    hasSuper = FALSE;
    super = NULL;

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

void Frame::add(Character &c)
{
    mvwaddch(w,c.getRow(),c.getCol(),c.getSymbol());
}

void Frame::erase(Character &c)
{
    mvwaddch(w,c.getRow(),c.getCol(),' ');
}

void Frame::add(Character &c, int nRow, int nCol)
{
    if((nRow >= 0 && nRow < height) && (nCol >= 0 && nCol < width))
    {
        erase(c);
        mvwaddch(w,nRow,nCol,c.getSymbol());
        c.move(nRow,nCol);
    }
}

void Frame::center(Character &ch)
{
    if(hasSuper)
    {
        int rr = row;
        int cc = col;
        int hh, ww;
        int r = ch.getRow() - height/2;
        int c = ch.getCol() - width/2;

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
    if(!colored)
        for(int i = 0; i < width; i++)
            for(int j = 0; j < height; j++)
            {
                if(m[j][i] == 'O' || m[j][i] == '0')
                    wattron(w,COLOR_PAIR(2));
                else
                    wattron(w,COLOR_PAIR(1));
                mvwaddch(w,j,i,m[j][i]);
            }
    
    wattron(w,COLOR_PAIR(3));
    for(int y = 0; y < height; ++y)
    {      
	mvwaddch(w, y, 0, '-');
	mvwaddch(w, y, width - 1, '-');
    }

    for(int x = 0; x < width; ++x) 
    {
	mvwaddch(w, 0, x, '|');
	mvwaddch(w, height - 1, x, '|');
    }
    wattroff(w,COLOR_PAIR(3));
}

WINDOW * Frame::getWin()
{
    return w;
}

WINDOW * Frame::getSuper()
{
    return super;
}

bool Frame::getHasSuper()
{
    return hasSuper;
}

int Frame::getHeight()
{
    return height;
}

int Frame::getWidth()
{
    return width;
}

int Frame::getRow()
{
    return row;
}

int Frame::getCol()
{
    return col;
}




