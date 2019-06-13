#ifndef INVADERSCONTROLLER_H
#define INVADERSCONTROLLER_H

#include <SFML/Graphics.hpp>
#include "InvadersView.h"

class InvadersController {
	bool finished = false;

	InvadersView & view;
	Tank &tank;
	// ... & model;
	sf::RenderWindow &win;
public:
	explicit InvadersController(InvadersView & v, sf::RenderWindow &w, Tank &t);
public:
	void handleEvent(sf::Event &event);

	// no need to change this
	void draw(sf::RenderWindow & win) { view.draw(win); }
	bool isFinished() const { return finished; }
};



#endif
