#include <iostream>
#include <string>
#include "FCowBullGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
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
	constexpr int WORLD_LENGHT = 5;
	std::cout << "Welcome to Cows and Bulls, a raw word game.\n";
	std::cout << "Can you guess the " << WORLD_LENGHT;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	int MaxTries = CBGame.GetMaxTries();
	
	// loop for the number of turns asking for guesses
	for (int count = 1; count <= MaxTries; count++)
	{
		std::string Guess = GetGuess();
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}
}

std::string GetGuess() 
{
	int CurrentTry = CBGame.GetCurrentTry();

	// get a guess from the player
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	std::string Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}
