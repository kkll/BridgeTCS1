#include <gtest/gtest.h>
#include "../Play.hpp"

class TrickFixture : ::testing::Test{
	Trick trick;
	Player player;
	Card card;
};

TEST_F(TrickFixture, Adding){
	trick.add(player, card);
	Player const& winner = trick.getWinner();
	ASSERT_EQ(winner, player);
}
