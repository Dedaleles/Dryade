#pragma once
#include <unordered_map>
#include <iostream>
#include <vector>
#include <regex>
#include <string>
#include <sstream>
#include <algorithm>
#include "HexTile.h"
#include "utils.h"

class Grid
{
private:
	static Grid * singleton_;
	static const HexCoord forward_;
	static const std::vector<HexCoord> cubeDirection_;

	std::unordered_map<HexCoord, HexTile, HexCoordHash>  tiles;
	std::vector<HexCoord> indexToCoord;
	std::vector<std::vector<HexCoord>> rings;
	int n_cells;
	Grid(std::istream& file = std::cin);

public:
	static const std::vector<HexCoord> sunDirection_;
	static Grid* getInstance() {
		return singleton_;
	}

	static Grid* parse(std::istream& file = std::cin) {
		if (singleton_ == nullptr) {
			singleton_ = new Grid(file);
		}
		return singleton_;

	}

	HexCoord& getCoord(int index)  { return indexToCoord[index]; };
	HexTile& getTile(int index)  { return tiles[indexToCoord[index]]; };
	HexTile& getTile(const HexCoord& coord)  { return tiles[coord]; };
	int getIndex(HexCoord& c) {
		auto it = std::find(indexToCoord.begin(), indexToCoord.end(), c);

		if (it == indexToCoord.end()){
			return -1;
		}
		else {
			return it - indexToCoord.begin();
		}
	}
	const std::vector<HexCoord> getRing(int size) { return rings[size]; }
	const std::vector<HexCoord> computeRing(const HexCoord& center, int radius);

};


