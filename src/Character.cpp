#include "Character.hpp"

Character::Character(char nSymbol, int nColor, Location L)
{
    symbol = nSymbol; 
    color = nColor;
    l = L;
    d = Location(100,100);
}

void Character::draw(WINDOW * w)
{
    wattron(w,COLOR_PAIR(color));
    mvwaddch(w,l.x,l.y,symbol);
}

void Character::action(vector <Character> men, vector <Location> impassable)
{
        if(order == "wander")
            wander(men, impassable);
        else if(order == "move")
            heuristic(men,impassable);
}

bool Character::check(Location L, vector <Character> men, vector <Location> impassable)
{
    for(int i = 0; i < men.size(); i++) 
        if(L.x == men[i].getLocation().x && L.y == men[i].getLocation().y)
            return false;
    
    for(int i = 0; i < impassable.size(); i++)
        if(L.x == impassable[i].x && L.y == impassable[i].y)
            return false;
    
    return true;
}

void Character::wander(vector <Character> men, vector <Location> impassable)
{
    vector <Location> possible = getLocal(l,men,impassable);
    int r = rand()%2;
    
    if(r && possible.size())
    { 
        int i = rand() % possible.size();
        move(possible[i]);
    }
}

void Character::heuristic(vector <Character> men, vector <Location> impassable)
{
    vector <Location> open = getLocal(l,men,impassable);  
    
    float v,u;
    Location L;

    if(open.size())
    {
        v = sqrt(pow(open[0].x - d.x,2) + pow(open[0].y - d.y,2));
        L = open[0];
    }
    for(int i = 0; i < open.size(); i++)
    {
        u = sqrt(pow(open[i].x - d.x,2) + pow(open[i].y - d.y,2));
        if (u<v)
        {
            L = open[i];
            v = u;
        }
    }
    move(L);
    if(l.x==d.x && l.y==d.y)
        order="wait";
}

vector <Location> Character::getLocal(Location L, vector <Character> men, vector <Location> impassable)
{
    vector <Location> x;
    Location Lo;

    Lo=Location(L.x+1,L.y);
    if(check(Lo,men,impassable))
        x.push_back(Lo);
    
    Lo=Location(L.x-1,L.y);
    if(check(Lo,men,impassable))
        x.push_back(Lo);

    Lo=Location(L.x,L.y+1);
    if(check(Lo,men,impassable))
        x.push_back(Lo);

    Lo=Location(L.x,L.y-1);
    if(check(Lo,men,impassable))
        x.push_back(Lo);

    Lo=Location(L.x+1,L.y+1);
    if(check(Lo,men,impassable))
        x.push_back(Lo);

    Lo=Location(L.x-1,L.y-1);
    if(check(Lo,men,impassable))
        x.push_back(Lo);

    Lo=Location(L.x+1,L.y-1);
    if(check(Lo,men,impassable))
        x.push_back(Lo);

    Lo=Location(L.x-1,L.y+1);
    if(check(Lo,men,impassable))
        x.push_back(Lo);
    
    return x;
}
