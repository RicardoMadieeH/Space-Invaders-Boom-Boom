#include "InvadersView.h"


InvadersView::InvadersView(Tank &t, Fleet &f, Defense &d) :tank(t), fleet(f), defense(d){
	//this->tank = Tank();
	//tank.setTankTexture();
	//tank.setTankStart();
	if (!font.loadFromFile("/usr/share/fonts/truetype/ubuntu/Ubuntu-B.ttf")) {
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf")) {
			abort();
		}
	}

	vic.setCharacterSize(100);
	vic.setFillColor(sf::Color::White);
	vic.setFont(font);
	vic.setPosition(sf::Vector2f(150, 400));
	vic.setString("VICTORY");

	defeat.setCharacterSize(100);
	defeat.setFillColor(sf::Color::White);
	defeat.setFont(font);
	defeat.setPosition(sf::Vector2f(175, 400));
	defeat.setString("DEFEAT");
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
	for (auto i : defense.def) {
		i->drawTo(win);
	}

	updateState();
	if (finvic == true) {
		win.draw(vic);
	}
	else if (findef == true) {
		win.draw(defeat);
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

void InvadersView::updateState() {
	if (fleet.fleet.size() == 0) {
		finvic = true;
	}
	
	for (auto i : fleet.fleet) {
		if (i->alien.getPosition().y >= 850) {
			findef = true;
			break;
		}
	}
}


