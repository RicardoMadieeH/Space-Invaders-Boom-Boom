#include "IntroView.h"
#include <cstdlib> // abort()


IntroView::IntroView() {
	rect.setSize(sf::Vector2f(100, 100));
	rect.setPosition(100, 100);

	if (!font.loadFromFile("/usr/share/fonts/truetype/ubuntu/Ubuntu-B.ttf")) {
		abort();
	}
	txt.setFont(font);
	txt.setString("Intro");
	txt.setPosition(50, 50);
	txt.setFillColor(sf::Color::Red);
	txt.setCharacterSize(20);
}

void IntroView::draw(sf::RenderWindow &win) {
	win.draw(rect);
	win.draw(txt);
}