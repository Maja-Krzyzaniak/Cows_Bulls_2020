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
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

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
	std::cout << "\n\nWelcome to Cows and Bulls, a raw word game.\n";
	std::cout << std::endl;
	std::cout << "          }   {        )___(" << std::endl;
	std::cout << "          (o o)        (o o) " << std::endl;
	std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
	std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
	std::cout << " *  |-,--- |              |--'''|  * " << std::endl;
	std::cout << "    ^      ^              ^      ^ " << std::endl;
	std::cout << "Can you guess the " << CBGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	CBGame.Reset();
	int32 MaxTries = CBGame.GetMaxTries();
	
	// loop asking for guesses while the game
	// is NOT won and there are tries still remaining
	while(!CBGame.IsGameWon() && CBGame.GetCurrentTry() <= MaxTries) { 
		FText Guess = GetValidGuess();
	
		// submit valid guess to the game and receive counts
		FCowBullCount CowBullCount =  CBGame.SubmitValidGuess(Guess);

		std::cout << "Cows = " << CowBullCount.Cows;
		std::cout << ". Bulls = " << CowBullCount.Bulls << "\n\n";
	}
	PrintGameSummary();
	return;
}

// loop continually until the user gives a valid guess
FText GetValidGuess()
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		// get a guess from the player
		int32 CurrentTry = CBGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << " of " << CBGame.GetMaxTries();
		std::cout << ". Enter your guess: ";
		std::getline(std::cin, Guess);

		// check status and give feedback
		 Status = CBGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Lenght:
			std::cout << "Please enter a " << CBGame.GetHiddenWordLength() << " letter word.\n\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters.\n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters.\n\n";
			break;
		default:
			// assume the guess is valid
			break;
		}
	} while (Status != EGuessStatus::OK); // keep looping until we get no errors
	return Guess;
}


bool AskToPlayAgain()
{
	std::cout << "Do you want to play again with the same hidden word (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}

void PrintGameSummary() 
{
	if (CBGame.IsGameWon()) 
	{
		std::cout << "H0I! Yu ges righ! Tem so proud of yu!\n";
	}
	else 
	{
		std::cout << "You idiot! In this world, it's guess or BE killed. Try your luck next time!\n";
	}
}