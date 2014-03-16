#ifndef Trick_hpp
#define Trick_hpp


#include "Card.hpp"
#include "Trick.hpp"

enum class myPointsOfCompass {
	N, E, S, W
};

using PointsOfCompass = myPointsOfCompass;

class myPlayer {
	PointsOfCompass pointOfCompass;
public:
	PointsOfCompass getPointOfCompass() const;
};

using Player = myPlayer;
using Trump = int;

class Play
{
public:
	/* Returns the number of tricks taken. It's up to the caller to convert it into points result. */
	/* declarer = rozgrywajacy
	 * ?? Should take the trump or the whole contract as an argument?? */
	int doPlay (Player players[], PointsOfCompass declarer, Denomination denomination);
};

#endif
