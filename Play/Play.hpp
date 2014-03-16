#include "Card.hpp"
#include "Trick.hpp"

enum class myPointsOfCompass {
	N, E, S, W
};

using PointsOfCompass = myPointsOfCompass;

class myPlayer {
public:
	PointsOfCompass pointOfCompass;
	PointsOfCompass getPointOfCompass() const
	{
		return pointOfCompass;
	}
};

using Player = myPlayer;
using Trump = int;

class Play
{
public:
	/* Returns the number of tricks taken. It's up to the caller to convert it into points result. */
	/* declarer = rozgrywajacy
	 * ?? Should take the trump or the whole contract as an argument?? */
	int doPlay (Player players[], PointsOfCompass declarer, Trump trump)
	{
		int tricksTaken = 0;
		PointsOfCompass lastRoundWinner = declarer;
		for (int trickNr = 0; trickNr < 13; trickNr++)
		{
			Trick trick;
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
};
