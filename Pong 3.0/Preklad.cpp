#include "Preklad.h"
/*
	XMLElement* hlavni = base->FirstChildElement("hlavni");
	profil->QueryIntText(&hlavni_stringu);
	XMLElement* herni_mody = base->FirstChildElement("herni_mody");
	profil->QueryIntText(&herni_mody_stringu);
	XMLElement* vzhled_plosiny = base->FirstChildElement("vzhled_plosiny");
	profil->QueryIntText(&vzhled_plosiny_stringu);
	XMLElement* nastaveni = base->FirstChildElement("nastaveni");
	profil->QueryIntText(&nastaveni_stringu);
	XMLElement* ovladani = base->FirstChildElement("ovladani");
	profil->QueryIntText(&ovladani_stringu);
	XMLElement* konec_kola = base->FirstChildElement("konec_kola");
	profil->QueryIntText(&konec_kola_stringu);*/

std::vector<const char*> Preklad::nacteni_textu_profil(int v_jazyk)
{
	XMLDocument xmlDoc;

	std::vector<int> vektor_poctu_stringu;

	std::vector<const char*> vektor_stringu;

	xmlDoc.LoadFile("Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement("zaklad");

	XMLElement* profil = base->FirstChildElement("profil");
	profil->QueryIntText(&profil_stringu);

	XMLElement* jazyk = root->FirstChildElement("CZ");;
	if (v_jazyk == 0)
		jazyk = root->FirstChildElement("CZ");
	if (v_jazyk == 1)
		jazyk = root->FirstChildElement("EN");

	for (int i = 0; i < profil_stringu; i++)
	{
		XMLElement* text = jazyk->FirstChildElement("p0");
		const char* data;
		text->QueryAttribute("data", &data); //tady sem seklej
		vektor_stringu.push_back(data);
		text = text->NextSiblingElement("p0");
	}

	return vektor_stringu;
}