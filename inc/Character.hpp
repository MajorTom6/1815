#ifndef character_h
#define character_h

class Character
{
    public:
        Character(char nSymbol, int nRow, int nCol);
        void move(int nRow, int nCol);
        int getRow();
        int getCol();
        char getSymbol();

    private:
        char symbol;
        int row;
        int col;
};

#endif
