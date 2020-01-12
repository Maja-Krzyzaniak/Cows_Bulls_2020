/* This is the console executable, that makes use of the CowBull class
This acts as the view in a MVC pattern, and is responsible for all user interaction. 
For game logic see FCowBullGame class.
*/

#include <iostream>
#include <string>
#include "FCowBullGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FCowBullGame CBGame; // instantiate a new game


// the entry point for our application
int main() 
{
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} 
	while (bPlayAgain);
	return 0; // exit the application
}

// Introduce the game
void PrintIntro() 
{
	std::cout << "Welcome to Cows and Bulls, a raw word game.\n";
	std::cout << "Can you guess the " << CBGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	CBGame.Reset();
	int32 MaxTries = CBGame.GetMaxTries();
	
	// loop for the number of turns asking for guesses
	for (int32 count = 1; count <= MaxTries; count++) // TODO change from FOR to WHILE 
	{
		FText Guess = GetGuess();

		EGuessStatus Status = CBGame.CheckGuessValidity(Guess);

		// submit valid guess to the game and receive counts
		FCowBullCount CowBullCount =  CBGame.SubmitGuess(Guess);

		// print the number of cows and bulls
		std::cout << "Cows = " << CowBullCount.Cows;
		std::cout << ". Bulls = " << CowBullCount.Bulls << std::endl;
		std::cout << std::endl;
	}
	// TODO summarize game
}

FText GetGuess() // TODO change to GetValidGuess
{
	int32 CurrentTry = CBGame.GetCurrentTry();

	// get a guess from the player
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}
