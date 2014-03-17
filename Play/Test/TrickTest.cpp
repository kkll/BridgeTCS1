#include <gtest/gtest.h>
#include "../Play.hpp"

class TrickFixture : public ::testing::Test{
	Player player;
	Card card;
	Denomination denomination;
};

TEST_F(TrickFixture, Adding){
	Trick trick(denomination);
	trick.add(player, card);
	Player const& winner = trick.getWinner();
	ASSERT_EQ(winner, player);
}
