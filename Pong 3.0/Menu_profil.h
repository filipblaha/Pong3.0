#pragma once
#include "Menu.h"
class Menu_profil : public Menu
{
    public:
    Commands set;

    Menu_profil() : Menu(profil_e, 10, 8, 8, 17)
    {
        vykresleni_profil();
    }
    void vykresleni_profil();
};

