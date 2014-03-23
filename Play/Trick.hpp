#ifndef Trick_hpp
#define Trick_hpp

#include <vector>
#include "../Deck/Card.hpp"
#include "../Bidding/Denomination.hpp"

using Player = int;
///class myPlayer;
//typedef myPlayer Player;


//KK: zakładam na ten moment, ze nie kompilujemy az Kasia sobie poradzi, w przeciwnym razie... sie pomysli
//using Card = int;

struct PlayerAndCard
{
	const Card & card;
	const Player & player;
	PlayerAndCard(const Card &, const Player &);
};

class Trick {
	std::vector<PlayerAndCard> cards;
	Denomination trump;
	public:
		Trick(Denomination trump);
		void add(const Player &, const Card &);
		Player const& getWinner();
};

#endif
