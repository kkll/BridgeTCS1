#include <vector>
#include "Trick.hpp"

class Player;

PlayerAndCard::PlayerAndCard(const Player& player, const Card& card) : player(player), card(card){}


Trick::Trick(Denomination) : denomination(Denomination) {}
bool Trick::add(const Player &, const Card &){
	cards.push_back(PlayerAndCard(Player,Card));
}
Player const& Trick::getWinner(){

	PlayerAndCard* actualWinner=cards.begin();

	for(vector<PlayerAndCard>::iterator it=cards.begin()+1;it!=cards.end();it++){
		if((it->card.suit==denomination && actualWinner->card.suit==denomination)
				|| (it->card.suit==actualWinner->card.suit)){
			if(actualWinner->card.rank < it->card.rank) actualWinner = it;
		}
		if(it->card.suit==denomination && actualWinner->card.suit!=denomination) actualWinner = it;
	}
	return actualWinner->player;
}

