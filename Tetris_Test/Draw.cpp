#include "Draw.h"

Draw::Draw() : data{ {false} } {}

void Draw::draw(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	for(int x = 0 ; x < W ; ++x)
		for (int y = 0; y < H; ++y)
		{
			if (data[x][y])
			{
				SDL_Rect rect{ x * 720 / 2 / 10 + 1, y * 720 / 2 / 10 + 1, 720 / 2 / 10 - 2, 720 / 2 / 10 - 2 };
				SDL_RenderFillRect(renderer, &rect);
			}
			else
				SDL_RenderDrawPoint(renderer, x * 720 / 2 / 10 + 720 / 2 / 10 / 2,
					y * 720 / 2 / 10 + 720 / 2 / 10 / 2);
		}
}

void Draw::unite( Tetris &t)
{
	for(int x = 0 ; x < 4; ++x)
		for(int y = 0 ; y < 4 ; ++y)
			if (t.block(x, y))
			{
				data[t.x() + x][t.y() + y] = true;
			}
}

void Draw::clearline()
{
	for (int y = H - 1; y >= 0; --y)
	{
		bool Sol = true;
		for (int x = 0; x < W; ++x)
			if (!data[x][y])
			{
				Sol = false;
				break;
			}
		if (Sol)
		{
			for (int j = y - 1; j >= 0; --j)
				for (int k = 0; k < W; ++k)
					data[k][j + 1] = data[k][j];
			for (int k = 0; k < W; ++k)
				data[k][0] = false;
		}
	}
}


bool Draw::Collision( Tetris &t) 
{
	for(int x = 0 ; x < 4 ; ++x)
		for (int y = 0; y < 4; ++y)
		{
			if (t.block(x, y))
			{
				int cx = t.x() + x;
				int cy = t.y() + y;
				if (cx < 0 || cx >= W || cy < 0 || cy >= H)
				{
					return true;
				}
				if (data[cx][cy])
					return true;
			}
		}
	return false;
}