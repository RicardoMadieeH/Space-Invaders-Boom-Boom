#include "Barrier.h"



Barrier::Barrier()
{
}

void Barrier::setPosition(float xPos, float yPos) {
	this->bBar.setPosition(sf::Vector2f(xPos, yPos));
	this->bBar.setFillColor(sf::Color::White);
	this->bBar.setSize(sf::Vector2f(100, 20));
}
