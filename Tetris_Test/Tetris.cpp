#include "Tetris.h"

Tetris::Tetris(Kind kind) : g_kind(kind), g_x(10 / 2 - 4 / 2), g_y(0), g_angle(0) {}



void Tetris::draw(SDL_Renderer *renderer)
{
	switch (g_kind)
	{
	case Tetris::A:
		SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
		break;
	case Tetris::B:
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		break;
	case Tetris::C:
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		break;
	case Tetris::D:
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		break;
	case Tetris::E:
		SDL_SetRenderDrawColor(renderer, 0, 255, 100, 255);
		break;
	case Tetris::F:
		SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
		break;
	case Tetris::G:
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		break;
	}
	for (int j = 0; j < 4 ; ++j)
		for(int k = 0 ; k < 4 ; ++k)
			if (block(j, k))
			{
				SDL_Rect rect{ (j + g_x) * 720 / 2 / 10 + 1, (k + g_y) * 720 / 2 / 10 + 1, 720 / 2 / 10 - 2, 720 / 2 / 10 - 2 };
				SDL_RenderFillRect(renderer, &rect);
			}
}

void Tetris::move(int move_x, int move_y)
{
	g_x += move_x;
	g_y += move_y;
}

void Tetris::rotate()
{
	g_angle += 3;
	g_angle %= 4;
}

int Tetris::x() 
{
	return g_x;
}

int Tetris::y() 
{
	return g_y;
}

bool Tetris::block(int x, int y) 
{
	static const char *form[][4] = {
		{
		" *  "
		" *  "
		" *  "
		" *  ",

		"    "
		"****"
		"    "
		"    ",

		" *  "
		" *  "
		" *  "
		" *  ",

		"    "
		"****"
		"    "
		"    ",

		},
	{
		"  * "
		"  * "
		" ** "
		"    ",

		"    "
		"*   "
		"*** "
		"    ",

		" ** "
		" *  "
		" *  "
		"    ",

		"    "
		"    "
		"*** "
		"  * ",

	},
	{
		" *  "
		" *  "
		" ** "
		"    ",

		"    "
		"*** "
		"*   "
		"    ",

		" ** "
		"  * "
		"  * "
		"    ",

		"  * "
		"*** "
		"    "
		"    ",

	},
	{
		"    "
		" ** "
		" ** "
		"    ",

		"    "
		" ** "
		" ** "
		"    ",

		"    "
		" ** "
		" ** "
		"    ",

		"    "
		" ** "
		" ** "
		"    ",

	},
	{
		"  * "
		" ** "
		" *  "
		"    ",

		"    "
		"**  "
		" ** "
		"    ",

		"  * "
		" ** "
		" *  "
		"    ",

		"    "
		"**  "
		" ** "
		"    ",

	},
	{
		" *  "
		" ** "
		" *  "
		"    ",

		"    "
		"*** "
		" *  "
		"    ",

		" *  "
		"**  "
		" *  "
		"    ",

		" *  "
		"*** "
		"    "
		"    ",

	},
	{
		" *  "
		" ** "
		"  * "
		"    ",

		"    "
		" ** "
		"**  "
		"    ",

		" *  "
		" ** "
		"  * "
		"    ",

		"    "
		" ** "
		"**  "
		"    ",

	},
	};
	return form[g_kind][g_angle][x + y * 4] == '*';
}