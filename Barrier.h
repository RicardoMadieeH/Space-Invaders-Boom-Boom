#ifndef BARRIER_H
#define BARRIER_H

#include "SFML/Graphics.hpp"
#include <iostream>

class Barrier
{
	float xPos;
	float yPos;
	sf::RectangleShape bBar;
	sf::RectangleShape mBar;
	sf::RectangleShape uBar;
public:
	Barrier();

	void setPosition(float xPos, float yPos);
	void getxPos();
	void getyPos();

	void drawTo(sf::RenderWindow &win);

	friend class InvadersView;
};

#endif
