#include "InvadersView.h"


InvadersView::InvadersView(Tank &t) :tank(t){
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
	tank.drawTo(win);
	for (auto i : tank.boom) {
		i->drawTo(win);
	}
}


