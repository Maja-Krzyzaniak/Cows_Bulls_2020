#include "FCowBullGame.h"

using int32 = int;

FCowBullGame::FCowBullGame() { Reset(); }

int32 FCowBullGame::GetMaxTries() const { return MyMaxTries; }
int32 FCowBullGame::GetCurrentTry() const { return MyCurrentTry; }

void FCowBullGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}

bool FCowBullGame::IsGameWon() const
{
	return false;
}

bool FCowBullGame::CheckGuessValidity(FString)
{
	return false;
}

// receives a VALID guess, incriments turn, and returns count
CowBullCount FCowBullGame::SubmitGuess(FString)
{
	// incriment the turn number
	MyCurrentTry++;

	// setup return variable
	CowBullCount CowBullCount; 

	// loop through all letters in the guess
       // compare letters against hidden word

	return CowBullCount;
}
