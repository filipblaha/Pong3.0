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

	std::vector<std::string> vektor_stringu;

	std::vector<std::string> nacteni_textu_profil(int jazyk);
	std::vector<std::string> nacteni_textu_hlavni(int jazyk);
	std::vector<std::string> nacteni_textu_herni_mody(int jazyk);
	std::vector<std::string> nacteni_textu_vzhled_plosiny(int jazyk);
	std::vector<std::string> nacteni_textu_nastaveni(int jazyk);
	std::vector<std::string> nacteni_textu_ovladani(int jazyk);
	std::vector<std::string> nacteni_textu_konec_kola(int jazyk);
};

