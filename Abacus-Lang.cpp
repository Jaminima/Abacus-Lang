#include <iostream>

const unsigned int LeftStart = 10;
const unsigned int Rows = 32;

const char* Instructions = ">>R<]";

class Rod {
public:
    int Left = LeftStart;
    int Right = 0;
};

Rod Rods[Rows];
unsigned int R = 0;

void GotoEndLoop(unsigned int& i) {
    unsigned int Open = 1;
    while (Open > 0) {
        i++;
        if (Instructions[i] == ']') Open--;
        else if (Instructions[i] == 'L' || Instructions[i] == 'R') Open++;
    }
}

void GotoStartLoop(unsigned int& i) {
    unsigned int Open = 1;
    while (Open > 0) {
        i--;
        if (Instructions[i] == ']') Open++;
        else if (Instructions[i] == 'L' || Instructions[i] == 'R') Open--;
    }
    i--;
}

void DoExec()
{
    unsigned int i = 0;

    char C = Instructions[i];

    while (C != 0x0) {

        switch (C)
        {

        case '>':
            if (Rods[R].Left > 0) {
                Rods[R].Left--;
                Rods[R].Right++;
            }
            break;

        case '<':
            if (Rods[R].Right > 0) {
                Rods[R].Right--;
                Rods[R].Left++;
            }
            break;

        case 'D':
            if (R < Rows) {
                R++;
            }
            break;

        case 'U':
            if (R > 0) {
                R--;
            }
            break;

        case 'L':
            if (Rods[R].Left == 0) GotoEndLoop(i);
            break;

        case 'R':
            if (Rods[R].Right == 0) GotoEndLoop(i);
            break;

        case ']':
            GotoStartLoop(i);
            break;

        }

        i++;
        C = Instructions[i];
    }
}

int main()
{
    DoExec();
}