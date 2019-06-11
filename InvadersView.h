#ifndef INVADERSVIEW_H
#define INVADERSVIEW_H

#include <SFML/Graphics.hpp>

class InvadersView {
	sf::Clock clk;
	sf::Font font;
	sf::Text txt;
public:
	void draw(sf::RenderWindow &win);
};




#endif
