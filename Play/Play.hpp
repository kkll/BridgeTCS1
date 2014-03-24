#ifndef Play_hpp
#define Play_hpp

#include <vector>

#include "../Deck/Card.hpp"
#include "../Bidding/Contract.hpp"
#include "../Rubber/Arbiter.hpp"



using Player = int;
using Trump = int;

class Play
{
/***************************************************************/
    struct PlayerAndCard
    {
        int player;
        const Card & card;
        PlayerAndCard(int player, const Card & card) : player(player), card(card) {}
    };

    class Trick {
        std::vector<PlayerAndCard> cards;
        Denomination trump;
        inline bool defeat(const Card &, const Card &);

        public:
            Trick(Denomination trump) : trump(trump) {}

            void add(int player, const Card & card)
            {
                cards.push_back(PlayerAndCard(player, card));
            }

            int getWinner();
    };
/***************************************************************/

public:
	/* Returns the number of tricks taken. It's up to the caller to convert it into points result. */
	int doPlay (Arbiter arbiters[], Contract contract);
};

#endif
