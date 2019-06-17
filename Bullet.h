#ifndef BULLET_H
#define BULLET_H


#include "SFML/Graphics.hpp"
#include "iostream"


class Bullet
{
	sf::Sprite missile;
	sf::Texture missileTex;


public:
	Bullet(float xPos, float yPos);
	
	void move();
	void moveDown();

	void drawTo(sf::RenderWindow &win);

	friend class Tank;
	friend class Alien;
	friend class InvadersView;
	friend class Fleet;
};

#endif