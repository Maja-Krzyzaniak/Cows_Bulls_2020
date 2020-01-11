#pragma once
#include <string>

using FString = std::string;
using int32 = int;

class FCowBullGame {
public:
	FCowBullGame(); // constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // TODO make a more rich return value.
	bool CheckGuessValidity(FString); // TODO make a more rich return value.
	// provide a method for counting cows & bulls and increasing turn number


	// ^^ Please try and ignore this and focus on the interface above ^^
private:
	// see constructor for initialisation
	int32 MyCurrentTry;
	int32 MyMaxTries;
};