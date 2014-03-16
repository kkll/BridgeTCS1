#include <vector>
#include "Trick.hpp"

class Player;

Trick::Trick(Denomination) : denomination(Denomination) {}
bool Trick::add(const Player &, const Card &){
	PlayerAndCard playerAndCard;
	playerAndCard.card=Card;
	playerAndCard.player=Player;
	cards.push_back(playerAndCard);
}
Player const& Trick::getWinner(){
	return cards.front();
}

