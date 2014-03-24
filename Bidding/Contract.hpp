#ifndef CONTRACT_HPP
#define CONTRACT_HPP
#include "Denomination.hpp"


struct Contract
{
	int level;
	Denomination trump;
	int declarer;
	bool redeal;
};
#endif
