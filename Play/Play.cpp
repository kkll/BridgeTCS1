#include "Play.hpp"

//using PointsOfCompass = myPointsOfCompass;
class Trick;

PointsOfCompass myPlayer::getPointOfCompass() const
{
	return pointOfCompass;
}

//using Player = myPlayer;
//using Trump = int;

/* Returns the number of tricks taken. It's up to the caller to convert it into points result. */
/* declarer = rozgrywajacy
 * ?? Should take the denomination or the whole contract as an argument?? */
int Play::doPlay (Player players[], Contract contract)
{
	int tricksTaken = 0;
	const Denomination& denomination = contract.denomination;
	const PointsOfCompass declarerPoC = contract.declarer.getPointOfCompass();
	PointsOfCompass lastRoundWinner = declarerPoC;

	for (int trickNr = 0; trickNr < 13; trickNr++)
	{
		Trick trick(denomination);
		PointsOfCompass playerInd;
		int i;
		for (i=0, playerInd = lastRoundWinner; i < 4; i++, playerInd = (playerInd + 1)%4)
		{
			Card card;
			//
			//wczytywanie karty
			//
			trick.add((Player)players[myPointsOfCompass], card);
			//TODO: czemu wymusza to rzutowanie?? typdef?
		}
		lastRoundWinner = trick.getWinner().getPointOfCompass();
		//
		//dodanie lewy do wyniku
		//
	}
}
