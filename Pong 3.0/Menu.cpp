#include "Menu.h"

Plosina plosina;
Commands set;

void Menu::vykresleni_oznaceni()
{
	set.setCursorPosition(oznaceni.at(0), oznaceni.at(1));
	std::wcout << L"\x25ba";
}
void Menu::smazani_oznaceni()
{
	set.setCursorPosition(oznaceni.at(0), oznaceni.at(1));
	std::wcout << ' ';
}

void Menu::vykresleni_otazka()
{
	set.setCursorPosition(5, 2);
	if (!jazyk)
		std::wcout << smazani_pokrok_otazka1CZ;
	if (jazyk)
		std::wcout << smazani_pokrok_otazka1EN;
	set.setCursorPosition(26, 3);
	if (!jazyk)
		std::wcout << smazani_pokrok_otazka2CZ;
	if (jazyk)
		std::wcout << smazani_pokrok_otazka2EN;
}
void Menu::smazani_otazka()
{
	set.setCursorPosition(5, 2);
	std::wcout << "                               ";
	set.setCursorPosition(26, 3);
	std::wcout << "       ";
}
void Menu::vykresleni_nazev_profilu()
{
	for (int j = 8; j < 13; j++)
	{
		set.setCursorPosition(9, j);
		for (int i = 0; i < 22; i++)
		{
			std::wcout << ' ';
		}
	}
	set.setCursorPosition(10, 8);
	if (!jazyk)
		std::wcout << profil_nazevCZ;
	if (jazyk)
		std::wcout << profil_nazevEN;
}

