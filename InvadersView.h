#ifndef INVADERSVIEW_H
#define INVADERSVIEW_H

#include <SFML/Graphics.hpp>
#include "Tank.h"

class InvadersView {
	sf::Clock clk;
	sf::Font font;
	sf::Text txt;
	Tank &tank;
public:
	InvadersView(Tank &t);
	void draw(sf::RenderWindow &win);

	void turnTankLeft();
	void turnTankRight();

	void moveTank();
};




#endif
