#include "pch.h"
#include <sstream>
#include <string>
#include "../../Dryade/HexTile.h"

TEST(HexTileTest, HexTileCreation) {
	HexTile t(HexCoord(0, 0), 3, 0);

	EXPECT_EQ(t.getCoord(), HexCoord(0, 0));
	EXPECT_EQ(t.getRichness(), 3);
	EXPECT_EQ(t.getIndex(), 0);

}

TEST(HexTileTest, HexTilePrint) {
	std::stringstream ss;
	ss << HexTile(HexCoord(0, 0), 3, 0);
	std::string cmp = "index = 0 (0, 0) richness = 3";
	EXPECT_EQ(cmp, ss.str());
}