#include "Bullet.h"



Bullet::Bullet(float xPos, float yPos, sf::Texture &tex) {
	//if (!missileTex.loadFromFile("Missile.png")) {
	//	std::cout << "Error loading texture of missile" << std::endl;
	//	abort();
	//}

	missile.setTexture(tex);
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
	if (missile.getPosition().y >= 10 && missile.getPosition().y <= 840) {
		if (&missile != nullptr) {
			win.draw(missile);
		}
		
		
	}
}