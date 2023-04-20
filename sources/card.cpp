#include "card.hpp"
using namespace ariel;

//Constructor for card
Card::Card(int num, string suit){
    this->num = num;
    this->suit = suit;
}


int Card::compareTo(Card other){
    if(this->num == other.num)
        return 0;
    if(this->num == 2 && other.num == 1) 
        return 1;
    if(this->num == 1 && other.num ==2)
        return -1;
    if(this->num < other.num)
        return -1;
    else 
        return 1;
}

string Card::toString(){
    if (this->num == 1) {
        return "Ace of " + this->suit;
    } else if (this->num == 11) {
        return "Jack of " + this->suit;
    } else if (this->num == 12) {
        return "Queen of " + this->suit;
    } else if (this->num == 13) {
        return "King of " + this->suit;
    } else {
        return to_string(this->num) + " of " + this->suit;
    }
}
