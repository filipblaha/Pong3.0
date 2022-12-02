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

	bool program = 0;
	bool exit = 0;
	bool enter = 0;
	bool del = 0;
	bool pokracovani = 0;
	bool reset = 0;
	bool pouzit = 0;
	bool jazyk = 0;

	Menu(int strana, int x = 0, int y = 0, int horni_z = 0, int dolni_z = 0, int leva_z = 0, int prava_z = 0)
	{
		program = 1;
		exit = 0;
		enter = 0;
		del = 0;

		if (strana > 0)
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

			if (strana == 1)
			{
				vykresleni_profil();
			}
			if (strana == 2)
			{
				vykresleni_hlavni();
				vykresleni_logo();
			}
		}
	}
	Menu()
	{
		reset = 0;
		pokracovani = 1;
		set.prechod();
		set.font(20, 20);
	}

	void vykresleni_oznaceni()
	{
		set.setCursorPosition(oznaceni.at(0), oznaceni.at(1));
		std::wcout << L"\x25ba";
	}
	void smazani_oznaceni()
	{
		set.setCursorPosition(oznaceni.at(0), oznaceni.at(1));
		std::wcout << ' ';
	}

	void vykresleni_otazka()
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
	void smazani_otazka()
	{
		set.setCursorPosition(5, 2);
		std::wcout << "                               ";
		set.setCursorPosition(26, 3);
		std::wcout << "       ";
	}
	void vykresleni_nazev_profilu()
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

	void pojmenovani_profilu()
	{
		set.setCursorPosition(10, 10);
		std::cin >> pojmenovani;
		string_na_vektor(pojmenovani);
	}
	void vyber_profilu(int vybrany_profil)
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
	int ukladani_profilu()
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
	int nacteni_vyberu_profilu()
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
	int ulozeni_vyberu_profilu()
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



	void vstup_menu(int strana)
	{
		switch (_getch())
		{
		case 'w':
		{
			{
				if ((oznaceni.at(1) > zavory.at(0)) && (strana == -1))
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
				if ((oznaceni.at(1) > zavory.at(0)) && (strana == 0 || strana == 1))
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
				}
				exit = 0;
				enter = 0;
				del = 0;
			}
			break;
		}
		case 's':
		{
			{
				if ((oznaceni.at(1) < zavory.at(1)) && (strana == -1))
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
				if ((oznaceni.at(1) < zavory.at(1)) && (strana == 0 || strana == 1))
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
				}
				exit = 0;
				enter = 0;
				del = 0;
			}
			break;
		}
		case 'a':
		{
			{
				if (oznaceni.at(0) > zavory.at(2))
				{
					oznaceni.at(0) -= 10;
					exit = 0;
					enter = 0;
					del = 0;
				}
			}
			break;
		}
		case 'd':
		{
			{
				if (oznaceni.at(0) < zavory.at(3))
				{
					oznaceni.at(0) += 10;
					exit = 0;
					enter = 0;
					del = 0;
				}
			}
			break;
		}
		case '\r':
		{
			{
				enter = 1;
				exit = 0;
			}
			break;
		}
		case ' ':
		{
			{
				if (strana == -1)
				{
					exit = 1;
					del = 0;
					pokracovani = 0;
				}
			}
			break;
		}
		case 'q':
		{
			{
				if (strana == 0)
				{
					program = 0;
				}
				else if (strana == -1)
				{
					reset = 0;
					pokracovani = 0;
					enter = 0;
					del = 0;
				}
				else if (strana == 4)
				{
					enter = 0;
					del = 0;
					reset = 0;
				}
				else
				{
					enter = 0;
					del = 0;
				}
				exit = 1;
			}
			break;
		}
		case char(8) :
		{
			if (strana == -1)
			{
				del = 1;
			}
			break;
		}
		default:
			break;
		}
	}
	int rozhodovac(int strana)
	{
		/////////////////////    Profily     //////////////////////////
		if (strana == -1)
		{
			/*nazev_profil_novy.clear();
			nacteni_vyberu_profilu();
			vytvoreni_noveho_nazvu_profilu();*/
			if (oznaceni.at(1) == 8)
			{
				profil0 profil;
				if (enter)
					vyber_profilu(0);
				if (del)
				{
					profil.vytvoreni_noveho_profilu();
					nazev_profil0 = nazev_profil_novy;
					level = 0;
					ulozeni_vyberu_profilu();
					enter = 0;
					del = 0;
					exit = 1;
				}
				return 1;
			}
			if (oznaceni.at(1) == 10)
			{
				profil1 profil;
				if (enter)
					vyber_profilu(1);
				if (del)
				{
					profil.vytvoreni_noveho_profilu();
					nazev_profil1 = nazev_profil_novy;
					level = 0;
					ulozeni_vyberu_profilu();
					enter = 0;
					del = 0;
					exit = 1;
				}
				return 1;
			}
			if (oznaceni.at(1) == 12)
			{
				profil2 profil;
				if (enter)
					vyber_profilu(2);
				if (del)
				{
					profil.vytvoreni_noveho_profilu();
					nazev_profil2 = nazev_profil_novy;
					level = 0;
					ulozeni_vyberu_profilu();
					enter = 0;
					del = 0;
					exit = 1;
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

		if (strana == 0)
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
	

private:

	const int delka_menu = 40;
	const int vyska_menu = 20;

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

	////////    Oznaceni     ////////
	std::vector<int> oznaceni;
	std::vector<int> zavory;

	////////    Profily    ////////
	std::vector<char> nazev_profil0;
	std::vector<char> nazev_profil1;
	std::vector<char> nazev_profil2;
	std::vector<char> nazev_profil_novy;
	std::vector<char> vytvoreni_noveho_nazvu_profilu()
	{
		for (int i = 0; i < novy_profil.size(); i++)
		{
			nazev_profil_novy.push_back(novy_profil.at(i));
		}
		return nazev_profil_novy;

	}

	////////    Custom skin   ///////
	std::vector<char> pole_skin;

	////////    Level bar   ///////
	std::vector<int> docas;
	std::vector<int> exp_pole;

	void level_bar()
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

	/////////////////////    Vykresleni     //////////////////////////

	void vykresleni_profil()
	{
		///////    Ramecek   ///////
		set.setCursorPosition(8, 7);
		for (int i = 0; i < 24; i++)
		{
			if (i == 0)
				std::wcout << L"\x250c";
			else if (i == 23)
				std::wcout << L"\x2510";
			else
				std::wcout << L"\x2500";
		}
		for (int j = 8; j < 13; j++)
		{
			set.setCursorPosition(8, j);
			for (int i = 0; i < 24; i++)
			{
				if (i == 0)
					std::wcout << L"\x2502";
			}
		}
		for (int j = 8; j < 13; j++)
		{
			set.setCursorPosition(31, j);
			for (int i = 0; i < 24; i++)
			{
				if (i == 0)
					std::wcout << L"\x2502";
			}
		}
		set.setCursorPosition(8, 13);
		for (int i = 0; i < 24; i++)
		{
			if (i == 0)
				std::wcout << L"\x2514";
			else if (i == 23)
				std::wcout << L"\x2518";
			else
				std::wcout << L"\x2500";
		}
		set.setCursorPosition(32, 16);
		for (int i = 0; i < 7; i++)
		{
			if (i == 0)
				std::wcout << L"\x250c";
			else if (i == 6)
				std::wcout << L"\x2510";
			else
				std::wcout << L"\x2500";
		}
		set.setCursorPosition(32, 17);
		for (int i = 0; i < 7; i++)
		{
			if (i == 0 || i == 6)
				std::wcout << L"\x2502";
			else if (i == 3)
				std::wcout << char(17);
			else if (i == 4 || i == 5)
				std::wcout << L"\x2500";
			else
				std::wcout << ' ';
		}
		set.setCursorPosition(32, 18);
		for (int i = 0; i < 7; i++)
		{
			if (i == 0)
				std::wcout << L"\x2514";
			else if (i == 6)
				std::wcout << L"\x2518";
			else
				std::wcout << L"\x2500";
		}

			///////    Text   ///////
		
			set.setCursorPosition(10, 5);
			if (!jazyk)
				std::wcout << vyber_profiluCZ;
			if (jazyk)
				std::wcout << vyber_profiluEN;
			set.setCursorPosition(12, 8);
			std::wcout << muj_profil0;
			set.setCursorPosition(12, 10);
			std::wcout << muj_profil1;
			set.setCursorPosition(12, 12);
			std::wcout << muj_profil2;
		
			set.setCursorPosition(4, 16);
			if (!jazyk)
				std::wcout << jazykCZ;
			if (jazyk)
				std::wcout << jazykEN;
			set.setCursorPosition(4, 17);
			if (!jazyk)
				std::wcout << ceskyCZ;
			if (jazyk)
				std::wcout << anglickyEN;
			if (!jazyk)
			{
				set.setCursorPosition(18, 17);
				std::wcout << smazani_pokrokCZ;
			}
			if (jazyk)
			{
				set.setCursorPosition(17, 17);
				std::wcout << smazani_pokrokEN;
			}
	}
	void vykresleni_hlavni()
	{
		set.setCursorPosition(6, 10);
		if (!jazyk)
			std::wcout << herni_modyCZ;
		if (jazyk)
			std::wcout << herni_modyEN;
		set.setCursorPosition(6, 12);
		if (!jazyk)
			std::wcout << vzhled_plosinyCZ;
		if (jazyk)
			std::wcout << vzhled_plosinyEN;
		set.setCursorPosition(6, 14);
		if (!jazyk)
			std::wcout << nastaveniCZ;
		if (jazyk)
			std::wcout << nastaveniEN;
		set.setCursorPosition(2, 18);
		if (!jazyk)
			std::wcout << verzeCZ << 2.9;
		if (jazyk)
			std::wcout << verzeEN << 2.9;
	}

	void vykresleni_menu_start()
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
	void vykresleni_logo()
	{
		int m = 10;
		int n = 2;
		set.setCursorPosition(m, n);
		for (int j = 0; j < vyska_menu; j++)
		{
			for (int i = 0; i < delka_menu; i++)
			{
				if (j == 2)
				{
					if (i == 0 || i == 3 || i == 5 || i == 8 || i == 10 || i == 13 || i == 15 || i == 18)
						std::wcout << L"\x2588";
					else if (i == 1 || i == 2 || i == 6 || i == 7 || i == 16 || i == 17)
						std::wcout << L"\x2580";
					else
					{
						if (i < 19)
							std::wcout << ' ';
					}
				}
			}
		}
		set.setCursorPosition(m, n + 1);
		for (int j = 0; j < vyska_menu; j++)
		{
			for (int i = 0; i < delka_menu; i++)
			{
				if (j == 2)
				{
					if (i == 0 || i == 3 || i == 5 || i == 8 || i == 10 || i == 11 || i == 13 || i == 15)
						std::wcout << L"\x2588";
					else
					{
						if (i < 19)
							std::wcout << ' ';
					}
				}
			}
		}
		set.setCursorPosition(m, n + 2);
		for (int j = 0; j < vyska_menu; j++)
		{
			for (int i = 0; i < delka_menu; i++)
			{
				if (j == 2)
				{
					if (i == 0 || i == 5 || i == 8 || i == 10 || i == 12 || i == 13 || i == 15 || i == 18)
						std::wcout << L"\x2588";
					else if (i > 0 && i < 4 || i == 17)
						std::wcout << L"\x2580";
					else
					{
						if (i < 19)
							std::wcout << ' ';
					}
				}
			}
		}
		set.setCursorPosition(m, n + 3);
		for (int j = 0; j < vyska_menu; j++)
		{
			for (int i = 0; i < delka_menu; i++)
			{
				if (j == 2)
				{
					if (i == 0 || i == 5 || i == 8 || i == 10 || i == 13 || i == 15 || i == 18)
						std::wcout << L"\x2588";
					else if (i == 6 || i == 7 || i == 16 || i == 17)
						std::wcout << L"\x2584";
					else
					{
						if (i < 19)
							std::wcout << ' ';
					}
				}
			}
		}
	}
	void vykresleni_uroven()
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

	/////////////////////    Input od uzivatele     //////////////////////////

	void custom_skin()
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
	std::vector<char> string_na_vektor(std::string nazev)
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
	void vektor_na_string(std::vector<char> p0, std::vector<char> p1, std::vector<char> p2)
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
};

