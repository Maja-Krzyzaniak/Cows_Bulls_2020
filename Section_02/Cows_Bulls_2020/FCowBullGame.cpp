#include "FCowBullGame.h"

using int32 = int;

FCowBullGame::FCowBullGame() { Reset(); }

int32 FCowBullGame::GetMaxTries() const { return MyMaxTries; }
int32 FCowBullGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FCowBullGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

void FCowBullGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet"; 
	
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}

bool FCowBullGame::IsGameWon() const
{
	return false;
}

bool FCowBullGame::CheckGuessValidity(FString) const
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
	for (int32 MHWChar = 0; MHWChar < HiddenWordLenght; MHWChar++) 
	{
		// compare letters against hidden word
		for (int32 GChar = 0; GChar < HiddenWordLenght; GChar++) 
		{
			// if they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar]) {
				
				if (MHWChar == GChar) {  // if they're in the same place
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
