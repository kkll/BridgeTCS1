#ifndef Play_hpp
#define Play_hpp

#include "../Bidding/Contract.hpp"
#include "Trick.hpp"
#include "../Rubber/Arbiter.hpp"



using Player = int;
using Trump = int;

class Play
{
public:
	/* Returns the number of tricks taken. It's up to the caller to convert it into points result. */
	int doPlay (Arbiter arbiters[], Contract contract);
};

#endif
