#include "Window.h"
#include "WindowRL.h"
#include "WindowSDL.h"

#include "Sprite.h"

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


class GameObject
{
public:

	GameObject() { }
	GameObject(Sprite* s);

	void update();

	inline Sprite* getSprite() const { return sprite; }

	inline void setVelocity(float x, float y) { velX = x; velY = y; }


private:

	Sprite* sprite;
	float posX;
	float posY;
	float velX;
	float velY;
};

GameObject::GameObject(Sprite* s)
	: sprite(s), velX(0.0F), velY(0.0F)
{
	int x, y;
	s->getPosition(x, y);
	posX = x;
	posY = y;
}

void GameObject::update()
{
	posX += velX;
	posY += velY;

	if (posX < 0 || posX >= 1280) {
		velX = -velX;
	}
	if (posY < 0 || posY >= 720) {
		velY = -velY;
	}

	sprite->setPosition(posX, posY);
}


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

	vector<GameObject> objects;

	time_t t0 = 0, t1 = 0;

	while (window->isWindowOpen()) {
		window->processEvents();

		t1 = time(0);
		if (t1 != t0) {
			t0 = t1;
			window->setBackgroundColor(rand() / (float) RAND_MAX, rand() / (float) RAND_MAX, rand() / (float) RAND_MAX);

			Sprite* sprite = window->createSprite();
			sprite->loadTexture("pitballs.png");
			sprite->setPosition(400, 300);
			sprite->setSize(80, 80);

			objects.emplace_back(sprite);
			objects.back().setVelocity((rand() / (float)RAND_MAX - 0.5F) * 20.0F, (rand() / (float)RAND_MAX - 0.5F) * 20.0F);
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
