#pragma once
#include <SDL.h>
#include "Tetris.h"

class Draw
{
public:
	Draw();
	void draw(SDL_Renderer *);
	bool Collision( Tetris &t);
	void unite( Tetris &);
	void clearline();
	enum { W = 10, H = 20 };
private:
	bool data[W][H];
};