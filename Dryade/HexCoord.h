#pragma once
#include <cstdlib>
#include <string>
#include <sstream>

class HexCoord
{
private:
	const int q, r;
public:
	friend bool operator==(const HexCoord& t1, const HexCoord& t2);
	HexCoord(int q=0, int r=0) : q(q), r(r) {};

	const int getQ() const { return q; };
	const int getR() const { return r; };


	HexCoord operator-(const HexCoord& t) const {
		return HexCoord(q - t.q, r - t.r);
	}

	HexCoord operator+(const HexCoord& t) const {
		return HexCoord(q + t.q, r + t.r);
	}

	HexCoord operator*(int factor) const {
		return HexCoord(q * factor, r * factor);
	}

	bool operator<(const HexCoord& c) const {
		return 10 * q + r < 10 * c.q + c.r;
	}

	int dist(const HexCoord& t) const {
		HexCoord diff = *this - t;

		return  (std::abs(diff.q) + std::abs(diff.r) + std::abs(diff.q + diff.r)) / 2;
	}

};

inline bool operator==(const HexCoord& t1, const HexCoord& t2) { return t1.r == t2.r && t1.q == t2.q; }
;


