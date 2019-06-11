#ifndef BARRIER_H
#define BARRIER_H

#include "SFML/Graphics.hpp"
#include <iostream>

class Barrier
{
	float xPos;
	float yPos;
	sf::RectangleShape bBar;
	sf::RectangleShape mbar;
	sf::RectangleShape uBar;
public:
	Barrier();

	void setPosition(float xPos, float yPos);
	void getxPos();
	void getyPos();

};

#endif
