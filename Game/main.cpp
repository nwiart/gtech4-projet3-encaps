#include "Window.h"
#include "WindowRL.h"
#include "WindowSDL.h"

#include "Sprite.h"

#include <iostream>
using namespace std;


enum RenderImplementation
{
	SDL,
	RAYLIB,
};

static RenderImplementation impl =
#if defined(RENDER_SDL)
	SDL;
#elif defined(RENDER_RL)
	RAYLIB;
#else
#	error Wrong configuration, no render implementation selected.
#endif


int parse_cmd_args(int argc, char** argv);


int main(int argc, char** argv)
{
	srand(time(0));

	if (parse_cmd_args(argc, argv) != 0) {
		return 1;
	}

	Window* window = 0;
	switch (impl)
	{
	case SDL:
		window = new WindowSDL();
		break;
	case RAYLIB:
		window = new WindowRL();
		break;
	}

	if (window == 0) {
		cout << "Unexpected error. The window implementation was not created...\n";
		return 2;
	}

	window->initialize();

	window->createWindow(1280, 720, "Bouncing balls");

	Sprite* sprites[6];
	for (int i = 0; i < 6; i++) {
		Sprite* sprite = window->createSprite();
		sprite->loadTexture("pitballs.png");
		sprite->setPosition(rand() / 16, rand() / 16);
		sprite->setSize(80, 80);
		sprites[i] = sprite;
	}

	time_t t0 = 0, t1 = 0;

	while (window->isWindowOpen()) {
		window->processEvents();

		t1 = time(0);
		if (t1 != t0) {
			t0 = t1;
			window->setBackgroundColor(rand() / (float) RAND_MAX, rand() / (float) RAND_MAX, rand() / (float) RAND_MAX);
		}

		window->beginDraw();
		for (int i = 0; i < 6; i++) {
			sprites[i]->setPosition(rand() / 16, rand() / 16);
			window->drawSprite(sprites[i], 0, 0);
		}
		window->endDraw();
	}

	window->quit();

	delete window;
}


int parse_cmd_args(int argc, char** argv)
{
	if (argc == 1) return 0;

	if (strcmp(argv[1], "--sdl") == 0) {
		impl = SDL;
	}
	else if (strcmp(argv[1], "--rl") == 0) {
		impl = RAYLIB;
	}

	return 0;
}
