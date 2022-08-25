#pragma once
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

class HexCoord
{
private:
	int q, r;
public:
	friend bool operator==(const HexCoord& t1, const HexCoord& t2);
	friend std::ostream& operator<<(std::ostream&, const HexCoord&);
	friend class HexCoordHash;

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

	HexCoord& operator=(const HexCoord& c) {
		q = c.q;
		r = c.r;
		return	*this;
	}



	int dist(const HexCoord& t) const {
		HexCoord diff = *this - t;

		return  (std::abs(diff.q) + std::abs(diff.r) + std::abs(diff.q + diff.r)) / 2;
	}

	


};

class HexCoordHash {
public:
	size_t operator()(const HexCoord& c) const {
		return  10 * c.q + c.r;
	}
};

inline bool operator==(const HexCoord& t1, const HexCoord& t2) { return t1.r == t2.r && t1.q == t2.q; };

inline std::ostream& operator<<(std::ostream& o, const HexCoord& c) {
	o << "(" << c.q << ", " << c.r << ")";
	return o;
};

std::ostream& operator<<(std::ostream& o, const std::vector<HexCoord>& coords);



