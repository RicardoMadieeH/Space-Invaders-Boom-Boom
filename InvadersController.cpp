#include "InvadersController.h"

InvadersController::InvadersController(InvadersView &v, sf::RenderWindow &w, Tank &t) :view(v), tank(t), win(w)
{}

void InvadersController::handleEvent(sf::Event &event) {
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Escape) {
			finished = true;
		}

		if (event.key.code == sf::Keyboard::Space) {
			tank.shooting = true;
			tank.shoot();
		}
		
		if (event.key.code == sf::Keyboard::Left && tank.getPosX() > 0) {
			tank.turnLeft();
		}
		else if (event.key.code == sf::Keyboard::Right && tank.getPosX() < 682) {
			tank.turnRight();
		}
		else {
			tank.stop();
		}
	}
	else {
		tank.stop();
	}
}