#include "Window.h"
#include "WindowRL.h"
#include "WindowSDL.h"

#include "Sprite.h"

#include "Config.h"
#include "GameObject.h"

#include <iostream>
#include <vector>
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


Window* window = 0;
vector<GameObject> objects;


int parse_cmd_args(int argc, char** argv);

void spawn_random_object();


int main(int argc, char** argv)
{
	srand(time(0));

	if (parse_cmd_args(argc, argv) != 0) {
		return 1;
	}

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
	window->createWindow(GAME_WIDTH, GAME_HEIGHT, "Bouncing balls");

	time_t t0 = 0, t1 = 0;

	while (window->isWindowOpen()) {
		window->processEvents();

		t1 = time(0);
		if (t1 != t0) {
			t0 = t1;
			window->setBackgroundColor(rand() / (float) RAND_MAX, rand() / (float) RAND_MAX, rand() / (float) RAND_MAX);

			spawn_random_object();
		}

		window->beginDraw();
		for (GameObject& obj : objects) {
			obj.update();
			window->drawSprite(obj.getSprite(), 0, 0);
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

void spawn_random_object()
{
	Sprite* sprite = window->createSprite();
	sprite->loadTexture("pitballs.png");
	sprite->setPosition(400, 300);
	sprite->setSize(80, 80);

	objects.emplace_back(sprite);
	objects.back().setVelocity((rand() / (float)RAND_MAX - 0.5F) * 20.0F, (rand() / (float)RAND_MAX - 0.5F) * 20.0F);
}
