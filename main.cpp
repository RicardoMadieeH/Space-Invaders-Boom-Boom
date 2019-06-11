#include <iostream>
#include "SFML/Graphics.hpp"

#include "Alien.h"
#include "Barrier.h"
#include "Tank.h"

#include "GameManager.h"
#include "IntroView.h"
#include "IntroController.h"
#include "InvadersView.h"
#include "InvadersController.h"
#include "ScoreView.h"
#include "ScoreController.h"

#include "Button.h"

int main() {

	sf::RenderWindow win(sf::VideoMode(1280, 720), "Ultimate Snook v9001", sf::Style::Titlebar | sf::Style::Close);

	win.setFramerateLimit(60);

	IntroView iv;
	IntroController ic(iv);

	InvadersView invv;
	InvadersController invc(invv);

	ScoreView sv;
	ScoreController sc(sv);

	GameManager gm(ic, invc, sc);
	

	// Start the game loop
	while (win.isOpen()) {
		// Process events
		sf::Event event;
		while (win.pollEvent(event)) {
			// Close window : exit
			if (event.type == sf::Event::Closed) {
				win.close();
			}

			gm.handleEvent(event);

		}
		
		// Clear screen
		win.clear();

		// Draw current state
		gm.draw(win);

		// Update the window
		win.display();
	}



	return 0;
}