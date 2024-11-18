#include "GameObject.h"

#include "Config.h"
#include "Sprite.h"


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
	posX += velX;
	posY += velY;

	// Collision test against window borders.
	if (posX < 0 || posX >= GAME_WIDTH) {
		velX = -velX;
	}
	if (posY < 0 || posY >= GAME_HEIGHT) {
		velY = -velY;
	}

	sprite->setPosition(posX, posY);
}
