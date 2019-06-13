#include "IntroView.h"
#include <cstdlib> // abort()


IntroView::IntroView() {

	if (!font.loadFromFile("/usr/share/fonts/truetype/ubuntu/Ubuntu-B.ttf")) {
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf")) {
			abort();
		}
	}

	//Title on Intro screen settings//
	title.setFont(font);
	title.setString("  Space\nInvaders");
	title.setPosition(170, 0);
	title.setFillColor(sf::Color::White);
	title.setCharacterSize(100);

	//Name on Intro screen settings//
	name.setFont(font);
	name.setString("Michal Grad");
	name.setPosition(5, 5);
	name.setFillColor(sf::Color::White);
	name.setCharacterSize(20);

	//Index on Intro screen settings//
	index.setFont(font);
	index.setString("249306");
	index.setPosition(5, 30);
	index.setFillColor(sf::Color::White);
	index.setCharacterSize(20);

	//Group on Intro screen settings//
	group.setFont(font);
	group.setString("wtorek - 17:15");
	group.setPosition(5, 55);
	group.setFillColor(sf::Color::White);
	group.setCharacterSize(20);

	//Play button settings//
	play = Button("PLAY", { 175,55 }, 75, sf::Color::Black, sf::Color::White, 5, sf::Color::Black);
	play.setPosition(sf::Vector2f(280, 370));
	play.setFont(font);
	play.setTextPosition({ 275,355 });

	//How To Play button settings//
	howToPlay = Button("HOW TO PLAY", { 500, 55 }, 75, sf::Color::Black, sf::Color::White, 5, sf::Color::Black);
	howToPlay.setPosition(sf::Vector2f(125, 450));
	howToPlay.setFont(font);
	howToPlay.setTextPosition(sf::Vector2f(120, 435));

	//Exit button settings//
	exit = Button("EXIT", { 155,47 }, 75, sf::Color::Black, sf::Color::White, 5, sf::Color::Black);
	exit.setPosition(sf::Vector2f(280, 610));
	exit.setFont(font);
	exit.setTextPosition(sf::Vector2f(275, 590));

	//Instructions settings//
	heWannaKnow = Button("Use arrows to steer your tank.\nPress space to shoot.\nDestroy all aliens to win.", { 1,1 }, 20, sf::Color::Black, sf::Color::White, 1, sf::Color::Black);
	heWannaKnow.setPosition(sf::Vector2f(400, 500));
	heWannaKnow.setFont(font);
	heWannaKnow.setTextPosition(sf::Vector2f(430, 800));
}

void IntroView::draw(sf::RenderWindow &win) {

	win.draw(title);
	win.draw(name);
	win.draw(index);
	win.draw(group);
	play.drawTo(win);
	howToPlay.drawTo(win);
	exit.drawTo(win);

	if (doIWannaKnow == true) {
		heWannaKnow.drawTo(win);
	}

}

bool IntroView::doesHeWannaKnow() {
	return doIWannaKnow;
}

void IntroView::seekerOfKnowledge() {
	if (doIWannaKnow == false) {
		doIWannaKnow = true;
	}
	else {
		doIWannaKnow = false;
	}
}