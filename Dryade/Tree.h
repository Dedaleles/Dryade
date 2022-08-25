#pragma once
#include "HexTile.h"
#include "Player.h"
#include "Grid.h"
#include <iostream>
#include <set>

class Tree
{
private:
	int size;
	bool dormant;
	HexTile& tile;
	Player& player;
public:
	friend std::ostream& operator<< (std::ostream& os, const Tree& t);

	Tree(Player& p, HexTile& t,int s=0,bool isD=false):player(p),tile(t),size(s),dormant(isD){
		player.addTreesOfSize(0);
	}
	Tree() :player(Player::nullPlayer), tile(Grid::getInstance()->getTile(0)), size(-1), dormant(true){};
	
	HexCoord& getCoord()  { return tile.getCoord(); };
	HexTile& getTile()  { return tile; };

	int getSize() const { return size; };
	int getSuns() const { return size; };
	const Player& getPlayer() const { return player; };

	bool isDormant() const { return dormant; };

	void grow() {
		if (size < 3) {
			player.removeTreesOfSize(size);
			size++;
			player.addTreesOfSize(size);
			dormant = true;
		}
	}
	void complete(int nutrients) {
		if (size == 3) {
			player.removeTreesOfSize(size);
			player.addScore(bonusScore() + nutrients);
		}
	}

	void wakeUp() { dormant = false; };
	void sleep() { dormant = true; };
	int bonusScore() { return (tile.getRichness() - 1) * 2; };

	std::set<HexCoord> projectShadow(int sun_pos) {
		std::set< HexCoord> res;
		HexCoord toAdd = Grid::sunDirection_[sun_pos];
		for (int i = 1; i <= size; i++) {
			res.insert(getCoord() + toAdd * i);
		}
		return res;
	}
};

inline std::ostream& operator<< (std::ostream& os, const Tree& t) {
	os << t.player.getName() << "'s tree on tile : " << t.tile.getIndex() << ", size = " << t.size << ", dormant = " << t.dormant;
	return os;
}