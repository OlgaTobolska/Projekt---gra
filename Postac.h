#include <iostream>
#include <SDL.h>
#include <stdio.h>

class Postac
{
protected:
	double x;	// lewy gorny rog
	double y;
	SDL_Surface* obraz;
public:
	Postac(double _x, double _y, SDL_Surface* _obraz)
	{
		x = _x;
		y = _y;
		obraz = _obraz;
	}
	virtual void kolizja()
	{

	}
};