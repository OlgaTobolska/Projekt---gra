#include <iostream>
#include <SDL.h>
#include <stdio.h>
#include <vector>
#include "Postac.h"

using namespace std;

vector<Ajax*> enemies;

class Ajax : public Postac
{
private:

public:
	Ajax(double _x, double _y) : Postac(_x, _y)
	{}
	void zniszcz(int it)
	{
		enemies.erase(enemies.begin() + it);
	}
};