#pragma once
#include <SDL.h>

class Tetris
{
public:

	enum Kind { A = 0, B, C, D, E, F, G };

	Tetris(Kind);

	void draw(SDL_Renderer *);
	void move(int move_x, int move_y);
	void rotate();
	bool block(int x, int y) ;
	int x() ;
	int	y() ;

private:
	Kind g_kind;
	int g_x;
	int g_y;
	int g_angle; //0도 , 90도 , 180도, 270도
};