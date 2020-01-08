#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuessAndPrintBack();

// the entry point for our application
int main() 
{
	PrintIntro();

	// loop for the number of turns asking for guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++)
	{
		GetGuessAndPrintBack();
		cout << endl;
	}

	return 0;
}

// Introduce the game
void PrintIntro() 
{
	constexpr int WORLD_LENGHT = 5;
	cout << "Welcome to Cows and Bulls, a raw word game.\n";
	cout << "Can you guess the " << WORLD_LENGHT;
	cout << " letter isogram I'm thinking of?\n";
	cout << endl;
	return;
}


string GetGuessAndPrintBack() 
{
	// get a guess from the player
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);

	// print the guess back to them
	cout << "Your guess was: " << Guess << endl;
	return Guess;
}