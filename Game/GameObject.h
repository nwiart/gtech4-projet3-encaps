#pragma once

class Sprite;


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
