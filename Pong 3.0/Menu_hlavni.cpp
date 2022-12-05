#include "Menu_hlavni.h"

void  Menu_hlavni::vykresleni_hlavni()
{
	//set.setCursorPosition(6, 10);
	//if (!jazyk)
	//	std::wcout << herni_modyCZ;
	//if (jazyk)
	//	std::wcout << herni_modyEN;
	//set.setCursorPosition(6, 12);
	//if (!jazyk)
	//	std::wcout << vzhled_plosinyCZ;
	//if (jazyk)
	//	std::wcout << vzhled_plosinyEN;
	//set.setCursorPosition(6, 14);
	//if (!jazyk)
	//	std::wcout << nastaveniCZ;
	//if (jazyk)
	//	std::wcout << nastaveniEN;
	//set.setCursorPosition(2, 18);
	//if (!jazyk)
	//	std::wcout << verzeCZ << 2.9;
	//if (jazyk)
	//	std::wcout << verzeEN << 2.9;
}

void  Menu_hlavni::vykresleni_logo()
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