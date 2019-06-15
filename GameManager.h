#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "IntroController.h"
#include "InvadersController.h"
#include "ScoreController.h"

class GameManager {
	IntroController &introController;
	InvadersController &invadersController;
	ScoreController &scoreController;

	enum GameState {
		INTRO, GAME, SCORE
	} state;

	void updateState();
public:
	GameManager(IntroController &ic, InvadersController &invc, ScoreController &sc);

	void draw(sf::RenderWindow &win);

	void handleEvent(sf::Event &event);

};


#endif
