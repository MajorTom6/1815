#ifndef window_h
#define window_h

#include <string>
#include "ncurses.h"

using namespace std;

class Screen
{
    public:
        Screen();
        ~Screen();
        void ping(string msg);
        int getHeight();
        int getWidth();
    private:
        int height, width;
};

#endif