/////////////////////    Profily     //////////////////////////
void Menu::pojmenovani_profilu()
{
	set.setCursorPosition(10, 10);
	std::cin >> pojmenovani;
	string_na_vektor(pojmenovani);
}
void Menu::vyber_profilu(int vybrany_profil)
{
	if (vybrany_profil == 0)
	{
		profil_probiha = 0;

		profil0 profil;
		profil.nacteni_profilu();
		pouzit = profil.pouzit_s;
		jazyk = profil.jazyk_s;
		plosina_skin = profil.plosina_skin_s;
		highscore_cas = profil.highscore_cas_s;
		highscore_znicenych_bloku = profil.highscore_znicenych_bloku_s;
		level = profil.level_s;
		exp = profil.exp_s;
		pohyb_vlevo = profil.pohyb_vlevo_s;
		pohyb_vpravo = profil.pohyb_vpravo_s;
		pouziti_schopnosti = profil.pouziti_schopnosti_s;
		pauza = profil.pauza_s;
	}
	if (vybrany_profil == 1)
	{
		profil_probiha = 1;

		profil1 profil;
		profil.nacteni_profilu();
		pouzit = profil.pouzit_s;
		jazyk = profil.jazyk_s;
		plosina_skin = profil.plosina_skin_s;
		highscore_cas = profil.highscore_cas_s;
		highscore_znicenych_bloku = profil.highscore_znicenych_bloku_s;
		level = profil.level_s;
		exp = profil.exp_s;
		pohyb_vlevo = profil.pohyb_vlevo_s;
		pohyb_vpravo = profil.pohyb_vpravo_s;
		pouziti_schopnosti = profil.pouziti_schopnosti_s;
		pauza = profil.pauza_s;
	}
	if (vybrany_profil == 2)
	{
		profil_probiha = 2;

		profil2 profil;
		profil.nacteni_profilu();
		pouzit = profil.pouzit_s;
		jazyk = profil.jazyk_s;
		plosina_skin = profil.plosina_skin_s;
		highscore_cas = profil.highscore_cas_s;
		highscore_znicenych_bloku = profil.highscore_znicenych_bloku_s;
		level = profil.level_s;
		exp = profil.exp_s;
		pohyb_vlevo = profil.pohyb_vlevo_s;
		pohyb_vpravo = profil.pohyb_vpravo_s;
		pouziti_schopnosti = profil.pouziti_schopnosti_s;
		pauza = profil.pauza_s;
	}
}
int Menu::ukladani_profilu()
{
	pouzit = 1;
	XMLDocument xmlDoc;
	if (profil_probiha == 0)
	{
		XMLNode* pRoot = xmlDoc.NewElement("Profil");
		xmlDoc.InsertFirstChild(pRoot);

		XMLElement* pElement0 = xmlDoc.NewElement("pouzit");
		pElement0->SetText(pouzit);
		pRoot->InsertEndChild(pElement0);

		XMLElement* pElement1 = xmlDoc.NewElement("jazyk");
		pElement1->SetText(jazyk);
		pRoot->InsertEndChild(pElement1);

		XMLElement* pElement2 = xmlDoc.NewElement("plosina_skin");
		pElement2->SetText(plosina_skin);
		pRoot->InsertEndChild(pElement2);

		XMLElement* pElement3 = xmlDoc.NewElement("highscore_cas");
		pElement3->SetText(highscore_cas);
		pRoot->InsertEndChild(pElement3);

		XMLElement* pElement4 = xmlDoc.NewElement("highscore_znicenych_bloku");
		pElement4->SetText(highscore_znicenych_bloku);
		pRoot->InsertEndChild(pElement4);

		XMLElement* pElement5 = xmlDoc.NewElement("level");
		pElement5->SetText(level);
		pRoot->InsertEndChild(pElement5);

		XMLElement* pElement6 = xmlDoc.NewElement("exp");
		pElement6->SetText(exp);
		pRoot->InsertEndChild(pElement6);

		XMLElement* pElement7 = xmlDoc.NewElement("pohyb_vlevo");
		pElement7->SetText(pohyb_vlevo);
		pRoot->InsertEndChild(pElement7);

		XMLElement* pElement8 = xmlDoc.NewElement("pohyb_vpravo");
		pElement8->SetText(pohyb_vpravo);
		pRoot->InsertEndChild(pElement8);

		XMLElement* pElement9 = xmlDoc.NewElement("pouziti_schopnosti");
		pElement9->SetText(pouziti_schopnosti);
		pRoot->InsertEndChild(pElement9);

		XMLElement* pElement10 = xmlDoc.NewElement("pauza");
		pElement10->SetText(pauza);
		pRoot->InsertEndChild(pElement10);

		XMLError eResult = xmlDoc.SaveFile("profil0.xml");
		XMLCheckResult(eResult);
	}
	if (profil_probiha == 1)
	{
		XMLNode* pRoot = xmlDoc.NewElement("Profil");
		xmlDoc.InsertFirstChild(pRoot);

		XMLElement* pElement0 = xmlDoc.NewElement("pouzit");
		pElement0->SetText(pouzit);
		pRoot->InsertEndChild(pElement0);


		XMLElement* pElement1 = xmlDoc.NewElement("jazyk");
		pElement1->SetText(jazyk);
		pRoot->InsertEndChild(pElement1);

		XMLElement* pElement2 = xmlDoc.NewElement("plosina_skin");
		pElement2->SetText(plosina_skin);
		pRoot->InsertEndChild(pElement2);


		XMLElement* pElement3 = xmlDoc.NewElement("highscore_cas");
		pElement3->SetText(highscore_cas);
		pRoot->InsertEndChild(pElement3);

		XMLElement* pElement4 = xmlDoc.NewElement("highscore_znicenych_bloku");
		pElement4->SetText(highscore_znicenych_bloku);
		pRoot->InsertEndChild(pElement4);

		XMLElement* pElement5 = xmlDoc.NewElement("level");
		pElement5->SetText(level);
		pRoot->InsertEndChild(pElement5);

		XMLElement* pElement6 = xmlDoc.NewElement("exp");
		pElement6->SetText(exp);
		pRoot->InsertEndChild(pElement6);

		XMLElement* pElement7 = xmlDoc.NewElement("pohyb_vlevo");
		pElement7->SetText(pohyb_vlevo);
		pRoot->InsertEndChild(pElement7);

		XMLElement* pElement8 = xmlDoc.NewElement("pohyb_vpravo");
		pElement8->SetText(pohyb_vpravo);
		pRoot->InsertEndChild(pElement8);

		XMLElement* pElement9 = xmlDoc.NewElement("pouziti_schopnosti");
		pElement9->SetText(pouziti_schopnosti);
		pRoot->InsertEndChild(pElement9);

		XMLElement* pElement10 = xmlDoc.NewElement("pauza");
		pElement10->SetText(pauza);
		pRoot->InsertEndChild(pElement10);

		XMLError eResult = xmlDoc.SaveFile("profil1.xml");
		XMLCheckResult(eResult);
	}
	if (profil_probiha == 2)
	{
		XMLNode* pRoot = xmlDoc.NewElement("Profil");
		xmlDoc.InsertFirstChild(pRoot);

		XMLElement* pElement0 = xmlDoc.NewElement("pouzit");
		pElement0->SetText(pouzit);
		pRoot->InsertEndChild(pElement0);


		XMLElement* pElement1 = xmlDoc.NewElement("jazyk");
		pElement1->SetText(jazyk);
		pRoot->InsertEndChild(pElement1);

		XMLElement* pElement2 = xmlDoc.NewElement("plosina_skin");
		pElement2->SetText(plosina_skin);
		pRoot->InsertEndChild(pElement2);


		XMLElement* pElement3 = xmlDoc.NewElement("highscore_cas");
		pElement3->SetText(highscore_cas);
		pRoot->InsertEndChild(pElement3);

		XMLElement* pElement4 = xmlDoc.NewElement("highscore_znicenych_bloku");
		pElement4->SetText(highscore_znicenych_bloku);
		pRoot->InsertEndChild(pElement4);

		XMLElement* pElement5 = xmlDoc.NewElement("level");
		pElement5->SetText(level);
		pRoot->InsertEndChild(pElement5);

		XMLElement* pElement6 = xmlDoc.NewElement("exp");
		pElement6->SetText(exp);
		pRoot->InsertEndChild(pElement6);

		XMLElement* pElement7 = xmlDoc.NewElement("pohyb_vlevo");
		pElement7->SetText(pohyb_vlevo);
		pRoot->InsertEndChild(pElement7);

		XMLElement* pElement8 = xmlDoc.NewElement("pohyb_vpravo");
		pElement8->SetText(pohyb_vpravo);
		pRoot->InsertEndChild(pElement8);

		XMLElement* pElement9 = xmlDoc.NewElement("pouziti_schopnosti");
		pElement9->SetText(pouziti_schopnosti);
		pRoot->InsertEndChild(pElement9);

		XMLElement* pElement10 = xmlDoc.NewElement("pauza");
		pElement10->SetText(pauza);
		pRoot->InsertEndChild(pElement10);

		XMLError eResult = xmlDoc.SaveFile("profil2.xml");
		XMLCheckResult(eResult);
	}
}
int Menu::nacteni_vyberu_profilu()
{
	XMLDocument xmlDoc;
	XMLError eResult = xmlDoc.LoadFile("profil_vyber.xml");
	XMLCheckResult(eResult);

	XMLNode* pRoot = xmlDoc.FirstChild();
	if (pRoot == nullptr) return XML_ERROR_FILE_READ_ERROR;

	XMLElement* pElement0 = pRoot->FirstChildElement("profil0");
	if (pElement0 == nullptr) return XML_ERROR_PARSING_ELEMENT;
	XMLElement* pListElement0 = pElement0->FirstChildElement("Item");
	nazev_profil0.clear();
	while (pListElement0 != nullptr)
	{
		int iOutListValue;
		eResult = pListElement0->QueryIntText(&iOutListValue);
		XMLCheckResult(eResult);

		nazev_profil0.push_back(iOutListValue);
		pListElement0 = pListElement0->NextSiblingElement("Item");
	}

	XMLElement* pElement1 = pRoot->FirstChildElement("profil1");
	if (pElement1 == nullptr) return XML_ERROR_PARSING_ELEMENT;
	XMLElement* pListElement1 = pElement1->FirstChildElement("Item");
	nazev_profil1.clear();
	while (pListElement1 != nullptr)
	{
		int iOutListValue;
		eResult = pListElement1->QueryIntText(&iOutListValue);
		XMLCheckResult(eResult);

		nazev_profil1.push_back(iOutListValue);
		pListElement1 = pListElement1->NextSiblingElement("Item");
	}

	XMLElement* pElement2 = pRoot->FirstChildElement("profil2");
	if (pElement2 == nullptr) return XML_ERROR_PARSING_ELEMENT;
	XMLElement* pListElement2 = pElement2->FirstChildElement("Item");
	nazev_profil2.clear();
	while (pListElement2 != nullptr)
	{
		int iOutListValue;
		eResult = pListElement2->QueryIntText(&iOutListValue);
		XMLCheckResult(eResult);

		nazev_profil2.push_back(iOutListValue);
		pListElement2 = pListElement2->NextSiblingElement("Item");
	}

	XMLElement* pElement3 = pRoot->FirstChildElement("uroven0");
	if (pElement3 == nullptr) return XML_ERROR_PARSING_ELEMENT;
	eResult = pElement3->QueryIntText(&uroven_profil0);
	XMLCheckResult(eResult);

	XMLElement* pElement4 = pRoot->FirstChildElement("uroven11");
	if (pElement4 == nullptr) return XML_ERROR_PARSING_ELEMENT;
	eResult = pElement4->QueryIntText(&uroven_profil1);
	XMLCheckResult(eResult);

	XMLElement* pElement5 = pRoot->FirstChildElement("uroven2");
	if (pElement5 == nullptr) return XML_ERROR_PARSING_ELEMENT;
	eResult = pElement5->QueryIntText(&uroven_profil2);
	XMLCheckResult(eResult);
	return XML_SUCCESS;
}
int Menu::ulozeni_vyberu_profilu()
{
	XMLDocument xmlDoc;
	XMLNode* pRoot = xmlDoc.NewElement("Profil");
	xmlDoc.InsertFirstChild(pRoot);

	XMLElement* pElement0 = xmlDoc.NewElement("profil0");
	for (const auto& item : nazev_profil0)
	{
		XMLElement* pListElement0 = xmlDoc.NewElement("Item");
		pListElement0->SetText(item);

		pElement0->InsertEndChild(pListElement0);
	}
	pRoot->InsertEndChild(pElement0);

	XMLElement* pElement1 = xmlDoc.NewElement("profil1");
	for (const auto& item : nazev_profil1)
	{
		XMLElement* pListElement1 = xmlDoc.NewElement("Item");
		pListElement1->SetText(item);

		pElement1->InsertEndChild(pListElement1);
	}
	pRoot->InsertEndChild(pElement1);

	XMLElement* pElement2 = xmlDoc.NewElement("profil2");
	for (const auto& item : nazev_profil2)
	{
		XMLElement* pListElement2 = xmlDoc.NewElement("Item");
		pListElement2->SetText(item);

		pElement2->InsertEndChild(pListElement2);
	}
	pRoot->InsertEndChild(pElement2);

	if (profil_probiha == 0)
	{
		profil0 profil;
		uroven_profil0 = level;
	}
	if (profil_probiha == 1)
	{
		profil0 profil;
		uroven_profil1 = level;
	}
	if (profil_probiha == 2)
	{
		profil0 profil;
		uroven_profil2 = level;
	}

	XMLElement* pElement3 = xmlDoc.NewElement("uroven0");
	pElement3->SetText(uroven_profil0);
	pRoot->InsertEndChild(pElement3);

	XMLElement* pElement4 = xmlDoc.NewElement("uroven1");
	pElement4->SetText(uroven_profil1);
	pRoot->InsertEndChild(pElement4);

	XMLElement* pElement5 = xmlDoc.NewElement("uroven2");
	pElement5->SetText(uroven_profil2);
	pRoot->InsertEndChild(pElement5);

	XMLError eResult = xmlDoc.SaveFile("profil_vyber.xml");
	XMLCheckResult(eResult);
} // 
std::vector<char> Menu::vytvoreni_noveho_nazvu_profilu()
{
	for (int i = 0; i < novy_profil.size(); i++)
	{
		nazev_profil_novy.push_back(novy_profil.at(i));
	}
	return nazev_profil_novy;

}


