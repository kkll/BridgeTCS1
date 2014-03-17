#ifndef Trick_hpp
#define Trick_hpp

#include <vector>
#include "Card.hpp"
//using Player = int;
class myPlayer;
using Player = myPlayer;

//KK: zakladam na ten moment, ze nie kompilujemy az Kasia sobie poradzi, w przeciwnym razie... sie pomysli
//using Card = int;

struct PlayerAndCard
{
	const Card & card;
	const Player & player;
	PlayerAndCard(const Player &, const Card &);
};

class Trick {
	std::vector<PlayerAndCard> cards;
	Denomination denomination;
	public:
		Trick(Denomination denomination);
		bool add(const Player &, const Card &);
		Player const& getWinner();
};

#endif
