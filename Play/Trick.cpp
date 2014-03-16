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

	PlayerAndCard actualWinner;
	actualWinner.card=cards.front().card; 
	actualWinner.player=cards.front().player;

	for(vector<PlayerAndCard>::iterator it=cards.begin()+1;it!=cards.end();it++){
		if((it->card.suit==denomination && actualWinner.card.suit==denomination) || (it->card.suit==actualWinner.card.suit)){
			if(actualWinner.card.rank < it->card.rank) actualWinner=(*it);	
		}
		if(it->card.suit==denomination && actualWinner.card.suit!=denomination) actualWinner=(*it);
	}
	return actualWinner;
}

