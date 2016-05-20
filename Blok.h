#include <iostream>
#include <SDL.h>
#include <stdio.h>

class Blok
{
private:
	double x;	// lewy gorny rog
	double y;
	SDL_Surface* obraz;
public:
	Blok(double _x, double _y)
	{
		x = _x;
		y = _y;
		obraz = NULL;
	}
};