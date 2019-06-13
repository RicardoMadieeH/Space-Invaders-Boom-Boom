#ifndef INTROCONTROLLER_H
#define INTROCONTROLLER_H

#include <SFML/Graphics.hpp>
#include "IntroView.h"

class IntroController {
	bool finished = false;
	IntroView & view;
	sf::RenderWindow &win;
	// IntroModel & model;
public:
	explicit IntroController(IntroView & iv, sf::RenderWindow &w);

	void handleEvent(sf::Event &event);

	// no need to change this
	void draw(sf::RenderWindow & win) { view.draw(win); }
	bool isFinished() const { return finished; }
	bool resetState() { finished = false; return finished; }
};


#endif