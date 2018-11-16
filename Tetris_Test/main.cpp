#include "Game.h"
#include <iostream>
#include<SDL_mixer.h>

static const char *Main = "Asset/Main.mp3";

int main(int argc, char *args[])
{
	int result = 0;
	int flags = MIX_INIT_MP3;

	if (SDL_Init(SDL_INIT_AUDIO) < 0) {
		printf("Failed to init SDL\n");
		exit(1);
	}

	if (flags != (result = Mix_Init(flags))) {
		printf("Could not initialize mixer (result: %d).\n", result);
		printf("Mix_Init: %s\n", Mix_GetError());
		exit(1);
	}

	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
	Mix_Music *music = Mix_LoadMUS(Main);
	Mix_PlayMusic(music, -1);


	Game game;
	while (game.Start());
	return 0;
}