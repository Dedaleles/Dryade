#pragma once
#include <map>
#include <iostream>
#include <vector>
#include <regex>
#include <string>
#include <sstream>
#include "HexTile.h"


class Grid
{
private:
	static Grid * singleton_;
	static const HexCoord forward_;
	static const std::vector<HexCoord> cubeDirection_;
	std::map<HexCoord, HexTile>  tiles;
	std::vector<HexCoord> indexToCoord;
	std::vector<std::vector<HexCoord>> rings;
	int n_cells;
	Grid(std::istream& file = std::cin);

public:
	static Grid* getInstance() {
		return singleton_;
	}

	static Grid* parse(std::istream& file = std::cin) {
		if (singleton_ == nullptr) {
			singleton_ = new Grid(file);
		}
		return singleton_;

	}

	const HexCoord& getCoord(int index) const { return indexToCoord[index]; };
	const HexTile& getTile(int index)  { return tiles[indexToCoord[index]]; };
	const std::vector<HexCoord> getRing(int size) { return rings[size]; }
	const std::vector<HexCoord> computeRing(HexCoord center, int radius);
};

std::vector<std::string> split(std::string str, char delimiter);