/////////////////////    Input     //////////////////////////
int Menu::vstup_menu(int strana)
{
	switch (_getch())
	{
	case 'w':
	{
		smazani_oznaceni();
		{
			if ((oznaceni.at(1) > zavory.at(0)) && (strana == 0))
			{
				if (oznaceni.at(1) <= 12)
				{
					oznaceni.at(1) -= 2;
				}
				else
				{
					oznaceni.at(1) -= 5;
					oznaceni.at(0) = 10;
				}
			}
			/*if ((oznaceni.at(1) > zavory.at(0)) && (strana == 0 || strana == 1))
			{
				oznaceni.at(1) -= 2;
			}

			if ((oznaceni.at(1) > zavory.at(0)) && (strana == 2))
			{
				oznaceni.at(1) -= 4;
			}
			if ((oznaceni.at(1) > zavory.at(0)) && (strana == 3))
			{
				if (oznaceni.at(1) <= 12)
				{
					oznaceni.at(0) = 4;
				}
				else
				{
					oznaceni.at(0) = 7;
				}
				oznaceni.at(1) -= 2;
			}
			if ((oznaceni.at(1) > zavory.at(0)) && (strana == 4))
			{
				oznaceni.at(1) = oznaceni.at(1)--;
			}*/
		}
		break;
	}
	case 's':
	{
		smazani_oznaceni();
		{
			if ((oznaceni.at(1) < zavory.at(1)) && (strana == 0))
			{
				if (oznaceni.at(1) < 12)
				{
					oznaceni.at(1) += 2;
				}
				else
				{
					oznaceni.at(1) += 5;
					oznaceni.at(0) = 2;
				}
			}
			/*if ((oznaceni.at(1) < zavory.at(1)) && (strana == 0 || strana == 1))
			{
				oznaceni.at(1) += 2;
			}
			if ((oznaceni.at(1) < zavory.at(1)) && (strana == 2))
			{
				oznaceni.at(1) += 4;
			}
			if ((oznaceni.at(1) < zavory.at(1)) && (strana == 3))
			{
				if (oznaceni.at(1) <= 8)
				{
					oznaceni.at(0) = 4;
				}
				else
				{
					oznaceni.at(0) = 7;
				}
				oznaceni.at(1) += 2;
			}
			if ((oznaceni.at(1) < zavory.at(1)) && (strana == 4))
			{
				oznaceni.at(1)++;
			}*/
		}
		break;
	}
	case 'a':
	{
		smazani_oznaceni();
		{
			if (oznaceni.at(0) > zavory.at(2))
			{
				oznaceni.at(0) -= 10;
			}
		}
		break;
	}
	case 'd':
	{
		smazani_oznaceni();
		{
			if (oznaceni.at(0) < zavory.at(3))
			{
				oznaceni.at(0) += 10;
			}
		}
		break;
	}
	case '\r':
	{
		{
			return enter;
		}
		break;
	}
	case ' ':
	{
		{
			if (strana == -1)
			{
				return exit;
			}
		}
		break;
	}
	case 'q':
	{
		{
			if (strana == 0)
			{
				return exit;
			}
			else if (strana == 4)
			{

			}
			else
			{

			}
		}
		break;
	}
	case char(8) :
	{
		if (strana == 0)
		{
			return del;
		}
		break;
	}
	default:
		break;
	}
}
int Menu::rozhodovac(int strana, int prikaz)
{
	/////////////////////    Profily     //////////////////////////
	if (strana == 0)
	{
		/*nazev_profil_novy.clear();
		nacteni_vyberu_profilu();
		vytvoreni_noveho_nazvu_profilu();*/
		if (oznaceni.at(1) == 8)
		{
			profil0 profil;
			if (prikaz == enter)
				vyber_profilu(0);
			if (prikaz == del)
			{
				profil.vytvoreni_noveho_profilu();
				nazev_profil0 = nazev_profil_novy;
				level = 0;
				ulozeni_vyberu_profilu();
			}
			return 1;
		}
		if (oznaceni.at(1) == 10)
		{
			profil1 profil;
			if (prikaz == enter)
				vyber_profilu(1);
			if (prikaz == del)
			{
				profil.vytvoreni_noveho_profilu();
				nazev_profil1 = nazev_profil_novy;
				level = 0;
				ulozeni_vyberu_profilu();
			}
			return 1;
		}
		if (oznaceni.at(1) == 12)
		{
			profil2 profil;
			if (prikaz == enter)
				vyber_profilu(2);
			if (prikaz == del)
			{
				profil.vytvoreni_noveho_profilu();
				nazev_profil2 = nazev_profil_novy;
				level = 0;
				ulozeni_vyberu_profilu();
			}
			return 1;
		}
		if (oznaceni.at(1) == 17)
		{
			if (!jazyk)
				jazyk = 1;
			else
				jazyk = 0;
		}
	}

	/////////////////////    Hlavni menu     //////////////////////////

	if (strana == 1)
	{
		if (oznaceni.at(1) == 10)
			return 1;
		if (oznaceni.at(1) == 12)
			return 2;
		if (oznaceni.at(1) == 14)
			return 3;
	}

	/////////////////////    Herni mody     //////////////////////////

	if (strana == 1)
	{
		if (oznaceni.at(1) == 8)
			return 1;
		/*if (y_tecka == 10)
		if (y_tecka == 12)*/
		if (oznaceni.at(1) == 14)
			return 4;
	}

	/////////////////////    Skiny     //////////////////////////

	if (strana == 2)
	{
		if (oznaceni.at(1) == 9 && oznaceni.at(0) == 6)
			return plosina_skin = 0;
		if (oznaceni.at(1) == 9 && oznaceni.at(0) == 16)
			if (level >= potr_urov1)
				return plosina_skin = 1;
			else
				return -1;
		if (oznaceni.at(1) == 9 && oznaceni.at(0) == 26)
			if (level >= potr_urov2)
				return plosina_skin = 2;
			else
				return -2;
		if (oznaceni.at(1) == 13 && oznaceni.at(0) == 6)
			if (level >= potr_urov3)
				return plosina_skin = 3;
			else
				return -3;
		if (oznaceni.at(1) == 13 && oznaceni.at(0) == 16)
			if (level >= potr_urov4)
				return plosina_skin = 4;
			else
				return -4;
		if (oznaceni.at(1) == 13 && oznaceni.at(0) == 26)
		{
			if (level >= potr_urov5)
			{
				custom_skin();
				return plosina_skin = 5;
			}
			else
				return -5;
		}
	}

	/////////////////////    Nastaveni     //////////////////////////

	/*if (strana == 3)
	{
		if (oznaceni.at(1) == 8)
		{
			return -1;
		}
		if (oznaceni.at(1) == 10)
		{
			exit = 0;
			if (vytazeno)
				vytazeno = 0;
			else
				vytazeno = 1;
			return balic = 1;
		}
		if (oznaceni.at(1) == 12)
		{
			vytazeno = 0;
			exit = 1;
			return jazyk_zmena = 0;
		}
		if (oznaceni.at(1) == 14)
		{
			vytazeno = 0;
			exit = 1;
			return jazyk_zmena = 1;
		}
	}*/
	/////////////////////    Nastaveni     //////////////////////////

	if (strana == 4)
	{
		if (oznaceni.at(1) == 12)
		{
			set.setCursorPosition(29, 12);
			pohyb_vpravo = _getch();
			if (pohyb_vpravo >= 97 && pohyb_vpravo <= 122)
				pohyb_vpravo -= 32;
		}
		if (oznaceni.at(1) == 13)
		{
			set.setCursorPosition(29, 13);
			pohyb_vlevo = _getch();
			if (pohyb_vlevo >= 97 && pohyb_vlevo <= 122)
				pohyb_vlevo -= 32;
		}
		if (oznaceni.at(1) == 14)
		{
			set.setCursorPosition(29, 14);
			pouziti_schopnosti = _getch();
			if (pouziti_schopnosti >= 97 && pouziti_schopnosti <= 122)
				pouziti_schopnosti -= 32;
		}
		if (oznaceni.at(1) == 14)
		{
			set.setCursorPosition(29, 15);
			pauza = _getch();
			if (pauza >= 97 && pauza <= 122)
				pauza -= 32;
		}
	}
}

