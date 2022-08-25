#pragma once
#include <unordered_map>
#include <set>
#include <vector>
#include <algorithm>
#include "Tree.h"
#include "HexCoord.h"

class Forest
{
private:
	std::unordered_map<HexCoord, Tree, HexCoordHash> trees;
	int nutrients;
public:
	Forest() :nutrients(20) {};
	Forest(const Forest& f) : nutrients(f.nutrients) {
		for (auto& t : f) {
			trees.insert({ t.first, Tree(t.second) });
		}
	}
	void computeSuns() {// TODO Define compute suns
	};

	std::vector<std::set<HexCoord>> computeShadows(int sun_pos) {//TODO Define compute shadows
		std::vector<std::set<HexCoord>> shadows = {
			std::set<HexCoord>({}),
			std::set<HexCoord>({}),
			std::set<HexCoord>({}),
			std::set<HexCoord>({})};

		for (auto& t : trees) {
			std::set<HexCoord> s = t.second.projectShadow(sun_pos);
			int index = t.second.getSize();
			for (auto c : s) {
				shadows[index].insert(c);
			}
		}

		return shadows;
	};

	void plantTree(const HexCoord& coord, Player& player) {
		trees.insert({ coord, Tree(player, Grid::getInstance()->getTile(coord), 0, true) });
	}

	void growTree(const HexCoord& coord) {
		trees[coord].grow();
	}

	void completeTree(const HexCoord& coord) {
		trees[coord].complete(nutrients);
		nutrients -= 1;
		trees.erase(coord);
	}

	void wakeEveryone() {
		for (auto& t : trees) {
			t.second.wakeUp();
		}
	}

	Tree& operator[](const HexCoord& coord) {
		return trees[coord];
	}

	typedef std::unordered_map<HexCoord, Tree, HexCoordHash>::iterator iterator;
	iterator begin() { return trees.begin(); };
	iterator end() { return trees.end(); };

	typedef std::unordered_map<HexCoord, Tree, HexCoordHash>::const_iterator const_iterator;
	const_iterator begin() const { return trees.begin(); };
	const_iterator end() const { return trees.end(); };
};

