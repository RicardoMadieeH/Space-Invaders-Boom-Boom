#include "InvadersController.h"

InvadersController::InvadersController(InvadersView &v) :view(v)
{}

void InvadersController::handleEvent(sf::Event &event) {
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Space) {
			finished = true;
		}
	}
}