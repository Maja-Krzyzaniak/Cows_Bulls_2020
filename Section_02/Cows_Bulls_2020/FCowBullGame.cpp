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

EGuessStatus FCowBullGame::CheckGuessValidity(FString Guess) const
{
	if (false) // if the guess isn't isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false) // if the guess isn't all lowercase
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength()) // if the guess lenght is wrong
	{
		return EGuessStatus::Wrong_Lenght;
	}
	else
	{
		return EGuessStatus::OK;
	}
	
}

// receives a VALID guess, incriments turn, and returns count
FCowBullCount FCowBullGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FCowBullCount CowBullCount; 
	int32 WordLenght = MyHiddenWord.length(); // assuming same lenght as guess

	// loop through all letters in the hidden word
	for (int32 MHWChar = 0; MHWChar < WordLenght; MHWChar++) 
	{
		// compare letters against the guess
		for (int32 GChar = 0; GChar < WordLenght; GChar++) 
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
