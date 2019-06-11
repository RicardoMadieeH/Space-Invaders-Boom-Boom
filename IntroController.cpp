#include "IntroController.h"

IntroController::IntroController(IntroView &v) : view(v)
{}

void IntroController::handleEvent(sf::Event &event) {
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Space) {
			finished = true;
		}
	}
}