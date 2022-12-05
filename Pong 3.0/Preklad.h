#pragma once
#include <iostream>
#include <vector>
#include "tinyxml2.h"

using namespace tinyxml2;
class Preklad
{
public:

	int profil_stringu = 0;
	int hlavni_stringu = 0;
	int herni_mody_stringu = 0;
	int vzhled_plosiny_stringu = 0;
	int nastaveni_stringu = 0;
	int ovladani_stringu = 0;
	int konec_kola_stringu = 0;

	std::vector<const char*> vektor_stringu;

	std::vector<const char*> nacteni_textu_profil(int jazyk);

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
};

