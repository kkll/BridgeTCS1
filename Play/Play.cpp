#include "Play.hpp"

//using PointsOfCompass = myPointsOfCompass;


PointsOfCompass myPlayer::getPointOfCompass() const
{
	return pointOfCompass;
}

PointsOfCompass operator++(PointsOfCompass pointsOfCompass){
    return static_cast<PointsOfCompass>( (static_cast<int>(pointsOfCompass)+1) %4 );
}

//using Player = myPlayer;
//using Trump = int;

/* Returns the number of tricks taken. It's up to the caller to convert it into points result. */
/* declarer = rozgrywajacy
 * ?? Should take the denomination or the whole contract as an argument?? */
int Play::doPlay (Player players[], Contract contract)
{
	int tricksTaken = 0;
	Denomination denomination = contract.denomination;
	const PointsOfCompass declarerPoC = contract.declarer.getPointOfCompass();
	PointsOfCompass lastRoundWinnerPoC = declarerPoC;

	for (int trickNr = 0; trickNr < 13; trickNr++)
	{
        Trick trick(denomination);
		PointsOfCompass playerInd;
		int i;
		for (i=0, playerInd = lastRoundWinnerPoC; i < 4; i++, ++playerInd)
		{
			Card card (Rank::ACE, Suit::SPADES);
			//
			//TODO wczytywanie karty
			//
			trick.add(players[static_cast<int>(playerInd)], card);
		}
		lastRoundWinnerPoC = trick.getWinner().getPointOfCompass();

        if(lastRoundWinnerPoC == declarerPoC) tricksTaken++;
        else
        {}//TODO: uzgodniæ czy w Playerze którego dostaniemy bêdzie referencja do partnera
	}
	return tricksTaken;
}
