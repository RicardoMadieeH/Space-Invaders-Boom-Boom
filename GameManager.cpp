#include "GameManager.h"

GameManager::GameManager(IntroController &ic, InvadersController &mc, ScoreController &sc)
	: introController(ic), invadersController(mc), scoreController(sc)
{

	state = INTRO;
}

void GameManager::updateState() {
	switch (state) {
	case INTRO:
		if (introController.isFinished())
			state = GAME;
		break;
	case GAME:
		if (invadersController.isFinished())
			state = SCORE;
		break;
	case SCORE:
		// oops - tu powinni�my jako� zamkn�� aplikacj�
		break;
	}
}

void GameManager::handleEvent(sf::Event &event)
{
	switch (state) {
	case INTRO:
		introController.handleEvent(event);
		break;
	case GAME:
		invadersController.handleEvent(event);
		break;
	case SCORE:
		scoreController.handleEvent(event);
		break;
	}
	updateState();
}

void GameManager::draw(sf::RenderWindow &win) {
	// updateState() ??
	switch (state) {
	case INTRO:
		introController.draw(win);
		break;
	case GAME:
		invadersController.draw(win);
		break;
	case SCORE:
		scoreController.draw(win);
		break;
	}
}