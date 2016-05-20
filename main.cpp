#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "Postac.h"
#include "Wade.h"
#include "Ajax.h"
#include "Scena.h"
#include "Blok.h"
using namespace std;

// ustawienie okna
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// uruchomienie SDL i stworzenie okna
bool init();

// ladowanie plikow
bool loadMedia();

// zwolnienie miejsca i wylaczenie SDL
void close();

//zaladowanie indywidualnego obrazka
SDL_Surface* loadSurface(string path);

// zaladowanie tla
SDL_Texture* loadTexture(string path);

// stworzenie obrazu okna
SDL_Window* gWindow = NULL;

// renderowanie okna
SDL_Renderer* gRenderer = NULL;

// aktualne wyswietlenie tekstury sceny
SDL_Texture* gTexture = NULL;

// Deadpool
SDL_Surface* gWade = NULL;
SDL_Surface* gWade1l = NULL;
SDL_Surface* gWade2l = NULL;
SDL_Surface* gWade1p = NULL;
SDL_Surface* gWade2p = NULL;
// Ajax
SDL_Surface* gAjax = NULL;
// Bloki
SDL_Surface* gBlok = NULL;
SDL_Surface* gBonus1 = NULL;	// serce
SDL_Surface* gBonus2 = NULL;	// +100
SDL_Surface* gBonus3 = NULL;	// +200
SDL_Surface* gBonus4 = NULL;	// dodatkowy Ajax i -200

bool init()
{
	// sprawdzenie poprawnosci
	bool success = true;

	// inicjalizacja SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		// liniowe filtrowanie tekstur?
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		// tworzenie okna
		gWindow = SDL_CreateWindow("Deadpool Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//stworzenie renderowania do okna
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				// ustawienie koloru okna
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				// ladowanie png
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	// sprawdzenie poprawnosci
	bool success = true;

	// zaladowanie tekstury png
	gTexture = loadTexture("tlo.png");
	if (gTexture == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}

	gWade = loadSurface( "dp.bmp" );
	if(gWade == NULL)
	{
		printf( "Failed to load default image!\n" );
		success = false;
	}
	gWade1l = loadSurface("dp1l.bmp");
	if (gWade1l == NULL)
	{
		printf("Failed to load default image!\n");
		success = false;
	}
	gWade2l = loadSurface("dp2l.bmp");
	if (gWade2l == NULL)
	{
		printf("Failed to load default image!\n");
		success = false;
	}
	gWade1p = loadSurface("dp1p.bmp");
	if (gWade1p == NULL)
	{
		printf("Failed to load default image!\n");
		success = false;
	}
	gWade2p = loadSurface("dp2p.bmp");
	if (gWade2p == NULL)
	{
		printf("Failed to load default image!\n");
		success = false;
	}
	gAjax = loadSurface("ajax.bmp");
	if (gAjax == NULL)
	{
		printf("Failed to load default image!\n");
		success = false;
	}
	gBlok = loadSurface("blok.bmp");
	if (gBlok == NULL)
	{
		printf("Failed to load default image!\n");
		success = false;
	}
	gBonus1 = loadSurface("bonus1.bmp");
	if (gBonus1 == NULL)
	{
		printf("Failed to load default image!\n");
		success = false;
	}
	gBonus2 = loadSurface("bonus2.bmp");
	if (gBonus2 == NULL)
	{
		printf("Failed to load default image!\n");
		success = false;
	}
	gBonus3 = loadSurface("bonus3.bmp");
	if (gBonus3 == NULL)
	{
		printf("Failed to load default image!\n");
		success = false;
	}
	gBonus4 = loadSurface("bonus4.bmp");
	if (gBonus4 == NULL)
	{
		printf("Failed to load default image!\n");
		success = false;
	}

	return success;
}

void close()
{
	// zwolnienie obrazu
	SDL_DestroyTexture(gTexture);
	gTexture = NULL;

	// zniszczenie okna	
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	// wylaczenie podsystemow SDL?
	IMG_Quit();
	SDL_Quit();
}

void stworzenieBlokow()
{}

int main(int argc, char* args[])
{
	//zalaczenie SDL i stworzenie okna
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		// zaladowanie plikow
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			// glowna petla?
			bool quit = false;

			// Event handler ???
			SDL_Event e;

			// jesli aplikacja jest wlaczona
			while (!quit)
			{
				//Handle events on queue ??? operowanie wydarzeniami w kolejce?
				while (SDL_PollEvent(&e) != 0)
				{
					// zadanie wylaczenia
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}

				// czyszczenie okna
				SDL_RenderClear(gRenderer);

				// renderowanie tekstury na ekran
				SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);

				// aktualizacja ekranu
				SDL_RenderPresent(gRenderer);
			}
		}
	}

	// zwolnienie plikow i zamkniecie SDL
	close();

	return 0;
}