#ifndef Trick_hpp
#define Trick_hpp

#include <vector>

//using Player = int;
class myPlayer;
using Player = myPlayer;

//KK: zakladam na ten moment, ze nie kompilujemy az Kasia sobie poradzi, w przeciwnym razie... sie pomysli
//using Card = int;

struct PlayerAndCard
{
	Card card;
	Player player;
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
