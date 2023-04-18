#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
#include <string>

using namespace std;

namespace ariel{

    class Card{

        private:
        int num;
        std::string suit;

        public:
        Card(int num, string suit);
        int compareTo(Card other);
    };
    
}

#endif