#include <iostream>
#include <SDL.h>
#include <stdio.h>
#include "Postac.h"

class Wade : public Postac
{
private:
	SDL_Surface* obraz1l;
	SDL_Surface* obraz2l;
	SDL_Surface* obraz3l;
	SDL_Surface* obraz4l;
public:
	Wade(double _x, double _y, SDL_Surface* _obraz) : Postac(_x, _y, _obraz)
	{}
	void setObraz(SDL_Surface* _obraz1, SDL_Surface* _obraz2, SDL_Surface* _obraz3, SDL_Surface* _obraz4)
	{
		obraz1l = _obraz1;
		obraz2l = _obraz2;
		obraz3l = _obraz3;
		obraz4l = _obraz4;
	}
};