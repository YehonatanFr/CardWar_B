#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"
#include <iostream>
#include <string>

namespace ariel{

    class Game{
        private:
        Player p1;
        Player p2;
        
        public:
        Game(Player player1, Player player2);
        // ~Game();
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();

    };

}

#endif