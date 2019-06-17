#include "InvadersView.h"


InvadersView::InvadersView(Tank &t, Fleet &f) :tank(t), fleet(f){
	//this->tank = Tank();
	//tank.setTankTexture();
	//tank.setTankStart();
}

void InvadersView::turnTankLeft() {
	this->tank.turnLeft();
}

void InvadersView::turnTankRight() {
	this->tank.turnRight();
}

void InvadersView::moveTank() {
	this->tank.move();
}


void InvadersView::draw(sf::RenderWindow &win) {
	fleet.startFleet();
	shotDown();
	tank.drawTo(win);
	for (auto i : tank.boom) {
		i->drawTo(win);
	}
	for (auto i : fleet.fleet) {
		i->drawTo(win);
	}
	
}

void InvadersView::shotDown() {
	int k = 0;
	int h;
	for (auto i : fleet.fleet) {
		h = 0;
		for (auto j : tank.boom) {
			if (i->alien.getGlobalBounds().intersects(j->missile.getGlobalBounds())) {
				fleet.fleet.erase(fleet.fleet.begin() + k);
				delete i;
				tank.boom.erase(tank.boom.begin() + h);
				delete j;
			}
			h++;
		}
		k++;
	}
}


