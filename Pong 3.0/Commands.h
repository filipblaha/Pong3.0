#pragma once
#include <iostream>
#include <Windows.h>
#include <fcntl.h>
#include <io.h>

class Commands
{
public:
	void prechod();
	void setCursorPosition(int x, int y);
	void font(int f1, int f2);
	void SetWindow(int delka, int vyska);
};