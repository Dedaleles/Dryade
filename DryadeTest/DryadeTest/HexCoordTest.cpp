#include "pch.h"
#include <sstream>
#include <string>
#include "../../Dryade/HexCoord.h"

TEST(HexCoordTest, HexCoordCreation) {
	HexCoord h(1, 2);
	EXPECT_EQ(h.getQ(), 1);
	EXPECT_EQ(h.getR(), 2);
}

TEST(HexCoordTest, HexCoordSubstraction) {
	HexCoord h1(1, 2), h2(0, -3);
	HexCoord h3(1,5);
	EXPECT_EQ(h1 - h2, h3);
}

TEST(HexCoordTest, HexCoordAddition) {
	HexCoord h1(1, 2), h2(0, -3);
	HexCoord h3(1, -1);
	EXPECT_EQ(h1 + h2, h3);
}

TEST(HexCoordTest, HexCoordScale) {
	HexCoord h1(1, 2), h2(3, 6);
	int factor = 3;
	EXPECT_EQ(h1 * factor, h2);
}

TEST(HexCoordTest, HexCoordComparison) {
	HexCoord h1(1, 2), h2(0, -3);
	EXPECT_TRUE(h2<h1);
}

TEST(HexCoordTest, HexCoordDist) {
	HexCoord h1(1, 2), h2(0, -3);
	EXPECT_EQ(h2.dist(h1),6);
}

TEST(HexCoordTest, HexCoordPrint) {
	HexCoord h1(1, 2);
	std::stringstream s;
	s << h1;
	EXPECT_EQ(s.str(), "(1, 2)");
}

