#ifndef FLEET_H
#define FLEET_H

#include "SFML/Graphics.hpp"
#include "Alien.h"
#include <deque>
#include <iostream>
#include <ctime>
#include <cstdlib>

enum State {STAY, PLAY};
enum Direct {LT, RT};

class Fleet
{
	std::deque<Alien*>fleet;
	Direct dir;
	float yFleet;
	float xFleet;
	State stat = STAY;

	sf::Clock fclk;
	sf::Time ftime;

	sf::Texture alienTex;

public:
	Fleet();
	void dirLeft();
	void dirRight();
	void fallDown();
	void startFleet();
	void move();

	void updateFleet();

	void drawTo(sf::RenderWindow &win);

	friend class InvadersView;
};

#endif