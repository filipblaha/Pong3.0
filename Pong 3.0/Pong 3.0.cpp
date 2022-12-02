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

#include "Menu.h"
//#include "Pong.h"

enum menu_strana
{
	start,
	profil,
	hlavni,
	herni_mody,
	vzhled_plosiny,
	nastaveni,
	ovladani,
};

void menu_hlavni()
{

}
void menu_profil()
{
	Menu vyber_profil(profil, 10, 8, 8, 17);

	bool jazyk_profil = vyber_profil.jazyk; // odstran


	while (!vyber_profil.exit)
	{
		vyber_profil.vykresleni_oznaceni();
		while (!_kbhit());
		vyber_profil.vstup_menu(profil);
		vyber_profil.smazani_oznaceni();

		if (vyber_profil.enter || vyber_profil.del)
		{
			if (vyber_profil.del)
			{
				vyber_profil.vykresleni_otazka();
				while (!_kbhit());
				vyber_profil.vstup_menu(profil);
				vyber_profil.smazani_otazka();
			}
			if (vyber_profil.rozhodovac(profil) == 1)
			{
				if (vyber_profil.enter)
				{
					if (vyber_profil.pouzit == 0)
					{
						if (jazyk_profil != vyber_profil.jazyk)
							vyber_profil.jazyk = jazyk_profil;

						vyber_profil.vykresleni_nazev_profilu();
						vyber_profil.nacteni_vyberu_profilu();
						vyber_profil.pojmenovani_profilu();
						vyber_profil.ulozeni_vyberu_profilu();
					}
					while (vyber_profil.program)
					{
						menu_hlavni();
						vyber_profil.ukladani_profilu();
						vyber_profil.ulozeni_vyberu_profilu(); // je potreba?
						vyber_profil.exit = 1;
					}
				}
			}
			else
			{
				vyber_profil.exit = 1;
			}
			vyber_profil.ulozeni_vyberu_profilu();
		}
	}
}

int main()
{
	Menu zacatek(start);
	while (zacatek.program)
	{
		menu_profil();
	}
}