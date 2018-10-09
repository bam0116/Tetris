#include "game.h"
#include <iostream>

//찾은정보 static_cast
Game::Game() :g_tetris{ static_cast<Tetris::Kind>(rand() % 7) }, g_moveTime(SDL_GetTicks())
{
	SDL_CreateWindowAndRenderer(720 / 2, 720, SDL_WINDOW_OPENGL | SDL_WINDOW_BORDERLESS, &g_window, &g_renderer);
	SDL_SetWindowPosition(g_window, 65, 126);

}

Game::~Game()
{
	SDL_DestroyRenderer(g_renderer);
	SDL_DestroyWindow(g_window);
	SDL_Quit();
}

bool Game::Start()
{
	SDL_Event e;
	if (SDL_WaitEventTimeout(&e, 250))
	{
		switch (e.type)
		{
		case SDL_KEYDOWN:
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_DOWN:
			{
				Tetris t = g_tetris;
				t.move(0, 1);
				if (!g_draw.Collision(t))
					g_tetris = t;
			}
			break;
			case SDLK_RIGHT:
			{
				Tetris t = g_tetris;
				t.move(1, 0);
				if (!g_draw.Collision(t))
					g_tetris = t;
			}
			break;
			case SDLK_LEFT:
			{
				Tetris t = g_tetris;
				t.move(-1, 0);
				if (!g_draw.Collision(t))
					g_tetris = t;
			}
			break;
			case SDLK_UP:
			{
				Tetris t = g_tetris;
				t.rotate();
				if (!g_draw.Collision(t))
					g_tetris = t;
			}
			break;
			}
		}
		break;
		case SDL_QUIT:
			return false;
	}	
	}
	SDL_SetRenderDrawColor(g_renderer, 0, 0, 0, 255);
	SDL_RenderClear(g_renderer);
	g_draw.draw(g_renderer);
	g_tetris.draw(g_renderer);
	if (SDL_GetTicks() > g_moveTime)
	{
		g_moveTime += 1000;
		Tetris t = g_tetris;
		t.move(0, 1);
		Check(t);
	}
	SDL_RenderPresent(g_renderer);
	return true;
}

void Game::Check( Tetris &t)
{
	if (g_draw.Collision(t))
	{
		g_draw.unite(g_tetris);
		g_tetris = Tetris(static_cast<Tetris::Kind>(rand() % 7));
		if (g_draw.Collision(g_tetris))
		{
			g_draw = Draw();
		}
	}
	else
	{
		g_tetris = t;
	}
}