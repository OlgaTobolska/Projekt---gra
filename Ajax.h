#include <iostream>
#include <SDL.h>
#include <stdio.h>
#include <vector>
#include "Postac.h"

using namespace std;

vector<Ajax*> enemies_p1;

class Ajax : public Postac
{
private:

public:
	Ajax(double _x, double _y, SDL_Surface* _obraz) : Postac(_x, _y, _obraz)
	{}
	void zniszcz(int it)
	{
		enemies.erase(enemies.begin() + it);
	}
};