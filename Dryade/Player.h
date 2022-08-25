#pragma once
#include <string>
#include <iostream>
#include <vector>

class Player
{
protected:
	const std::string name;
	int score, suns;
	std::vector<int> treesOfSize;
public:
	static Player nullPlayer;
	friend std::ostream& operator<<(std::ostream& os, const Player& p);

	Player(const std::string& n, int score = 0, int suns = 0) :name(n), score(score), suns(suns) {
		treesOfSize = { 0,0,0,0 };
	};
	Player(const Player& p) : name(p.name), score(p.score), suns(p.suns), treesOfSize(p.treesOfSize) {	}


	int getScore() const{return score;};
	int getSuns() const { return suns; };
	int getTreesOfSize(int size) const { return treesOfSize[size]; };
	const std::string& getName() const { return name; };

	void addSuns(int number) { suns += number; };
	void addScore(int number) { score += number; };
	void removeSuns(int number) { suns -= number; };
	void addTreesOfSize(int size) { treesOfSize[size]++; };
	void removeTreesOfSize(int size) { treesOfSize[size]--; };

};

inline std::ostream& operator<<(std::ostream& os, const Player& p) {
	os << p.name << " : score = " << p.score << ", suns = " << p.suns;
	return os;
}

