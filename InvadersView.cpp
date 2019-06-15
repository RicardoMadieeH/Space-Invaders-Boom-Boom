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
	tank.drawTo(win);
	for (auto i : tank.boom) {
		i->drawTo(win);
	}
	for (auto i : fleet.fleet) {
		i->drawTo(win);
	}
	
}


