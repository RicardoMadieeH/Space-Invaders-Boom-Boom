#ifndef DEFENSE_H
#define DEFENSE_H

#include "Barrier.h"
#include <deque>

class Defense
{
	std::deque<Barrier*>def;

public:
	Defense();
	
	void drawTo(sf::RenderWindow &win);

	friend class InvadersView;
};

#endif

