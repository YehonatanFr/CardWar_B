#ifndef Player_HPP
#define Player_HPP

#include <iostream>
#include <string>
#include <vector>
#include "card.hpp"
using namespace std;

namespace ariel{

    class Player{

        private:
        string name;
        vector<Card> myStack;
        int cardsTaken;
        int winRate;

        public:
        Player(string name); //Constructor
        int stacksize();
        int cardesTaken();

        //Getters & Setters
        void setName(string);
        string getName();
        vector<Card> getMyStack();
        int getWinRate();

        Card playCard();
        void addCard(Card);
        void PlusCardsWin(int);
        void WinCount();

    };
}

#endif