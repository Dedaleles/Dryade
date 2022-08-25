#include "HexCoord.h"


std::ostream& operator<<(std::ostream& o, const std::vector<HexCoord>& coords) {
	for (const HexCoord& c : coords) {
		o << c << "\n";
	}
	return o;
};