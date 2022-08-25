#include "pch.h"
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include "../../Dryade/Grid.h"

TEST(GridTest, GridCreation) {
	std::ifstream grid_stream("../../Dryade/grid.txt");
	Grid* grid = Grid::parse(grid_stream);
	Grid* g2 = Grid::getInstance();

	EXPECT_EQ(grid, g2);
}

TEST(GridTest, GridGetCoord) {
	Grid* grid = Grid::getInstance();

	EXPECT_EQ(grid->getCoord(0), HexCoord(0,0));
	EXPECT_EQ(grid->getCoord(36), HexCoord(2, 1));

}


TEST(GridTest, GridGetTile) {
	Grid* grid = Grid::getInstance();



	EXPECT_EQ(grid->getTile(0), HexTile(HexCoord(0, 0), 3, 0));
}

TEST(GridTest, GridGetRing) {
	Grid* grid = Grid::getInstance();

	std::vector<HexCoord> testRing = { HexCoord(2,0),HexCoord(2,-1),HexCoord(2,-2),
		HexCoord(1,-2), HexCoord(0,-2),HexCoord(-1,-1),HexCoord(-2,0),HexCoord(-2,1),
		HexCoord(-2,+2),HexCoord(-1,+2), HexCoord(0,2), HexCoord(1,1) };

	EXPECT_EQ(grid->getRing(2), testRing);
}

TEST(GridTest, GridComputeRing) {
	Grid* grid = Grid::getInstance();
	std::vector<HexCoord> testRing = { HexCoord(2,0),HexCoord(2,-1),HexCoord(1,-1),
			HexCoord(0,0),HexCoord(0,1),HexCoord(1,1) };

	EXPECT_EQ(grid->computeRing(HexCoord(1, 0), 1), testRing);

	std::vector<HexCoord> testRing2 = { HexCoord(2,-3),HexCoord(2,-2),HexCoord(3,-2) };

	EXPECT_EQ(grid->computeRing(HexCoord(3, -3), 1), testRing2);
}

TEST(GridTest, GridSplit) {
	std::string test = "voici un test efficace 0";
	std::vector<std::string> expected = { "voici", "un", "test", "efficace","0" };

	EXPECT_EQ(split(test, ' '), expected);
	EXPECT_EQ(split(test), expected);


}