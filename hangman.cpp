/**
* listhelpers.hpp has been provided by the instructor as starter code
* contains the following procedures to work with lists:
* display, append, insert, remove, length
*/
#include "listhelpers.hpp"


#include <cstdlib>   // srand, rand
#include <ctime>     // time
#include <iostream>  // std::cin, std::cout
#include <string>    // std::string, std::getline
#include <vector>    // std::vector


std::vector<std::string> hint = std::vector<std::string>(8, "_");    // Note that hint is globally available; we want it to be like this for this project


std::vector<std::string> getHint(std::string secret, char guessLetter)
{
    int index = 0;
    while (index < sizeof(secret))
    {
        if (secret[index] == guessLetter)
        {
            hint[index] = secret[index];
        }
            index = index + 1;
    }
    return hint;
}


bool letterIn (std::string secret, char guessLetter)
{
    int index = 0;
    while (index < sizeof(secret))
    {
        if (secret[index] == guessLetter)
        {
            return true;
        }
        index = index + 1;
    }
    return false;
}


bool wordFinish (std::vector<std::string> hint)
{
    int index = 0;
    while (index < sizeof(hint))
    {
        if (hint[index] == "_")
        {
            return false;
        }
        index = index + 1;
    }
    return true;
}


int main()
{
    srand(time(0));


    std::vector<std::string> wordList = {
        "solution",
        "mountain",
        "platinum",
        "alphabet",
        "necklace",
        "elevator",
        "diamonds",
        "fragrant",
        "velocity",
        "graduate",
        "nebraska",
        "tropical",
        "evidence",
        "involved",
        "shopping",
        "baseball",
        "kangaroo",
        "horrible",
    };
   
    std::string answer = wordList[rand() % length(wordList)];
    std::cout << "secret word: " << answer << std::endl;




    char letterGuess;
    std::string wordGuess = "";
    int lives = 10;
   
   
    std::cout << "Welcome to Hangman!\n";
    std::cout << "play? (y/n)" << std::endl;
    std::cin >> wordGuess;
    if (wordGuess == "y")
    {
             std::cout << "enter your guess: " << std::endl;
             std::cin >> wordGuess;
     while ((lives > 0) && !(wordFinish))  
     {
         std::cout << "\nEnter your guess: ";
         std::cin >> letterGuess;
         getHint(answer, letterGuess);
         display(hint);
         wordFinish(hint);
      
         if (letterIn(answer, letterGuess) == false)
         {
             lives--;
            
         }
         std::cout << "you have " << lives << " lives left to guess the word" << std::endl << std::endl;
        
     std::cout << "game over! play again? (y/n)" << std::endl << std::endl;
 }
 }
     return 0;
}