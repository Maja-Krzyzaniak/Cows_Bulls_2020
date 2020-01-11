#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// all values intialised to zero 
struct CowBullCount 
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FCowBullGame 
{
public:
	FCowBullGame(); // constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // TODO make a more rich return value.
	bool CheckGuessValidity(FString); // TODO make a more rich return value.
	CowBullCount SubmitGuess(FString);


	// ^^ Please try and ignore this and focus on the interface above ^^
private:
	// see constructor for initialisation
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};