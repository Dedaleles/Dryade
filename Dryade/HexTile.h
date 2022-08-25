#pragma once
#include <cstdlib>
#include <string>
#include <sstream>
#include <iostream>
#include "HexCoord.h"

class HexTile
{
private:
	int richness, index;
	HexCoord* coord;
	
public:
	friend bool operator==(const HexTile& t1, const HexTile& t2);
	friend std::ostream& operator<<(std::ostream& os, const HexTile& t);

	HexTile() : coord(nullptr), richness(0), index(0) {};

	HexTile(HexCoord& c, int r=0, int i=0) : coord(&c), richness(r), index(i) {};
	
	HexCoord& getCoord() const { return *coord; };
	const int getRichness() const { return richness; };
	const int getIndex() const { return index; };
};

inline bool operator==(const HexTile& t1, const HexTile& t2) { return *t1.coord == *t2.coord && t1.richness == t2.richness && t1.index==t2.index; };


inline std::ostream& operator<<(std::ostream& os, const HexTile& t) {
	os << "index = " << t.index << " " << *t.coord << " richness = " << t.richness;
	return os;
}