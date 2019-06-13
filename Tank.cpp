#include "Tank.h"



Tank::Tank()
{
	
	if (!tankTex.loadFromFile("Tank.png")) {
		std::cout << "Error loading texture of tank" << std::endl;
	}

	tank.setTexture(tankTex);
	tank.setScale(sf::Vector2f(0.25, 0.25));

	posX = 341.25;
	
	tank.setPosition(sf::Vector2f(posX, 825));

	
}

void Tank::setTankTexture() {
	if (!tankTex.loadFromFile("Tank.png")) {
		std::cout << "Error loading texture of tank" << std::endl;
	}

	tank.setTexture(tankTex);
	tank.setScale(sf::Vector2f(0.25, 0.25));
}

void Tank::setTankStart() {
	posX = 341.25;

	tank.setPosition(sf::Vector2f(posX, 825));
}

void Tank::turnLeft() {	
	dir = LEFT;
}

void Tank::turnRight() {
	dir = RIGHT;
}

void Tank::stop() {
	dir = STOP;
}

void Tank::move() {
	
	if (dir == LEFT && getPosX() > 0) {
		this->posX = this->posX - 1;
		this->tank.setPosition(sf::Vector2f(posX, 825));
		
	}
	else if (dir == RIGHT && getPosX() < 682) {
		this->posX = this->posX + 1;
		this->tank.setPosition(sf::Vector2f(posX, 825));
	}
	
}

float Tank::getPosX() {
	return this->posX;
}

Direction Tank::getDir() {
	return this->dir;
}

void Tank::drawTo(sf::RenderWindow &win) {
	win.draw(tank);
}

void Tank::updateTank() {
	time = clk.getElapsedTime();
	if (time.asMilliseconds() >= 100 / 15) {
		if (dir != STOP) {
			move();
			updateMissile();
			clk.restart();
		}
	}
}

void Tank::shoot() {
	boom.push_back(new Bullet(posX));
}

void Tank::updateMissile() {
	int j = 0;
	for (auto i : boom) {
		
		i->move();
		if (i->missile.getPosition().y <= 0) {
			boom.erase(boom.begin()+j);
			delete i;
		}
		j++;
	}
}
