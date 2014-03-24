#include <vector>
#include "Trick.hpp"



bool operator ==(Card card,Denomination trump){
    return static_cast<int> (trump)==static_cast<int> (card.suit);
}
bool operator ==(Card card1,Card card2){
    return card1.suit==card2.suit;
}






