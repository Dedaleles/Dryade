#pragma once
#include "Player.h"
#include "Forest.h"

class GameState
{
private:
	int sun_pos, day;
	Player p1, p2;
	Forest forest;
public:
	GameState() :sun_pos(0), day(0), p1("Player 1"), p2("Player 2"), forest() {
	};
	GameState(const GameState& g) : sun_pos(g.sun_pos), day(g.day), p1(g.p1), p2(g.p2), forest(forest) {
	};

	bool isGameOver() { return day == 24; };
	Player& getWinner() {
		if (p1.getScore() > p2.getScore()) {
			return p1;
		}
		else {
			return p2;
		}
	}

	int getRewardFor( const Player& p) {
		Player& opp = p == p1 ? p2 : p1;
		if (p.getScore() > opp.getScore()) {
			return 1;
		}
		else if (opp.getScore() > p.getScore()) {
			return -1;
		}
		return 0;
	}
};

