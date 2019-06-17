#include "Fleet.h"



Fleet::Fleet(){
	yFleet = 0;
	xFleet = 10;

	if (!alienTex.loadFromFile("Alien.png")) {
		std::cout << "Error loading texture of alien" << std::endl;
		abort();
	}

	int j = 0;
	for (int k = 0; k <= 64; k++) {
		fleet.push_front(new Alien(xFleet, yFleet, alienTex));
		xFleet = xFleet + 50;
		j++;
		if (j % 13 == 0) {
			yFleet = yFleet + 35;
			xFleet = 10;
		}
	}
}

void Fleet::startFleet() {
	if (stat == STAY) {
		stat = PLAY;
	}
	
}

void Fleet::drawTo(sf::RenderWindow &win) {
	for (auto i : fleet) {
		i->drawTo(win);
	}
}

void Fleet::dirLeft() {
	dir = LT;
}

void Fleet::dirRight() {
	dir = RT;
}

void Fleet::fallDown() {
	for (auto i : fleet) {
		i->alien.move(sf::Vector2f(0, 4));
	}
}

void Fleet::move() {
	if (dir == LT) {
		for (auto i : fleet) {
			i->alien.move(sf::Vector2f(-1, 0));
			if (i->alien.getPosition().x < 3) {
				fallDown();
				dirRight();
				break;
			}
		}
	}
	else if (dir == RT) {
		for (auto i : fleet) {
			if (i->alien.getPosition().x > 675) {
				fallDown();
				dirLeft();
				break;
			}
			i->alien.move(sf::Vector2f(1, 0));
		}
	}
}

void Fleet::updateFleet() {
	ftime = fclk.getElapsedTime();
	if (ftime.asMilliseconds() >= 250 / 15) {
		if (stat == PLAY) {
			move();
			fclk.restart();
		}
	}
}



















