#pragma once
#include <iostream>
#include <vector>
#include <conio.h>

#ifndef WIN32_LEAN_AND_MEAN // xml a windows.h nejdou do sebe, tohle to vyresi
#define WIN32_LEAN_AND_MEAN
#endif

#include <Windows.h>
#include <fcntl.h>
#include <io.h> // graficke knihovny

#include "Profily.h"
#include "Plosina.h"
#include "Commands.h"


class Menu
{
public:
	Plosina plosina;
	Commands set;

	const int delka_menu = 40;
	const int vyska_menu = 20;

	////////    Oznaceni     ////////
	std::vector<int> oznaceni;
	std::vector<int> zavory;

	enum vstup
	{
		exit,
		enter,
		del,
	};
	bool pokracovani = 0;
	bool reset = 0;
	bool pouzit = 0;
	bool jazyk = 0;

	enum menu_strana
	{
		profil_e,
		hlavni_e,
		herni_mody_e,
		vzhled_plosiny_e,
		nastaveni_e,
		ovladani_e,
	};

	Menu(int strana, int x = 0, int y = 0, int horni_z = 0, int dolni_z = 0, int leva_z = 0, int prava_z = 0)
	{
		oznaceni.push_back(x);
		oznaceni.push_back(y);

		zavory.push_back(horni_z);
		zavory.push_back(dolni_z);
		zavory.push_back(leva_z);
		zavory.push_back(prava_z);

		_setmode(_fileno(stdout), _O_U16TEXT);
		set.prechod();
		set.font(0, 20);
		set.SetWindow(delka_menu, vyska_menu - 2);
		nacteni_vyberu_profilu();
		vektor_na_string(nazev_profil0, nazev_profil1, nazev_profil2);
		vykresleni_menu_start();
		vykresleni_oznaceni();
	}

	void vykresleni_oznaceni();
	void smazani_oznaceni();

	void vykresleni_otazka();
	void smazani_otazka();
	void vykresleni_nazev_profilu();

	void pojmenovani_profilu();
	void vyber_profilu(int vybrany_profil);
	int ukladani_profilu();
	int nacteni_vyberu_profilu();
	int ulozeni_vyberu_profilu();

	int vstup_menu(int strana);
	int rozhodovac(int strana, int prikaz);
	

	////////    Profily    ////////
	std::vector<char> nazev_profil0;
	std::vector<char> nazev_profil1;
	std::vector<char> nazev_profil2;
	std::vector<char> nazev_profil_novy;
	std::vector<char> vytvoreni_noveho_nazvu_profilu();

	////////    Custom skin   ///////
	std::vector<char> pole_skin;

	////////    Level bar   ///////
	std::vector<int> docas;
	std::vector<int> exp_pole;

	void level_bar();

	/////////////////////    Vykresleni     //////////////////////////

	void vykresleni_menu_start();
	void vykresleni_uroven();

	/////////////////////    Input od uzivatele     //////////////////////////

	void custom_skin();
	std::vector<char> string_na_vektor(std::string nazev);
	void vektor_na_string(std::vector<char> p0, std::vector<char> p1, std::vector<char> p2);

	/////////////////////    Nazvy profilu     //////////////////////////

	std::string pojmenovani;

	std::wstring novy_profil = L"Novy_profil";
	std::wstring muj_profil0;
	std::wstring muj_profil1;
	std::wstring muj_profil2;

	/////////////////////    Preklad CZ    //////////////////////////

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

	/////////////////////    Translate EN    //////////////////////////

	///////  Profile  //////
	std::wstring vyber_profiluEN = L"Choose your profile";
	std::wstring profil1EN = L"Profile 1";
	std::wstring profil2EN = L"Profile 2";
	std::wstring profil3EN = L"Profile 3";
	std::wstring smazani_pokrokEN = L"Delete progress";
	std::wstring smazani_pokrok_otazka1EN = L"Do you want to delete progress?";
	std::wstring smazani_pokrok_otazka2EN = L"[ENTER]";
	std::wstring profil_nazevEN = L"Enter a profile name";

	///////  Main menu  //////
	std::wstring herni_modyEN = L"Game modes";
	std::wstring vzhled_plosinyEN = L"Skins";
	std::wstring nastaveniEN = L"Settings";
	std::wstring verzeEN = L"version ";

	///////  Game modes  //////
	std::wstring HERNI_MODYEN = L"GAME MODES";
	std::wstring klasikEN = L"Classic";
	std::wstring rogue_likeEN = L"Rogue like - zatim nefunkcni";
	std::wstring stejne_tvaryEN = L"Hit the same color - zatim nefunkcni";
	std::wstring bloky_padajiEN = L"Falling blocks";

	///////  Skins  //////
	std::wstring VZHLED_PLOSINYEN = L"SKINS";
	std::wstring neodemcenoEN = L"Unlocks after level ";

	///////  Settings  //////
	std::wstring NASTAVENIEN = L"SETTINGS";
	std::wstring jazykEN = L"Language";
	std::wstring ceskyEN = L"Czech";
	std::wstring anglickyEN = L"English";
	std::wstring ovladaniEN = L"Controls";

	///////  Controls  //////
	std::wstring OVLADANIEN = L"CONTROLS";
	std::wstring ovladani_menuEN = L"Menu controls";
	std::wstring ovladani_hraEN = L"In-game controls";
	std::wstring ovladani_enterEN = L"Enter";
	std::wstring ovladani_mezernikEN = L"Spacebar";
	std::wstring ovladani_schopnostEN = L"Use ability";
	std::wstring ovladani_pohyb_vlevoEN = L"Movement - left";
	std::wstring ovladani_pohyb_vpravoEN = L"Movement - right";
	std::wstring ovladani_pauzaEN = L"Pause";

	///////  End of a round  //////
	std::wstring odchodP1EN = L"Try again.";
	std::wstring odchodV1EN = L"YOU'VE WON!";
	std::wstring odchod2EN = L"Restart [SPACEBAR]";
	std::wstring odchod3EN = L"Menu [Q]";
	std::wstring odchod4EN = L"BEST TIME: ";
	std::wstring odchodV5EN = L"Your time: ";
	std::wstring odchodP5EN = L"Blocks left: ";
	std::wstring odchod6EN = L"Level ";
	std::wstring odchod7EN = L"Blocks destroyed: ";
	std::wstring odchod8EN = L"HIGHSCORE: ";
private:

	int plosina_skin = 0;

	//////////    Ukladani do profilu     ////////
	int highscore_cas = 0;
	int highscore_znicenych_bloku = 0;
	int n_exp = 0;
	int exp = 0;
	int level = 0;

	int pohyb_vlevo = 65;
	int pohyb_vpravo = 68;
	int pouziti_schopnosti = 32;
	int pauza = 27;

	int profil_probiha = 0;
	int uroven_profil0 = 0;
	int uroven_profil1 = 0;
	int uroven_profil2 = 0;

	int pocet_zivotu = 2;
	int potr_urov1 = 1;
	int potr_urov2 = 2;
	int potr_urov3 = 3;
	int potr_urov4 = 4;
	int potr_urov5 = 5;

};

