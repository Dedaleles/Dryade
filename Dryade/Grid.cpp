#include "Grid.h"

Grid* Grid::singleton_ = nullptr;	
const std::vector<HexCoord> Grid::cubeDirection_ = { HexCoord(0,-1),HexCoord(-1,0),HexCoord(-1,1),HexCoord(0,1),HexCoord(1,0),HexCoord(+1,-1) };
const std::vector<HexCoord> Grid::sunDirection_ = { HexCoord(1,0),HexCoord(0,1),HexCoord(-1,1),HexCoord(-1,0),HexCoord(0,-1),HexCoord(1,-1) };

const HexCoord Grid::forward_(1, 0);

Grid::Grid(std::istream& file)  {
	std::string line;
	std::getline(file, line);
	n_cells = std::stoi(line);
	
	HexCoord* last = nullptr;
	for (int n_circle = 0; n_circle < 4; n_circle++) {// the board have 4 rings total
		std::vector<HexCoord> ring;// store each ring, used to compute seeding range
		last = new HexCoord(HexCoord(0, 0) + forward_*n_circle);// move to the first tile of the ring
		indexToCoord.push_back(*last);
		ring.push_back(*last);
		for (int cycle = 0; cycle < 6; cycle++) { // go through each direction to make a circle
			for (int n = 0; n < n_circle; n++) { // we move n_circle times in each direction
				if (cycle != 5 or n != n_circle - 1) { // Eliminate the last tile (same as the first)
					last = new HexCoord(*last + cubeDirection_[cycle]);
					indexToCoord.push_back(*last);
					ring.push_back(*last);
				}
			}
		}
		rings.push_back(ring);
	}

	while (std::getline(file, line)) {//Get each line of input
		std::vector<std::string> extracted = split(line, ' '); //split line by space
		HexCoord *c = &indexToCoord[stoi(extracted[0])];
		tiles.insert({ *c, HexTile(*c, stoi(extracted[1]), stoi(extracted[0])) });
	}
}

const std::vector<HexCoord> Grid::computeRing(const HexCoord& center, int radius)
{
	std::vector<HexCoord> newRing;
	for (auto& c : rings[radius]) {
		HexCoord coord = c + center;
		if (std::find(indexToCoord.begin(), indexToCoord.end(), coord) != indexToCoord.end()) {
			newRing.push_back(c + center);

		}
	}
	return newRing;
}


