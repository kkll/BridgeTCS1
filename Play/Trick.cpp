#include <vector>
#include "Trick.hpp"



PlayerAndCard::PlayerAndCard(const Player & player, const Card & card) : card(card), player(player){}

bool operator ==(Card card,Denomination denomination){
    return static_cast<int> (denomination)==static_cast<int> (card.suit);
}
bool operator ==(Card card1,Card card2){
    return card1.suit==card2.suit;
}

Trick::Trick(Denomination denomination){
    denomination=denomination;
}
bool Trick::add(const Player & player , const Card & card){
	cards.push_back(PlayerAndCard(card,player));
}
Player const& Trick::getWinner(){

	std::vector<PlayerAndCard>::iterator actualWinner=cards.begin(); //iterator tu to rozwiązanie tymczasowe z braku lepszego na ten moment

	for(std::vector<PlayerAndCard>::iterator it=cards.begin()+1;it!=cards.end();it++){
		if(((*it).card==denomination && (*actualWinner).card==denomination)|| ((*it).card==(*actualWinner).card)){
			if((*actualWinner).card.rank < (*it).card.rank) actualWinner = it;
		}
		if((*it).card==denomination && (!((*actualWinner).card==denomination))) actualWinner = it;
	}
	return (*actualWinner).player;
}

