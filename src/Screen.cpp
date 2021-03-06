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
    timeout(100);

    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW,COLOR_BLACK);
    init_pair(3, COLOR_WHITE, COLOR_WHITE);
    init_pair(4, COLOR_WHITE, COLOR_BLUE);
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
