#ifndef ALIEN_H
#define ALIEN_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include <deque>
#include "Bullet.h"

enum Dir {L, R};

class Alien
{
	sf::Texture alienTex;
	sf::Sprite alien;
	Dir dir = R;
	float xPos;
	float yPos;

	sf::Clock clock;
	sf::Time t;

public:
	Alien(float x, float y, sf::Texture &alienTex);

	void move();
	
	float getxPos();
	float getyPos();
	Dir getDirection();


	void drawTo(sf::RenderWindow &win);

	friend class Fleet;
	friend class InvadersView;
};

#endif