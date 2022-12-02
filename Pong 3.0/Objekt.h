#include <iostream>
#include <vector>
class Objekt
{
public:
	int pohyb = 0;

	std::vector<int> souradnice;
	std::vector<int> zrychleni;

	Objekt(int x, int y, int ax, int ay)
	{
		souradnice.push_back(x);
		souradnice.push_back(y);

		zrychleni.push_back(ax);
		zrychleni.push_back(ay);
	}

private:

};