#ifndef Player_HPP
#define Player_HPP

#include <iostream>
#include <string>
using namespace std;

namespace ariel{

    class Player{

        private:
        string name;
        int stackSize;
        int cardsTaken;

        public:
        Player(string name); //Constructor
        // ~Player(); //Destructor
        int stacksize();
        int cardesTaken();

        //Getters & Setters
        void setName(string);
        string getName();


    };
}

#endif