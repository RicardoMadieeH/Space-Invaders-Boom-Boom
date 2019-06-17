#ifndef INVADERSVIEW_H
#define INVADERSVIEW_H

#include <SFML/Graphics.hpp>
#include "Tank.h"
#include "Fleet.h"
#include "Defense.h"

class InvadersView {
	sf::Clock clk;
	sf::Font font;
	sf::Text txt;
	Tank &tank;
	Fleet &fleet;
	Defense &defense;

	sf::Text vic;
	sf::Text defeat;

	bool finvic = false;
	bool findef = false;
public:
	InvadersView(Tank &t, Fleet &f, Defense &d);
	void draw(sf::RenderWindow &win);

	void turnTankLeft();
	void turnTankRight();

	void moveTank();

	void shotDown();

	void updateState();

	friend class InvadersController;
};




#endif
