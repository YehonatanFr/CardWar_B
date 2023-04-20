#include "game.hpp"
#include "card.hpp"
#include "player.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <iostream>

using namespace ariel;
using namespace std;

Game::Game(Player &player1, Player &player2): tempPlayer1(player1),tempPlayer2(player2){
    this->deck = vector<Card>();
    this->turns = vector<string>();
    this->drawRate = 0;

    initDeck();
    shuffleDeck();
    CardsDeal();

}

void Game::initDeck(){
    for (int i = 1; i < 14; i++)
    {
        deck.push_back(Card (i, "Hearts"));
        deck.push_back(Card (i, "Diamonds"));
        deck.push_back(Card (i, "Clovers"));
        deck.push_back(Card (i, "Pikes"));
    }
}

//From gpt
void Game::shuffleDeck(){
    random_device rd;
    mt19937 g(rd());
    shuffle(deck.begin(), deck.end(), g);
}

void Game::CardsDeal(){
    for (size_t i = 0; i < deck.size(); i++)
    {
        if (i % 2 == 0)
            tempPlayer1.addCard(deck[i]);
        else
            tempPlayer2.addCard(deck[i]);
    }
}

void Game::playTurn(){
    if (this->tempPlayer1.stacksize() == 0 || this->tempPlayer2.stacksize() == 0)
    {
        throw ("Cannot play, there is a problem");
    }

    if (&tempPlayer1 == &tempPlayer2)
    {
        throw runtime_error("Game cannot play by same player");
    }

    string LastTurn = "";

    Card CardP1 = tempPlayer1.playCard();
    Card CardP2 = tempPlayer2.playCard();

    int numOfCardsToTake = 2;

    while(CardP1.compareTo(CardP2) == 0)
    {
        LastTurn += tempPlayer1.getName() + " Played " + CardP1.toString() + ", " + tempPlayer2.getName() + " Played " + CardP2.toString() + " Finish the round with draw. " ;
        drawRate++;
        if (tempPlayer1.stacksize() == 0 || tempPlayer1.stacksize() == 0)
        {
            cout << "The game is over with a draw on the last turn" << endl;
            drawRate++;
            tempPlayer1.PlusCardsWin(numOfCardsToTake / 2);
            tempPlayer1.PlusCardsWin(numOfCardsToTake / 2);
            return;
        }

        tempPlayer1.playCard();
        tempPlayer2.playCard();

        numOfCardsToTake+=2;

        if (tempPlayer1.stacksize() == 0 || tempPlayer1.stacksize() == 0)
        {
            cout << "The game is over with a draw on the last turn" << endl;
            drawRate++;
            tempPlayer1.PlusCardsWin(numOfCardsToTake / 2);
            tempPlayer1.PlusCardsWin(numOfCardsToTake / 2);
            return;
        }

        CardP1 = tempPlayer1.playCard();
        CardP2 = tempPlayer2.playCard();
    
        numOfCardsToTake+=2;

    }

    if(CardP1.compareTo(CardP2) == 1)
    {
        tempPlayer1.PlusCardsWin(numOfCardsToTake);
        LastTurn+=tempPlayer1.getName() + " Played " + CardP1.toString() + " , " + tempPlayer2.getName() + " Played " + CardP2.toString() + ". " + tempPlayer1.getName() + " Won in the game!!" ; 
        tempPlayer1.WinCount(); 
    }
    else
    {
        tempPlayer2.PlusCardsWin(numOfCardsToTake);
        LastTurn+=tempPlayer1.getName() + " Played " + CardP1.toString() + " , " + tempPlayer2.getName() + " Played " + CardP2.toString() + ". " + tempPlayer2.getName() + " Won in the game!!" ; 
        tempPlayer2.WinCount(); 
    }
    
    turns.push_back(LastTurn);

} 

void Game::playAll(){
    while(this->tempPlayer1.stacksize() != 0 && this->tempPlayer2.stacksize() != 0)
    {
        this->playTurn();
    }
}

void Game::printLog(){
    for (auto turn : turns) {
        cout << turn << endl;
    }
}
void Game::printWiner(){
    // if(this-> turns.size() != 26)
    // {
    //     cout << "Game is not over yet!" << endl;
    //     return;
    // }
    if(tempPlayer1.cardesTaken() > tempPlayer2.cardesTaken())
            cout << tempPlayer1.getName() + " Won" << endl;
        
    else if(tempPlayer1.cardesTaken() < tempPlayer2.cardesTaken())
            cout << tempPlayer2.getName() + " Won" << endl;
        
    else cout << "The game ends with tie!" << endl;
}

void Game::printPlayerStats(Player& player, double winRate, int cardsWon) {
    cout << player.getName() << " Stats: "
         << "Win Rate: " << winRate << "%, Cards Won: " << cardsWon << endl;
}


void Game::printStats() 
{
    int SumTurns = turns.size();
    double P1Wins = (double)tempPlayer1.getWinRate() / SumTurns * 100;
    double P2Wins = (double)tempPlayer2.getWinRate() / SumTurns * 100;
    double SumDraw = (double)drawRate / SumTurns * 100;

    cout << "SDraw: " << SumDraw << endl;
    cout << "Drae: " << drawRate << endl;
    printPlayerStats(tempPlayer1, P1Wins, tempPlayer1.cardesTaken());
    printPlayerStats(tempPlayer2, P2Wins, tempPlayer2.cardesTaken());
    cout << "Draw Rate: " << SumDraw << "%, Draws: " << drawRate << endl;
}

void Game::printLastTurn(){
    if (turns.empty())
    {
        throw runtime_error("Cannot print last turn, please start to play");
    }
    cout << turns[turns.size() - 1] << endl;
}