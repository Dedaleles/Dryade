#pragma once
#include "HexCoord.h"
#include "Player.h"
#include "Grid.h"
#include "utils.h"
#include <iostream>
#include <string>
#include <vector>

enum class ActionType {
	Seed,
	Grow,
	Complete,
	Wait
};

inline std::ostream& operator<<(std::ostream& os, const ActionType& a) {
	switch (a)
	{
	case ActionType::Seed:
		os << "SEED";
		break;
	case ActionType::Grow:
		os << "GROW";
		break;
	case ActionType::Complete:
		os << "COMPLETE";
		break;
	case ActionType::Wait:
		os << "WAIT";
		break;
	default:
		break;
	}
	return os;
}

inline ActionType parseType(std::string input) {
	if (input == "WAIT") return ActionType::Wait;
	else if (input == "SEED") return ActionType::Seed;
	else if (input == "GROW") return ActionType::Grow;
	else if (input == "COMPLETE") return ActionType::Complete;
}


class Action
{
private:
	Player* player = nullptr;
	ActionType type;
	HexCoord* target = nullptr, * origin = nullptr;
public:
	friend std::ostream& operator<<(std::ostream& os, const Action& a);

	Action(Player* p = nullptr, ActionType a = ActionType::Wait, HexCoord* t = nullptr, HexCoord* o = nullptr) :
		player(p), type(a), target(t), origin(o) {};

	static Action parse(const std::string& input, Player *p=nullptr) {
		std::vector<std::string> inputs = split(input);
		Grid* g = Grid::getInstance();
		switch (inputs.size()) {
		case 1:
			return Action(p,parseType(inputs[0]));
			break;
		case 2:
			return Action(p,parseType(inputs[0]), &g->getCoord(std::stoi(inputs[1])));
			break;
		case 3:
			return Action(p,parseType(inputs[0]), &g->getCoord(std::stoi(inputs[2])), &g->getCoord(std::stoi(inputs[1])));
			break;
		}
	};

	Player& getPlayer() { return *player; };
	ActionType getType() { return type; };
	HexCoord& getTarget() { return *target; };
	HexCoord& getOrigin() { return *origin; };

};

inline std::ostream& operator<<(std::ostream& os, const Action& a) {
	Grid* g = Grid::getInstance();

	os << a.type;
	if (a.origin != nullptr) os << " "<<g->getIndex(*a.origin) << " " << g->getIndex(*a.target);
	else if(a.target != nullptr) os << " " << g->getIndex(*a.target);
	return os;
}