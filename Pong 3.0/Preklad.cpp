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

std::vector<std::string> Preklad::nacteni_textu_profil(int v_jazyk)
{
	XMLDocument xmlDoc;

	std::vector<int> vektor_poctu_stringu;

	xmlDoc.LoadFile("Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement("zaklad");

	XMLElement* profil = base->FirstChildElement("profil");
	profil->QueryIntText(&profil_stringu);

	XMLElement* jazyk = root->FirstChildElement("CZ");
	if (v_jazyk == 0)
		jazyk = root->FirstChildElement("CZ");
	if (v_jazyk == 1)
		jazyk = root->FirstChildElement("EN");

	XMLElement* text = jazyk->FirstChildElement("Menu");
	for (int i = 0; i < profil_stringu; i++)
	{
		const char* data = nullptr;
		data = text->Attribute("profil");
		std::string sdata = data;
		vektor_stringu.push_back(sdata);
		text = text->NextSiblingElement("Menu");
	}
	return vektor_stringu;
}
std::vector<std::string> Preklad::nacteni_textu_hlavni(int v_jazyk)
{
	XMLDocument xmlDoc;

	xmlDoc.LoadFile("Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement("zaklad");

	XMLElement* profil = base->FirstChildElement("hlavni");
	profil->QueryIntText(&profil_stringu);

	XMLElement* jazyk = root->FirstChildElement("CZ");
	if (v_jazyk == 0)
		jazyk = root->FirstChildElement("CZ");
	if (v_jazyk == 1)
		jazyk = root->FirstChildElement("EN");

	XMLElement* text = jazyk->FirstChildElement("Menu");
	for (int i = 0; i < profil_stringu; i++)
	{
		const char* data = nullptr;
		data = text->Attribute("hlavni");
		std::string sdata = data;
		vektor_stringu.push_back(sdata);
		text = text->NextSiblingElement("Menu");
	}
	return vektor_stringu;
}
std::vector<std::string> Preklad::nacteni_textu_herni_mody(int v_jazyk)
{
	XMLDocument xmlDoc;

	xmlDoc.LoadFile("Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement("zaklad");

	XMLElement* profil = base->FirstChildElement("herni_mody");
	profil->QueryIntText(&profil_stringu);

	XMLElement* jazyk = root->FirstChildElement("CZ");
	if (v_jazyk == 0)
		jazyk = root->FirstChildElement("CZ");
	if (v_jazyk == 1)
		jazyk = root->FirstChildElement("EN");

	XMLElement* text = jazyk->FirstChildElement("Menu");
	for (int i = 0; i < profil_stringu; i++)
	{
		const char* data = nullptr;
		data = text->Attribute("herni_mody");
		std::string sdata = data;
		vektor_stringu.push_back(sdata);
		text = text->NextSiblingElement("Menu");
	}
	return vektor_stringu;
}
std::vector<std::string> Preklad::nacteni_textu_vzhled_plosiny(int v_jazyk)
{
	XMLDocument xmlDoc;

	xmlDoc.LoadFile("Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement("zaklad");

	XMLElement* profil = base->FirstChildElement("vzhled_plosiny");
	profil->QueryIntText(&profil_stringu);

	XMLElement* jazyk = root->FirstChildElement("CZ");
	if (v_jazyk == 0)
		jazyk = root->FirstChildElement("CZ");
	if (v_jazyk == 1)
		jazyk = root->FirstChildElement("EN");

	XMLElement* text = jazyk->FirstChildElement("Menu");
	for (int i = 0; i < profil_stringu; i++)
	{
		const char* data = nullptr;
		data = text->Attribute("vzhled_plosiny");
		std::string sdata = data;
		vektor_stringu.push_back(sdata);
		text = text->NextSiblingElement("Menu");
	}
	return vektor_stringu;
}
std::vector<std::string> Preklad::nacteni_textu_nastaveni(int v_jazyk)
{
	XMLDocument xmlDoc;

	xmlDoc.LoadFile("Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement("zaklad");

	XMLElement* profil = base->FirstChildElement("nastaveni");
	profil->QueryIntText(&profil_stringu);

	XMLElement* jazyk = root->FirstChildElement("CZ");
	if (v_jazyk == 0)
		jazyk = root->FirstChildElement("CZ");
	if (v_jazyk == 1)
		jazyk = root->FirstChildElement("EN");

	XMLElement* text = jazyk->FirstChildElement("Menu");
	for (int i = 0; i < profil_stringu; i++)
	{
		const char* data = nullptr;
		data = text->Attribute("nastaveni");
		std::string sdata = data;
		vektor_stringu.push_back(sdata);
		text = text->NextSiblingElement("Menu");
	}
	return vektor_stringu;
}
std::vector<std::string> Preklad::nacteni_textu_ovladani(int v_jazyk)
{
	XMLDocument xmlDoc;



	xmlDoc.LoadFile("Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement("zaklad");

	XMLElement* profil = base->FirstChildElement("ovladani");
	profil->QueryIntText(&profil_stringu);

	XMLElement* jazyk = root->FirstChildElement("CZ");
	if (v_jazyk == 0)
		jazyk = root->FirstChildElement("CZ");
	if (v_jazyk == 1)
		jazyk = root->FirstChildElement("EN");

	XMLElement* text = jazyk->FirstChildElement("Menu");
	for (int i = 0; i < profil_stringu; i++)
	{
		const char* data = nullptr;
		data = text->Attribute("ovladani");
		std::string sdata = data;
		vektor_stringu.push_back(sdata);
		text = text->NextSiblingElement("Menu");
	}
	return vektor_stringu;
}
std::vector<std::string> Preklad::nacteni_textu_konec_kola(int v_jazyk)
{
	XMLDocument xmlDoc;



	xmlDoc.LoadFile("Preklad.xml");

	XMLNode* root = xmlDoc.FirstChild();
	XMLElement* base = root->FirstChildElement("zaklad");

	XMLElement* profil = base->FirstChildElement("konec");
	profil->QueryIntText(&profil_stringu);

	XMLElement* jazyk = root->FirstChildElement("CZ");
	if (v_jazyk == 0)
		jazyk = root->FirstChildElement("CZ");
	if (v_jazyk == 1)
		jazyk = root->FirstChildElement("EN");

	XMLElement* text = jazyk->FirstChildElement("Menu");
	for (int i = 0; i < profil_stringu; i++)
	{
		const char* data = nullptr;
		data = text->Attribute("konec");
		std::string sdata = data;
		vektor_stringu.push_back(sdata);
		text = text->NextSiblingElement("Menu");
	}
	return vektor_stringu;
}