void Menu::custom_skin()
{
	set.setCursorPosition(27, 14);
	std::wcout << L"      ";
	set.setCursorPosition(27, 14);

	pole_skin.resize(plosina.velikost_plosina);
	for (int i = 0; i < pole_skin.size(); i++)
	{
		pole_skin.at(i) = _getche();
	}
}
std::vector<char> Menu::string_na_vektor(std::string nazev)
{
	if (profil_probiha == 0)
	{
		nazev_profil0.clear();
		for (int i = 0; i < nazev.size(); i++)
		{
			nazev_profil0.push_back(nazev.at(i));
		}
		return nazev_profil0;
	}
	if (profil_probiha == 1)
	{
		nazev_profil1.clear();
		for (int i = 0; i < nazev.size(); i++)
		{
			nazev_profil1.push_back(nazev.at(i));
		}
		return nazev_profil1;
	}
	if (profil_probiha == 2)
	{
		nazev_profil2.clear();
		for (int i = 0; i < nazev.size(); i++)
		{
			nazev_profil2.push_back(nazev.at(i));
		}
		return nazev_profil2;
	}
}
void Menu::vektor_na_string(std::vector<char> p0, std::vector<char> p1, std::vector<char> p2)
{
	muj_profil0.clear();
	for (int i = 0; i < p0.size(); i++)
	{
		muj_profil0.push_back(p0.at(i));
	}
	muj_profil0;
	muj_profil1.clear();
	for (int i = 0; i < p1.size(); i++)
	{
		muj_profil1.push_back(p1.at(i));
	}
	muj_profil1;
	muj_profil2.clear();
	for (int i = 0; i < p2.size(); i++)
	{
		muj_profil2.push_back(p2.at(i));
	}
	muj_profil2;
}



