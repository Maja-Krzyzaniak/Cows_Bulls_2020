/* The game logic (no view code or direct user interaction)
The game is simple guess the word game based on Mastermind
*/

#pragma once
#include <string>

// to make syntax Unreal friendly
using FString = std::string;
using int32 = int;

struct FCowBullCount 
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Wrong_Lenght,
	Not_Isogram,
	Not_Lowercase
};
class FCowBullGame 
{
public:
	FCowBullGame(); // constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;

	void Reset();
	FCowBullCount SubmitValidGuess(FString);


	// ^^ Please try and ignore this and focus on the interface above ^^
private:
	// see constructor for initialisation
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameIsWon;

	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;
};