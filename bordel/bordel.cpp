#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <Windows.h>
#include <fcntl.h>
#include <io.h> // graficke knihovny
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
	///////  Profil  //////
	std::wstring vyber_profiluCZ = L"Vyber si svuj profil";
	std::wstring profil1CZ = L"Profil 1";
	std::wstring profil2CZ = L"Profil 2";
	std::wstring profil3CZ = L"Profil 3";
	std::wstring smazani_pokrokCZ = L"Smazat pokrok";
	std::wstring smazani_pokrok_otazka1CZ = L"Opravdu chcete smazat pokrok?";
	std::wstring smazani_pokrok_otazka2CZ = L"[ENTER]";
	std::wstring profil_nazevCZ = L"Zadej nazev profilu";

	///////  Hlavni menu  //////
	std::wstring herni_modyCZ = L"Herni mody";
	std::wstring vzhled_plosinyCZ = L"Vzhled plosiny";
	std::wstring nastaveniCZ = L"Nastaveni";
	std::wstring verzeCZ = L"verze ";

	///////  Herni mody  //////
	std::wstring HERNI_MODYCZ = L"HERNI MODY";
	std::wstring klasikCZ = L"Klasik";
	std::wstring rogue_likeCZ = L"Rogue like - zatim nefunkcni";
	std::wstring stejne_tvaryCZ = L"Stejne tvary - zatim nefunkcni";
	std::wstring bloky_padajiCZ = L"Bloky padaji";

	///////  Vzhled plosiny  //////
	std::wstring VZHLED_PLOSINYCZ = L"VZHLED PLOSINY";
	std::wstring neodemcenoCZ = L"Odemkne se na urovni  ";

	///////  Nastaveni  //////
	std::wstring NASTAVENICZ = L"NASTAVENI";
	std::wstring ovladaniCZ = L"Ovladani";
	std::wstring jazykCZ = L"Jazyk";
	std::wstring ceskyCZ = L"Cesky";
	std::wstring anglickyCZ = L"Anglicky";

	///////  Ovladani  //////
	std::wstring OVLADANICZ = L"OVLADANI";
	std::wstring ovladani_menuCZ = L"Ovladani v menu";
	std::wstring ovladani_hraCZ = L"Ovladani ve hre";
	std::wstring ovladani_enterCZ = L"Enter";
	std::wstring ovladani_mezernikCZ = L"Mezernik";
	std::wstring ovladani_schopnostCZ = L"Pouzit schopnost";
	std::wstring ovladani_pohyb_vlevoCZ = L"Pohyb - vlevo";
	std::wstring ovladani_pohyb_vpravoCZ = L"Pohyb - vpravo";
	std::wstring ovladani_pauzaCZ = L"Pauza";

	///////  Konec kola  //////
	std::wstring odchodP1CZ = L"Zkus to znovu.";
	std::wstring odchodV1CZ = L"VYHRAL JSI!";
	std::wstring odchod2CZ = L"Restart[MEZERNIK]";
	std::wstring odchod3CZ = L"Menu[Q]";
	std::wstring odchod4CZ = L"NEJLEPSI CAS: ";
	std::wstring odchodV5CZ = L"Dosazeny cas: ";
	std::wstring odchodP5CZ = L"Bloku zbylo: ";
	std::wstring odchod6CZ = L"Uroven ";
	std::wstring odchod7CZ = L"Bloku zniceno: ";
	std::wstring odchod8CZ = L"NEJVICE ZNICENYCH BLOKU: ";


	std::vector<std::wstring> v;
	v.push_back(vyber_profiluCZ);
	v.push_back(profil1CZ);
	v.push_back(profil2CZ);
	v.push_back(profil3CZ);
	v.push_back(smazani_pokrokCZ);
	v.push_back(smazani_pokrok_otazka1CZ);
	v.push_back(smazani_pokrok_otazka2CZ);
	v.push_back(profil_nazevCZ);

	///////  Hlavni menu  //////
	v.push_back(herni_modyCZ);
	v.push_back(vzhled_plosinyCZ);
	v.push_back(nastaveniCZ);
	v.push_back(verzeCZ);

	///////  Herni mody  //////
	v.push_back(HERNI_MODYCZ);
	v.push_back(klasikCZ);
	v.push_back(rogue_likeCZ);
	v.push_back(stejne_tvaryCZ);
	v.push_back(bloky_padajiCZ);

	///////  Vzhled plosiny  //////
	v.push_back(VZHLED_PLOSINYCZ);
	v.push_back(neodemcenoCZ);

	///////  Nastaveni  //////
	v.push_back(NASTAVENICZ);
	v.push_back(ovladaniCZ);
	v.push_back(jazykCZ);
	v.push_back(ceskyCZ);
	v.push_back(anglickyCZ);

	///////  Ovladani  //////
	v.push_back(OVLADANICZ);
	v.push_back(ovladani_menuCZ);
	v.push_back(ovladani_hraCZ);
	v.push_back(ovladani_enterCZ);
	v.push_back(ovladani_mezernikCZ); 
	v.push_back(ovladani_schopnostCZ);
	v.push_back(ovladani_pohyb_vlevoCZ); 
	v.push_back(ovladani_pohyb_vpravoCZ); 
	v.push_back(ovladani_pauzaCZ); 

	///////  Konec kola  //////
	v.push_back(odchodP1CZ); 
	v.push_back(odchodV1CZ); 
	v.push_back(odchod2CZ);
	v.push_back(odchod3CZ); 
	v.push_back(odchod4CZ);
	v.push_back(odchodV5CZ); 
	v.push_back(odchodP5CZ); 
	v.push_back(odchod6CZ);
	v.push_back(odchod7CZ);
	v.push_back(odchod8CZ);
    for (size_t i = 0; i < 43; i++)
    {
		int k = 0;
		if (i > 7)
			k = 1;
		if (i > 11)
			k = 2;
		if (i > 16)
			k = 3;
		if (i > 18)
			k = 4;
		if (i > 23)
			k = 5;
		if (i > 34)
			k = 6;
        std::wcout << "<p" << k << '>' << v.at(i) << "</p" << k << ">\n";
    }
}