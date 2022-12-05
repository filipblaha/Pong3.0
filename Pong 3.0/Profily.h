#pragma once
#include <iostream>
#include <vector>

#include "tinyxml2.h"

#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace tinyxml2;

class profil
{
public:
	XMLDocument xmlDoc;
	int pouzit_s = 0;
	int jazyk_s = 0;
	int plosina_skin_s = 0;
	int highscore_cas_s = 0;
	int highscore_znicenych_bloku_s = 0;
	int level_s = 0;
	int exp_s = 0;

	int pohyb_vlevo_s = 68;
	int pohyb_vpravo_s = 65;
	int pouziti_schopnosti_s = 32;
	int pauza_s = 27;

	int vytvoreni_noveho_profilu()
	{
		XMLNode* v = xmlDoc.NewElement("Profil0");
		xmlDoc.InsertFirstChild(v);

		XMLElement* a = xmlDoc.NewElement("porno");
		a->SetText(0);
		v->InsertEndChild(a);

		XMLNode* pRoot = xmlDoc.NewElement("Profil1");
		xmlDoc.InsertFirstChild(pRoot);

		XMLElement* pElement0 = xmlDoc.NewElement("pouzit");
		pElement0->SetText(0);
		pRoot->InsertEndChild(pElement0);

		XMLElement* pElement1 = xmlDoc.NewElement("jazyk");
		pElement1->SetText(0);
		pRoot->InsertEndChild(pElement1);

		XMLElement* pElement2 = xmlDoc.NewElement("plosina_skin");
		pElement2->SetText(0);
		pRoot->InsertEndChild(pElement2);

		XMLElement* pElement3 = xmlDoc.NewElement("highscore_cas");
		pElement3->SetText(0);
		pRoot->InsertEndChild(pElement3);

		XMLElement* pElement4 = xmlDoc.NewElement("highscore_znicenych_bloku");
		pElement4->SetText(0);
		pRoot->InsertEndChild(pElement4);

		XMLElement* pElement5 = xmlDoc.NewElement("level");
		pElement5->SetText(0);
		pRoot->InsertEndChild(pElement5);

		XMLElement* pElement6 = xmlDoc.NewElement("exp");
		pElement6->SetText(0);
		pRoot->InsertEndChild(pElement6);

		XMLElement* pElement7 = xmlDoc.NewElement("pohyb_vlevo");
		pElement7->SetText(68);
		pRoot->InsertEndChild(pElement7);

		XMLElement* pElement8 = xmlDoc.NewElement("pohyb_vpravo");
		pElement8->SetText(65);
		pRoot->InsertEndChild(pElement8);

		XMLElement* pElement9 = xmlDoc.NewElement("pouziti_schopnosti");
		pElement9->SetText(32);
		pRoot->InsertEndChild(pElement9);

		XMLElement* pElement10 = xmlDoc.NewElement("pauza");
		pElement10->SetText(27);
		pRoot->InsertEndChild(pElement10);

		XMLError eResult = xmlDoc.SaveFile("profil0.xml");
		XMLCheckResult(eResult);
	}
	int nacteni_profilu()
	{
		XMLError eResult = xmlDoc.LoadFile("profily.xml");
		XMLCheckResult(eResult);

		XMLNode* pRoot = xmlDoc.FirstChild();
		if (pRoot == nullptr) return XML_ERROR_FILE_READ_ERROR;

		XMLElement* pElement0 = pRoot->FirstChildElement("pouzit"); //nalezeni int value
		if (pElement0 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement0->QueryIntText(&pouzit_s); // vyndani int
		XMLCheckResult(eResult);

		XMLElement* pElement1 = pRoot->FirstChildElement("jazyk");
		if (pElement1 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement1->QueryIntText(&jazyk_s);
		XMLCheckResult(eResult);

		XMLElement* pElement2 = pRoot->FirstChildElement("plosina_skin");
		if (pElement2 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement2->QueryIntText(&plosina_skin_s);
		XMLCheckResult(eResult);

		XMLElement* pElement3 = pRoot->FirstChildElement("highscore_cas");
		if (pElement3 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement3->QueryIntText(&highscore_cas_s);
		XMLCheckResult(eResult);

		XMLElement* pElement4 = pRoot->FirstChildElement("highscore_znicenych_bloku");
		if (pElement4 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement4->QueryIntText(&highscore_znicenych_bloku_s);
		XMLCheckResult(eResult);

		XMLElement* pElement5 = pRoot->FirstChildElement("level");
		if (pElement5 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement5->QueryIntText(&level_s);
		XMLCheckResult(eResult);

		XMLElement* pElement6 = pRoot->FirstChildElement("exp");
		if (pElement6 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement6->QueryIntText(&exp_s);
		XMLCheckResult(eResult);

		XMLElement* pElement7 = pRoot->FirstChildElement("pohyb_vlevo");
		if (pElement7 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement7->QueryIntText(&pohyb_vlevo_s);
		XMLCheckResult(eResult);

		XMLElement* pElement8 = pRoot->FirstChildElement("pohyb_vpravo");
		if (pElement8 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement8->QueryIntText(&pohyb_vpravo_s);
		XMLCheckResult(eResult);

		XMLElement* pElement9 = pRoot->FirstChildElement("pouziti_schopnosti");
		if (pElement9 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement9->QueryIntText(&pouziti_schopnosti_s);
		XMLCheckResult(eResult);

		XMLElement* pElement10 = pRoot->FirstChildElement("pauza");
		if (pElement10 == nullptr) return XML_ERROR_PARSING_ELEMENT;
		eResult = pElement10->QueryIntText(&pauza_s);
		XMLCheckResult(eResult);

		return XML_SUCCESS;
	}
};