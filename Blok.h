#include <iostream>
#include <SDL.h>
#include <stdio.h>
#include <vector>

using namespace std;

vector<Blok*> poziom1;

class Blok
{
private:
	double x;	// lewy gorny rog
	double y;
	SDL_Surface* obraz;
public:
	Blok(double _x, double _y, SDL_Surface* _obraz)
	{
		x = _x;
		y = _y;
		obraz = _obraz;
	}
	void zmienBonus(SDL_Surface* _obraz)
	{
		obtaz = _obraz;
	}
};