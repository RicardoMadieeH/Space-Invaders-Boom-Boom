#include "Barrier.h"



Barrier::Barrier(){

}

void Barrier::setPosition(float xPos, float yPos) {
	this->bBar.setPosition(sf::Vector2f(xPos, yPos));
	this->bBar.setFillColor(sf::Color::Green);
	this->bBar.setOutlineThickness(1);
	this->bBar.setOutlineColor(sf::Color::Black);
	this->bBar.setSize(sf::Vector2f(75, 15));

	this->mBar.setPosition(sf::Vector2f(xPos, yPos-15));
	this->mBar.setFillColor(sf::Color::Green);
	this->mBar.setOutlineThickness(1);
	this->mBar.setOutlineColor(sf::Color::Black);
	this->mBar.setSize(sf::Vector2f(75, 15));

	this->uBar.setPosition(sf::Vector2f(xPos, yPos-30));
	this->uBar.setFillColor(sf::Color::Green);
	this->uBar.setOutlineThickness(1);
	this->uBar.setOutlineColor(sf::Color::Black);
	this->uBar.setSize(sf::Vector2f(75, 15));

}

void Barrier::drawTo(sf::RenderWindow &win) {
	win.draw(bBar);
	win.draw(mBar);
	win.draw(uBar);
}