#include "Play.hpp"

//using PointsOfCompass = myPointsOfCompass;


//using Player = myPlayer;
//using Trump = int;

inline bool arePartners(int player1, int player2)
{
    return player1%2 == player2%2;
}

/* Returns the number of tricks taken. It's up to the caller to convert it into points result. */
int Play::doPlay (Arbiter arbiters[], Contract contract)
{
	int tricksTaken = 0;
	Denomination trump = contract.denomination;
    int declarer = contract.declarer;
    int lastRoundWinner = declarer;

	for (int trickNr = 0; trickNr < 13; trickNr++)
	{
        Trick trick(trump);
		for (int i=0, playerInd = lastRoundWinner; i < 4; i++, playerInd = (playerInd + 1)%4 )
		{
			Card actCard = arbiters[playerInd].getCard();
			trick.add(playerInd, actCard);
		}
		lastRoundWinner = trick.getWinner();

        if(arePartners(lastRoundWinner, declarer)) tricksTaken++;
	}
	return tricksTaken;
}
