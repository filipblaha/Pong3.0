#include <iostream>
#include <conio.h>
int vstup()
{
    switch (_getch())
    {
    case 'h':
            return 0;
    case 'g':
        return 1;
    case 'j':
        return 2;
    default:
        break;
    }
}
int main()
{
    while(1)
    {
        switch (vstup())
        {
        case 0:
            std::cout << 's';
            break;

        case 1:
            std::cout << 'a';
            break;

        case 2:
            std::cout << 'x';
            break;
        default:
            break;
        }
    }
}