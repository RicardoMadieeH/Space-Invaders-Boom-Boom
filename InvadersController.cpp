#include "InvadersController.h"

InvadersController::InvadersController(InvadersView &v, sf::RenderWindow &w, Tank &t) :view(v), tank(t), win(w)
{}

void InvadersController::handleEvent(sf::Event &event) {
	
	if (event.type == sf::Event::KeyPressed) {
		if (view.finvic == true && event.key.code == sf::Keyboard::Return) {
			finished = true;
		}

		if (event.key.code == sf::Keyboard::Space) {
			tank.shoot();
		}
		
		if (event.key.code == sf::Keyboard::Left && tank.getPosX() > 0) {
			tank.turnLeft();
		}
		else if (event.key.code == sf::Keyboard::Right && tank.getPosX() < 682) {
			tank.turnRight();
		}
	}
	else {
		tank.stop();
	}
	
	/*
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		tank.turnLeft();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		tank.turnRight();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		tank.shoot();
	}
	*/
	
}