/////////////////////    Vykresleni     //////////////////////////


void  Menu::vykresleni_menu_start()
{
	set.setCursorPosition(0, 0);
	////////////    vykreslovani plocha    ////////////
	for (int j = 0; j < vyska_menu; j++)
	{
		for (int i = 0; i < delka_menu; i++)
		{
			if (j == 0 && i == 0)
			{
				std::wcout << L"\x2554";
			}
			else if (i == 0 && j == vyska_menu - 1)
			{
				std::wcout << L"\x255a";
			}
			else if (j == 0 && i == delka_menu - 1)
			{
				std::wcout << L"\x2557";
			}
			else if (j == vyska_menu - 1 && i == delka_menu - 1)
			{
				std::wcout << L"\x255d";
			}
			else if (j == 0 || j == vyska_menu - 1)
			{
				std::wcout << L"\x2550";
			}
			else if (i == 0 || i == delka_menu - 1)
			{
				std::wcout << L"\x2551";
			}
			else
			{
				std::wcout << ' ';
			}
		}
		if (!(j == vyska_menu - 1))
			std::wcout << '\n';
	}
}
void  Menu::vykresleni_uroven()
{
	if (!jazyk)
	{
		set.setCursorPosition(27, 17);
		std::wcout << odchod6CZ << level;
	}
	else
	{
		set.setCursorPosition(27, 17);
		std::wcout << odchod6EN << level;
	}
	for (int i = 0; i < exp; i++)
	{
		exp_pole.push_back(2);
	}
	for (int i = 0; i < 20 - exp; i++)
	{
		exp_pole.push_back(0);
	}
	set.setCursorPosition(17, 18);
	for (int i = 0; i < exp_pole.size(); i++)
	{
		if (exp_pole.at(i) == 2)
			std::wcout << L"\x2588";
		if (exp_pole.at(i) == 0)
			std::wcout << L"\x2591";
	}
}

void Menu::level_bar()
{
	exp_pole.clear();
	int docas_exp = 0;
	int level_up = 0;
	while (n_exp >= 20)
	{
		n_exp -= 20;
		level_up++;
		docas_exp = n_exp;
	}

	exp += n_exp;
	if (exp >= 20)
	{
		exp -= 20;
		docas_exp = exp;
		level_up++;
	}
	if (level_up > 0)
	{
		level += level_up;
		for (int i = 0; i < docas_exp; i++)
		{
			exp_pole.push_back(1);
		}
		for (int i = 0; i < 20 - docas_exp; i++)
		{
			exp_pole.push_back(0);
		}
	}
	else
	{
		for (int i = 0; i < exp - n_exp; i++)
		{
			exp_pole.push_back(2);
		}
		for (int i = 0; i < n_exp; i++)
		{
			exp_pole.push_back(1);
		}
		for (int i = 0; i < 20 - exp; i++)
		{
			exp_pole.push_back(0);
		}
	}
}