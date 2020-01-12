#include "FCowBullGame.h"

using int32 = int;

FCowBullGame::FCowBullGame() { Reset(); }

int32 FCowBullGame::GetMaxTries() const { return MyMaxTries; }
int32 FCowBullGame::GetCurrentTry() const { return MyCurrentTry; }

void FCowBullGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "ant";
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
FCowBullCount FCowBullGame::SubmitGuess(FString Guess)
{
	// incriment the turn number
	MyCurrentTry++;

	// setup return variable
	FCowBullCount CowBullCount; 

	// loop through all letters in the guess
	int32 HiddenWordLenght = MyHiddenWord.length();
	for (int32 i = 0; i < HiddenWordLenght; i++) {
		// compare letters against hidden word
		for (int32 j = 0; j < HiddenWordLenght; j++) {
			// if they match then
			if (Guess[i] == MyHiddenWord[i]) {
				
				if (i == j) {  // if they're in the same place
					CowBullCount.Bulls++; // incriment bulls
				}
				else {
					CowBullCount.Cows++; // incriment cows
				}
			}
		}
	}
	return CowBullCount;
}
