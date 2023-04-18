#include "player.hpp"
using namespace ariel;
using namespace std;


Player::Player(string name){
    this->name = name;
    this->cardsTaken = 0;
    this->stackSize = 26;
}

int Player::cardesTaken() {

    return this->cardsTaken;
}
int Player::stacksize() {
    
    return this->stackSize;
}

void Player::setName(string newName){
    this->name = newName;
    
}
        
string Player::getName(){
    return this->name;
}
