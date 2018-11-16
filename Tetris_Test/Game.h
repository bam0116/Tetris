#pragma once

#include<SDL.h>
#include "Tetris.h"
#include "Draw.h"


class Game
{
public:
	Game();
	~Game();
	bool Start();
private:
	Game(const Game &);
	SDL_Window *g_window;
	SDL_Renderer *g_renderer;
	Draw g_draw;
	Tetris g_tetris;
	uint32_t g_moveTime;// SDL_GetTicks를사용하기위해
	void Check( Tetris &);
};