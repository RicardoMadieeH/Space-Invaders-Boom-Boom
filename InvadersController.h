#ifndef MINESWEEPERCONTROLLER_H
#define MINESWEEPERCONTROLLER_H

#include <SFML/Graphics.hpp>
#include "InvadersView.h"

class InvadersController {
	bool finished = false;

	InvadersView & view;
	// ... & model;
public:
	explicit InvadersController(InvadersView & v);
public:
	void handleEvent(sf::Event &event);

	// no need to change this
	void draw(sf::RenderWindow & win) { view.draw(win); }
	bool isFinished() const { return finished; }
};



#endif // MINESWEEPERCONTROLLER_H
