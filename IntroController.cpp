#include "IntroController.h"

IntroController::IntroController(IntroView &v, sf::RenderWindow &w) : view(v), win(w)
{}

void IntroController::handleEvent(sf::Event &event) {

	if (event.type == sf::Event::EventType::MouseMoved) {
		if (view.play.isMouseOver(win)) {
			view.play.setTextColor(sf::Color(10, 170, 180));
		}
		else {
			view.play.setTextColor(sf::Color::White);
		}

		if (view.howToPlay.isMouseOver(win)) {
			view.howToPlay.setTextColor(sf::Color(10, 170, 180));
		}
		else {
			view.howToPlay.setTextColor(sf::Color::White);
		}

		if (view.exit.isMouseOver(win)) {
			view.exit.setTextColor(sf::Color(10, 170, 180));
		}
		else {
			view.exit.setTextColor(sf::Color::White);
		}
	}

	if (event.type == sf::Event::EventType::MouseButtonPressed) {
		if (view.play.isMouseOver(win)) {
			finished = true;
		}

		if (view.howToPlay.isMouseOver(win)) {
			view.seekerOfKnowledge();
		}

		if (view.exit.isMouseOver(win)) {
			win.close();
		}
	}
}
