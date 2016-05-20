#include <iostream>
#include <SDL.h>
#include <stdio.h>
#include "Postac.h"

class Wade : public Postac
{
private:

public:
	Wade(double _x, double _y) : Postac(_x, _y)
	{}
	void setObraz(SDL_Surface* _obraz)
	{

	}
};