#include "gtest/gtest.h"
#include "pch.h"
#include "../../Dryade/Tree.h"
#include "../../Dryade/Grid.h"

#include <fstream>
#include <sstream>
#include <string>


class TreeTest : public ::testing::Test {
protected:
	void SetUp() override {
		std::ifstream grid_stream("../../Dryade/grid.txt");
		g = Grid::parse(grid_stream);
		c = &g->getCoord(12);
		t= new HexTile(*c, 3, 12);
		p = new Player("charles");
		treeTest = new Tree(p,*t);
	}

	Grid* g;
	HexCoord* c;
	HexTile *t;
	Tree *treeTest;
	Player* p;

	void TearDown() {
		delete t;
		delete treeTest;
	}
};

TEST_F(TreeTest, TreeCreation) {
	Tree t2(p,*t, 2, true);
	EXPECT_EQ(t2.getCoord(), *c);
	EXPECT_EQ(t2.getSize(), 2);
	EXPECT_EQ(t2.isDormant(), true);
	EXPECT_EQ(t2.getPlayer().getTreesOfSize(0), 2);
}

TEST_F(TreeTest, TreeSleepManagement) {
	treeTest->sleep();
	EXPECT_EQ(treeTest->isDormant(), true);

	treeTest->wakeUp();
	EXPECT_EQ(treeTest->isDormant(), false);
}

TEST_F(TreeTest, ComputeBonusScore) {
	EXPECT_EQ(treeTest->bonusScore(), 4);

}

TEST_F(TreeTest, GrowTree) {
	treeTest->grow();
	EXPECT_EQ(treeTest->getSize(), 1);
	EXPECT_EQ(treeTest->getPlayer().getTreesOfSize(0),0);
	EXPECT_EQ(treeTest->getPlayer().getTreesOfSize(1), 1);
}

TEST_F(TreeTest, CompleteTree) {
	treeTest->grow();
	treeTest->grow();
	treeTest->grow();
	treeTest->complete(20);
	EXPECT_EQ(treeTest->getSize(), 3);
	EXPECT_EQ(treeTest->getPlayer().getTreesOfSize(0), 0);
	EXPECT_EQ(treeTest->getPlayer().getTreesOfSize(1), 0);
	EXPECT_EQ(treeTest->getPlayer().getTreesOfSize(2), 0);
	EXPECT_EQ(treeTest->getPlayer().getTreesOfSize(3), 0);
	EXPECT_EQ(treeTest->getPlayer().getScore(), 24);


}

TEST_F(TreeTest, PrintTree) {
	std::stringstream ss;
	ss << *treeTest;
	std::string cmp = "charles's tree on tile : 12, size = 0, dormant = 0";
	EXPECT_EQ(ss.str(), cmp);
}

TEST_F(TreeTest, ProjectShadow) {
	treeTest->grow();
	treeTest->grow();
	std::set<HexCoord> cmp = { g->getCoord(3), g->getCoord(2) };
	EXPECT_EQ(cmp, treeTest->projectShadow(0));
}

TEST_F(TreeTest, AddSuns) {
	treeTest->grow();
	treeTest->addSuns();
	EXPECT_EQ(p->getSuns(),1);
}