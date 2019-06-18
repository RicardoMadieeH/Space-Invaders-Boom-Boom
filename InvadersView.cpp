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
	//shotDown();
	tank.drawTo(win);
	for (auto i : tank.boom) {
		if (tank.boom.size() > 0) i->drawTo(win);
	}
	for (auto j : fleet.fleet) {
		if (fleet.fleet.size() > 0) j->drawTo(win);
	}
	for (auto k : defense.def) {
		if (defense.def.size() > 0) k->drawTo(win);
	}
	for (auto l : fleet.poof) {
		if (fleet.poof.size() > 0) l->drawTo(win);
	}
	shotDown();

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
	
	for (size_t i = 0; i < tank.boom.size(); i++) {
		for (size_t j = 0; j < fleet.fleet.size(); j++) {
			if (alienCollision(i, j)) {
				delete tank.boom[i];
				tank.boom.erase(tank.boom.begin() + i);

				delete fleet.fleet[j];
				fleet.fleet.erase(fleet.fleet.begin() + j);
			}
		}
	}

	k = 0;
	h = 0;
	for (auto &i : defense.def) {
		h = 0;
		for (auto &j : tank.boom) {
			if (i->bBar.getGlobalBounds().intersects(j->missile.getGlobalBounds())) {

				delete j;
				//j = nullptr;
				tank.boom.erase(tank.boom.begin() + h);
			}
			h++;
		}
	}
	k = 0;
	h = 0;
	for (auto i : fleet.poof) {
		if (i->missile.getGlobalBounds().intersects(tank.tank.getGlobalBounds())) {
			findef = true;
		}
	}
	k = 0;
	h = 0;
	
	for (auto i : fleet.poof) {
		h = 0;
		for (auto j : tank.boom) {
			if (fleet.poof.size() > 0 && tank.boom.size() > 0 && i->missile.getGlobalBounds().intersects(j->missile.getGlobalBounds())) {

			//delete j;
			//tank.boom.erase(tank.boom.begin() + h);
			//if (&i != nullptr) delete i;
			//fleet.poof.erase(fleet.poof.begin() + k);
				i->missile.setScale(0, 0);
				j->missile.setScale(0, 0);
			}
			h++;
		}
		k++;
	}
	
	k = 0;
	h = 0;
	for (auto i : fleet.poof) {
		h = 0;
		for (auto j : defense.def) {
			if (/*h < fleet.poof.size() &&*/ i != nullptr && j != nullptr && i->missile.getGlobalBounds().intersects(j->uBar.getGlobalBounds())) {
				//i->missile.setScale(0, 0);
				//delete i;
				//i = nullptr;
				//fleet.poof.erase(fleet.poof.begin() + h);
				j->uBar.setSize(sf::Vector2f(0, 0));
				i->missile.setScale(0, 0);
			}
			else if (/*h < fleet.poof.size() &&*/ i->missile.getGlobalBounds().intersects(j->mBar.getGlobalBounds())) {
				//i->missile.setScale(0, 0);
				//delete i;
				//i = nullptr;
				//fleet.poof.erase(fleet.poof.begin() + h);
				j->mBar.setSize(sf::Vector2f(0, 0));
				i->missile.setScale(0, 0);
			}
			else if (/*h < fleet.poof.size() &&*/ i->missile.getGlobalBounds().intersects(j->bBar.getGlobalBounds())) {
				//i->missile.setScale(0, 0);
				//delete i;
				//i = nullptr;
				//fleet.poof.erase(fleet.poof.begin() + h);
				j->bBar.setSize(sf::Vector2f(0, 0));
				i->missile.setScale(0, 0);
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


bool InvadersView::alienCollision(size_t i, size_t j) {
	/*
	int h;
	int k = 0;
	for (auto &i : tank.boom) {
		h = 0;
		for (auto &j : fleet.fleet) {
			if (i->missile.getGlobalBounds().intersects(j->alien.getGlobalBounds())) {

				delete i;
				tank.boom.erase(tank.boom.begin() + k);

				delete j;
				fleet.poof.erase(fleet.poof.begin() + h);
			}
			h++;
		}
		k++;
	}
	*/

	return tank.boom.size() > 0 && i < tank.boom.size() ? tank.boom[i]->missile.getGlobalBounds().intersects(fleet.fleet[j]->alien.getGlobalBounds()) ? true : false : false;
}