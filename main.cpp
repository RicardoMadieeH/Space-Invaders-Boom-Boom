#include <iostream>
#include "SFML/Graphics.hpp"
#include <ctime>

#include "Alien.h"
#include "Barrier.h"
#include "Tank.h"
#include "Fleet.h"

#include "GameManager.h"
#include "IntroView.h"
#include "IntroController.h"
#include "InvadersView.h"
#include "InvadersController.h"
#include "ScoreView.h"
#include "ScoreController.h"

#include "Button.h"

int main() {
	srand(time(0));

	sf::RenderWindow win(sf::VideoMode(720, 900), "Space Invaders: Electric Boogaloo 2", sf::Style::Titlebar | sf::Style::Close);

	win.setFramerateLimit(240);

	Tank tank;
	Fleet fleet;
	Defense defense;


	IntroView iv;
	IntroController ic(iv, win);

	InvadersView invv(tank, fleet, defense);
	InvadersController invc(invv, win, tank);

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

		tank.updateTank();
		fleet.updateFleet();
		
		
		// Clear screen
		win.clear();

		// Draw current state
		gm.draw(win);

		// Update the window
		win.display();
	}



	return 0;
}