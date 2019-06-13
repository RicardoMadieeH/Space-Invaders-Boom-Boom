#ifndef INTROVIEW_H
#define INTROVIEW_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Button.h"

class IntroView {

	sf::Font font;

	sf::Text title;
	sf::Text name;
	sf::Text index;
	sf::Text group;
	bool doIWannaKnow = false;

public:
	bool doesHeWannaKnow();
	void seekerOfKnowledge();

	Button play;
	Button howToPlay;
	Button exit;
	Button heWannaKnow;

	IntroView();

	void draw(sf::RenderWindow &win);
};


#endif