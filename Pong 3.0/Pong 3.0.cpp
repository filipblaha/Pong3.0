#include <iostream>
#include <vector>
#include <conio.h>

#ifndef WIN32_LEAN_AND_MEAN // xml a windows.h nejdou do sebe, tohle to vyresi
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>
#include <Winuser.h> // lepsi ovladani


#include <fcntl.h>
#include <io.h> // graficke knihovny

#include "Menu_profil.h"
#include "Menu_hlavni.h"
#include "Menu.h"
//#include "Pong.h"

bool menu_hlavni()
{
	Menu hlavni_menu();
	return 0;
	/*while (!profil.exit)
	{
	}*/
}
bool menu_profil()
{
	Menu_profil profil;

	bool jazyk_profil = profil.jazyk; // odstran

	while(1)
	{
		switch (profil.vstup_menu(profil.profil_e))
		{
		case profil.enter:
		{
			{
				if (profil.rozhodovac(profil.profil_e, profil.enter) == 1)
				{
					while (menu_hlavni())
					{
						profil.ukladani_profilu();
					}
				}
			}
			break;
		}
		case profil.del:
		{
			{
				profil.vykresleni_otazka();
				while (!_kbhit()); // ?

				if (profil.vstup_menu(profil.profil_e) == profil.enter)
				{
					profil.rozhodovac(profil.profil_e, profil.del);

					if (profil.pouzit == 0)
					{
						profil.vykresleni_nazev_profilu();
						profil.nacteni_vyberu_profilu();
						profil.pojmenovani_profilu();
						profil.ulozeni_vyberu_profilu();
					}
				}
				profil.smazani_otazka();
			}
			break;
		}
		case profil.exit:
		{
			return 0;
		}
		default:
		{
			profil.vykresleni_oznaceni();
		}
		break;
		}
	}
}

int main()
{
	while (menu_profil());
}