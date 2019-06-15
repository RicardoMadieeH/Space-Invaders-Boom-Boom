#ifndef INVADERSVIEW_H
#define INVADERSVIEW_H

#include <SFML/Graphics.hpp>
#include "Tank.h"
#include "Fleet.h"

class InvadersView {
	sf::Clock clk;
	sf::Font font;
	sf::Text txt;
	Tank &tank;
	Fleet &fleet;
public:
	InvadersView(Tank &t, Fleet &f);
	void draw(sf::RenderWindow &win);

	void turnTankLeft();
	void turnTankRight();

	void moveTank();
};




#endif
