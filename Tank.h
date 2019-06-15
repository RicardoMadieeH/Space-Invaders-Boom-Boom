#ifndef TANK_H
#define TANK_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <deque>
#include "Bullet.h"

enum Direction {STOP, LEFT, RIGHT};

class Tank{
	sf::Sprite tank;
	sf::Texture tankTex;
	Direction dir = STOP;
	float posX;
	

	sf::Clock clk;
	sf::Time time;

	std::deque<Bullet*> boom;

public:
	Tank();

	void setTankTexture();
	void setTankStart();

	void shoot();
	void move();
	void updateTank();

	void updateMissile();

	float getPosX();
	Direction getDir();

	void turnLeft();
	void turnRight();
	void stop();

	void drawTo(sf::RenderWindow &win);

	friend class InvadersController;
	friend class Bullet;
	friend class InvadersView;
};

#endif