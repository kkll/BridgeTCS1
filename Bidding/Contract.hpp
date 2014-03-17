#ifndef CONTRACT_HPP
#define CONTRACT_HPP
#include "Denomination.hpp"

class myPlayer;
using Player = myPlayer;

struct Contract
{
	int level;
	Denomination denomination;
	Player& declarer;
	bool redeal;
};
#endif
