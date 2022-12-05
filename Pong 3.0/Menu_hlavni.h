#pragma once
#include "Menu.h"
class Menu_hlavni : public Menu
{
public:

	Menu_hlavni() : Menu (profil_e, 10, 8, 8, 17)
	{
		vykresleni_hlavni();
		vykresleni_logo();
	}
	void vykresleni_hlavni();
	void vykresleni_logo();
};

