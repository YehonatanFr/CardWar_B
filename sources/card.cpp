#include "card.hpp"
using namespace ariel;

Card::Card(int num, string suit){
    this->num = num;
    this->suit = suit;
}

int Card::compareTo(Card other){
    return 0;
}
