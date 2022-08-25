#include "gtest/gtest.h"
#include "pch.h"
#include "../../Dryade/Player.h"
#include <string>
#include <sstream>

class PlayerTest : public ::testing::Test {
protected:
	void SetUp() override {
		p = new Player("charles", 10, 20);
	}

	Player* p;
	
	void TearDown() override {
		delete p;
	}
};

TEST_F(PlayerTest, TestDefaultCreation) {
	Player cr("p1");
	EXPECT_EQ(cr.getName(), "p1");
	EXPECT_EQ(cr.getSuns(), 0);
	EXPECT_EQ(cr.getScore(), 0);
}

TEST_F(PlayerTest, TestCreation) {
	EXPECT_EQ(p->getName(), "charles");
	EXPECT_EQ(p->getSuns(), 20);
	EXPECT_EQ(p->getScore(), 10);
}

TEST_F(PlayerTest, TestSuns) {
	p->addSuns(10);
	EXPECT_EQ(p->getSuns(), 30);

	p->removeSuns(10);
	EXPECT_EQ(p->getSuns(), 20);
}

TEST_F(PlayerTest, TestScore) {
	p->addScore(25);
	EXPECT_EQ(p->getScore(), 35);
}

TEST_F(PlayerTest, PlayerPrint) {
	std::stringstream ss;
	ss << *p;
	std::string cmp = "charles : score = 10, suns = 20";
	EXPECT_EQ(ss.str(), cmp);
}

TEST_F(PlayerTest, PlayerDefaultTree) {
	EXPECT_EQ(p->getTreesOfSize(0), 0);
	EXPECT_EQ(p->getTreesOfSize(1), 0);
	EXPECT_EQ(p->getTreesOfSize(2), 0);
	EXPECT_EQ(p->getTreesOfSize(3), 0);
}

TEST_F(PlayerTest, PlayerAddTree) {
	p->addTreesOfSize(1);
	p->addTreesOfSize(2);
	p->addTreesOfSize(2);

	EXPECT_EQ(p->getTreesOfSize(0), 0);
	EXPECT_EQ(p->getTreesOfSize(1), 1);
	EXPECT_EQ(p->getTreesOfSize(2), 2);
	EXPECT_EQ(p->getTreesOfSize(3), 0);
}

TEST_F(PlayerTest, PlayerRemoveTree) {
	p->addTreesOfSize(2);
	p->addTreesOfSize(2);
	p->removeTreesOfSize(2);
	EXPECT_EQ(p->getTreesOfSize(0), 0);
	EXPECT_EQ(p->getTreesOfSize(1), 0);
	EXPECT_EQ(p->getTreesOfSize(2), 1);
	EXPECT_EQ(p->getTreesOfSize(3), 0);
}