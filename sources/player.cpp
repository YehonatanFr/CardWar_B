#include "player.hpp"
using namespace ariel;
using namespace std;


Player::Player(string name){
    this->myStack = vector<Card>();
    this->name = name;
    this->cardsTaken = 0;
    this->winRate = 0;
}

int Player::cardesTaken() {
    return this->cardsTaken;
}
int Player::stacksize() {
    return this->myStack.size();
}

void Player::setName(string newName){
    this->name = newName;
    
}
        
string Player::getName(){
    return this->name;
}

vector<Card> Player::getMyStack(){
    return this->myStack;
}

int Player::getWinRate(){
    return this->winRate;
}


void Player::PlusCardsWin(int num){
    this->cardsTaken+=num;
}

void Player::WinCount(){
    this->winRate++;
}


void Player::addCard(Card card){
    this->myStack.push_back(card);
}

Card Player::playCard(){
    Card CardPlay = myStack.back();
    myStack.pop_back();
    return CardPlay;
}