#include <vector>
#include "Trick.hpp"



PlayerAndCard::PlayerAndCard(const Card & card, const Player & player) : card(card), player(player){}

bool operator ==(Card card,Denomination trump){
    return static_cast<int> (trump)==static_cast<int> (card.suit);
}
bool operator ==(Card card1,Card card2){
    return card1.suit==card2.suit;
}

Trick::Trick(Denomination trump)

void Trick::add(const Player & player , const Card & card){
	cards.push_back(PlayerAndCard(card,player));
}
Player const& Trick::getWinner(){

	PlayerAndCard* actualWinner = cards.begin(); //iterator tu to rozwiązanie tymczasowe z braku lepszego na ten moment


	for(std::vector<PlayerAndCard>::iterator it=cards.begin()+1;it!=cards.end();it++){
		if((it->card==trump && actualWinner->card==trump) || (it->card==actualWinner->card)){
			if(actualWinner->card.rank < it->card.rank) actualWinner = it;
		}
		if(it->card==trump && (!(actualWinner->card==trump))) actualWinner = it;
	}
	return actualWinner->player;
}

