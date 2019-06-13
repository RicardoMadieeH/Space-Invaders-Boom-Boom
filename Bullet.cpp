#include "Bullet.h"



Bullet::Bullet(float xPos) {
	if (!missileTex.loadFromFile("Missile.png")) {
		std::cout << "Error loading texture of missile" << std::endl;
	}

	missile.setTexture(missileTex);
	missile.setScale(sf::Vector2f(0.3, 0.3));

	missile.setPosition(sf::Vector2f(xPos+7, 830));
}


void Bullet::move() {
	missile.move(sf::Vector2f(0, -1));
}


void Bullet::drawTo(sf::RenderWindow &win) {
	win.draw(missile);
}