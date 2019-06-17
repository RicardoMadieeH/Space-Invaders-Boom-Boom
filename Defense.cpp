#include "Defense.h"



Defense::Defense(){
	for (int i = 0; i <= 3; i++) {
		def.push_back(new Barrier);
	}

	int xPos = 50;
	for (auto i : def) {
		i->setPosition(xPos, 800);
		xPos = xPos + 180;
	}
}

void Defense::drawTo(sf::RenderWindow &win) {
	for (auto i : def) {
		i->drawTo(win);
	}
}
