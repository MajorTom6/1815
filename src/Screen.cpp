#include "Screen.hpp"

Screen::Screen()
{
    initscr();
    clear();
    noecho();
    cbreak();
    keypad(stdscr,TRUE);
    curs_set(0);
    getmaxyx(stdscr,height,width);
}

Screen::~Screen()
{
    endwin();
}

void Screen::ping(string msg)
{   
    const char * cmsg = msg.c_str();
    printw(cmsg);
}

int Screen::getHeight()
{
    return height;
}

int Screen::getWidth()
{
    return width;
}
