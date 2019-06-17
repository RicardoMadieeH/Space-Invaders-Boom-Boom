#ifndef BULLET_H
#define BULLET_H


#include "SFML/Graphics.hpp"
#include "iostream"


class Bullet
{
	sf::Sprite missile;
	sf::Texture missileTex;


public:
	Bullet(float xPos);
	
	void move();

	void drawTo(sf::RenderWindow &win);

	friend class Tank;
	friend class Alien;
	friend class InvadersView;
};

#endif