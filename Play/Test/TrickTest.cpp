#include <gtest/gtest.h>
#include "../Trick.hpp"

class TrickTest : public ::testing::Test{
public:
	Player player1 = 1;
	Player player2 = 2;
	Player player3 = 3;
	Player player4 = 4;
	Denomination denomination;
};

TEST_F(TrickTest, Adding){
	denomination = Denomination::Clubs;
	Trick trick(denomination);
	trick.add(player1, Card(Rank::ACE, Suit::CLUBS));
	Player const& winner = trick.getWinner();
	ASSERT_EQ(winner, player1);
}

TEST_F(TrickTest, NoTrump1){
	denomination = Denomination::NT;
	Trick trick(denomination);

	Card card1(Rank::ACE, Suit::CLUBS);
	Card card2(Rank::ACE, Suit::DIAMONDS);
	Card card3(Rank::ACE, Suit::HEARTS);
	Card card4(Rank::TWO, Suit::CLUBS);

	trick.add(player1, card1);
	trick.add(player2, card2);
	trick.add(player3, card3);
	trick.add(player4, card4);
	Player const& winner = trick.getWinner();
	ASSERT_EQ(winner, player1);
}

TEST_F(TrickTest, NoTrump2){
	denomination = Denomination::NT;
	Trick trick(denomination);

	Card card1(Rank::TWO, Suit::CLUBS);
	Card card2(Rank::ACE, Suit::DIAMONDS);
	Card card3(Rank::ACE, Suit::HEARTS);
	Card card4(Rank::THREE, Suit::CLUBS);

	trick.add(player1, card1);
	trick.add(player2, card2);
	trick.add(player3, card3);
	trick.add(player4, card4);

	Player const& winner = trick.getWinner();
	ASSERT_EQ(winner, player4);
}
