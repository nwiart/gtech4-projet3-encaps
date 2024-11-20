#include "GameObject.h"

#include "Config.h"
#include "Sprite.h"

#include "Window.h"
#include "Input.h"

#include "math.h"


extern Window* window;


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
	// Integrate.
	velX *= 0.99F;
	velY *= 0.99F;

	velY += 0.2F;

	Input* i = window->getInput();
	if (i->isMouseBtnDown(0)) {
		float dx = posX - i->getMouseX();
		float dy = posY - i->getMouseY();
		float dist = sqrt(dx * dx + dy * dy);
		if (dist <= 500) {
			velX -= (dx / dist) * 4;
			velY -= (dy / dist) * 4;
		}
	}

	posX += velX;
	posY += velY;

	// Collision test against window borders.
	if (posX < 0 || posX > GAME_WIDTH) {
		velX = -velX;
		setVelocity(velX, velY);

		if (posX < 0) posX = 0;
		else posX = GAME_WIDTH;
	}
	if (posY < 0 || posY > GAME_HEIGHT) {
		velY = -velY;
		setVelocity(velX, velY);

		if (posY < 0) posY = 0;
		else posY = GAME_HEIGHT;
	}

	sprite->setPosition(posX, posY);
}
