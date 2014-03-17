#include <vector>
#include "Trick.hpp"



PlayerAndCard::PlayerAndCard(const Player & player, const Card & card) : card(card), player(player){}


Trick::Trick(Denomination denomination){
    denomination=denomination;
}
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

