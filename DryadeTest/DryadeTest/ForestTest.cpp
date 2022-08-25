#include "gtest/gtest.h"
#include "pch.h"
#include "../../Dryade/Forest.h"
#include "../../Dryade/Grid.h"
#include <sstream>
#include <fstream>
#include <vector>
#include <set>



class ForestTest : public ::testing::Test {
protected:
	void SetUp() override{
		std::ifstream grid_stream("../../Dryade/grid.txt");
		g = Grid::parse(grid_stream);
		p = new Player("charles");
		f.plantTree(g->getCoord(0), *p);
	}

	Forest f;
	Grid* g;
	Player* p;

	void TearDown() override {
		delete p;
	}
};

TEST_F(ForestTest, PlantTree) {
	f.plantTree(g->getCoord(1), *p);
	EXPECT_EQ(f[g->getCoord(1)].getSize(), 0);
}

TEST_F(ForestTest, GrowTree) {
	f.growTree(g->getCoord(0));
	EXPECT_EQ(f[g->getCoord(0)].getSize(), 1);
}

TEST_F(ForestTest, CompleteTree) {
	f.growTree(g->getCoord(0));
	f.growTree(g->getCoord(0));
	f.growTree(g->getCoord(0));
	f.completeTree(g->getCoord(0));
	EXPECT_EQ(f[g->getCoord(0)].getSize(), -1);
	EXPECT_EQ(p->getScore(), 24);
}

TEST_F(ForestTest, WakeTree) {
	f.growTree(g->getCoord(0));
	EXPECT_EQ(f[g->getCoord(0)].isDormant(), true);
	f.wakeEveryone();
	EXPECT_EQ(f[g->getCoord(0)].isDormant(), false);

}

TEST_F(ForestTest, ComputeShadows) {
	f.growTree(g->getCoord(0));
	f.growTree(g->getCoord(0));
	std::vector<std::set<HexCoord>> res = {
		std::set<HexCoord>(),
		std::set<HexCoord>(),
		std::set<HexCoord>({g->getCoord(1), g->getCoord(7)}),
		std::set<HexCoord>()
	};
	std::vector<std::set<HexCoord>>s = f.computeShadows(0);
}