#include "Alien.h"



Alien::Alien(float x, float y){
	if (!alienTex.loadFromFile("Alien.png")) {
		std::cout << "Error loading texture of alien" << std::endl;
		abort();
	}
	alien.setTexture(alienTex);
	alien.setScale(sf::Vector2f(0.025, 0.025));

	xPos = x;
	yPos = y;
	alien.setPosition(sf::Vector2f(x, y));
}

float Alien::getxPos() {
	return this->xPos;
}

float Alien::getyPos() {
	return this->yPos;
}

Dir Alien::getDirection() {
	return this->dir;
}

void Alien::move() {
	if (dir == L && getxPos() > 0) {
		this->xPos = this->xPos - 1;
		this->alien.setPosition(sf::Vector2f(xPos, yPos));
	}
	else if (dir == R && getxPos() < 682) {
		this->xPos = xPos + 1;
		this->alien.setPosition(sf::Vector2f(xPos, yPos));
	}
}





void Alien::drawTo(sf::RenderWindow &win) {
	win.draw(alien);
}