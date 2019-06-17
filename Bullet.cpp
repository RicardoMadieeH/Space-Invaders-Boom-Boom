#include "Bullet.h"



Bullet::Bullet(float xPos, float yPos) {
	if (!missileTex.loadFromFile("Missile.png")) {
		std::cout << "Error loading texture of missile" << std::endl;
		abort();
	}

	missile.setTexture(missileTex);
	missile.setScale(sf::Vector2f(0.3, 0.3));

	missile.setPosition(sf::Vector2f(xPos, yPos));
}


void Bullet::move() {
	missile.move(sf::Vector2f(0, -1));
}

void Bullet::moveDown() {
	missile.move(sf::Vector2f(0, 1));
}


void Bullet::drawTo(sf::RenderWindow &win) {
	win.draw(missile);
}