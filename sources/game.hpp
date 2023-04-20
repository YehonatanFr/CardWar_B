#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "player.hpp"
#include "card.hpp"
#include <string>

namespace ariel{

    class Game{

    private:
        Player &tempPlayer1;
        Player &tempPlayer2;
        int drawRate;
        vector<Card> deck;
        vector<string> turns;
        
    public:
        Game(Player &player1, Player &player2);
        void initDeck();
        void shuffleDeck();
        void CardsDeal();

        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printPlayerStats(Player& player, double winRate, int cardsWon);
        void printStats();

    };

}

#endif