#include "gtest/gtest.h"
#include "pch.h"
#include "../../Dryade/Action.h"
#include <string>
#include <sstream>
#include <fstream>

class ActionTest : public ::testing::Test {
protected:
	void SetUp() override{
		p = new Player("Charles");
		std::ifstream grid_stream("../../Dryade/grid.txt");
		g = Grid::parse(grid_stream);
	}

	Player* p;
	Grid* g;

	void TearDown() override {
		delete p;
	}
};

TEST_F(ActionTest, ActionTypeParsing) {
	ActionType wait = parseType("WAIT");
	ActionType complete = parseType("COMPLETE");
	ActionType grow = parseType("GROW");
	ActionType seed = parseType("SEED");

	EXPECT_EQ(wait, ActionType::Wait);
	EXPECT_EQ(complete, ActionType::Complete);
	EXPECT_EQ(grow, ActionType::Grow);
	EXPECT_EQ(seed, ActionType::Seed);
}

TEST_F(ActionTest, ActionTypePrinting) {
	std::stringstream res;
	res << ActionType::Grow << " " << ActionType::Seed;
	std::string cmp = "GROW SEED";
	EXPECT_EQ(cmp, res.str());
}

TEST_F(ActionTest, ActionCreation) {
	HexCoord c1(0, 0), c2(1, 1);
	Action a(p, ActionType::Seed, &c1, &c2);

	EXPECT_EQ(a.getType(), ActionType::Seed);
	EXPECT_EQ(a.getTarget(), HexCoord(0,0));
	EXPECT_EQ(a.getOrigin(), HexCoord(1, 1));
	EXPECT_EQ(a.getPlayer(), *p);
}

TEST_F(ActionTest, ActionParseSeed) {
	HexCoord c1(0, 0), c2(1, 0);
	Action a = Action::parse("SEED 0 1", p);

	EXPECT_EQ(a.getType(), ActionType::Seed);
	EXPECT_EQ(a.getTarget(), c2);
	EXPECT_EQ(a.getOrigin(), c1);
	EXPECT_EQ(a.getPlayer(), *p);
}

TEST_F(ActionTest, ActionParseComplete) {
	HexCoord  c2(1, 0);
	Action a = Action::parse("COMPLETE 1", p);

	EXPECT_EQ(a.getType(), ActionType::Complete);
	EXPECT_EQ(a.getTarget(), c2);
	EXPECT_EQ(a.getPlayer(), *p);
}

TEST_F(ActionTest, ActionParseGrow) {
	HexCoord c1(0, 0);
	Action a = Action::parse("GROW 0", p);

	EXPECT_EQ(a.getType(), ActionType::Grow);
	EXPECT_EQ(a.getTarget(), c1);
	EXPECT_EQ(a.getPlayer(), *p);
}

TEST_F(ActionTest, ActionParseWait) {
	HexCoord c1(0, 0);
	Action a = Action::parse("WAIT", p);

	EXPECT_EQ(a.getType(), ActionType::Wait);
	EXPECT_EQ(a.getPlayer(), *p);
}

TEST_F(ActionTest, ActionPrinting) {
	Action a = Action::parse("SEED 0 1", p);
	std::stringstream s;
	s << a;

	EXPECT_EQ(s.str(), "SEED 0 1");
}