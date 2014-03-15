#include <list>

using namespace std;

using Player = int;

struct PlayerAndCard {
	Player player;
	Card card;
};

class Trick {
	list<PlayerAndCard> cards;
	bool add(const& Player, const& Card);
	list<PlayerAndCard> const& getTrick();
};
