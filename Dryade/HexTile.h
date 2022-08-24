#pragma once
#include <cstdlib>
#include <string>
#include <sstream>
#include "HexCoord.h"

class HexTile
{
private:
	const int richness, index;
	const HexCoord& coord;
	
public:
	HexTile() : coord(HexCoord()), richness(0), index(0) {};

	HexTile(const HexCoord& c, int r=0, int i=0) : coord(c), richness(r), index(i) {};
	
	const int getRichness() const { return richness; };
	const int getIndex() const { return index; };
};


