#include "FCowBullGame.h"
#include <map>
#define TMap std::map 
using int32 = int;

FCowBullGame::FCowBullGame() { Reset(); }

int32 FCowBullGame::GetMaxTries() const { return MyMaxTries; }
int32 FCowBullGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FCowBullGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FCowBullGame::IsGameWon() const { return bGameIsWon; }

void FCowBullGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet"; 
	
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}

EGuessStatus FCowBullGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess)) // if the guess isn't isogram
	{
		return EGuessStatus::Not_Isogram; 
	}
	else if (!IsLowercase(Guess)) // if the guess isn't all lowercase 
	{
		return EGuessStatus::Not_Lowercase; // TODO write a function
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
	if (CowBullCount.Bulls == WordLenght) {
		bGameIsWon = true;
	}
	else 
	{
		bGameIsWon = false;
	}
	return CowBullCount;
}

bool FCowBullGame::IsIsogram(FString Word) const
{
	// treat 0 and 1 letter words as isogram
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen; // setup our map
	for (auto Letter : Word) // for all letters of the word
	{
		Letter = tolower(Letter); // handle mixed case
		if (LetterSeen[Letter]) {// if the letter is in the map
			return false; // we do NOT have isogram
		}
		else
		{
			LetterSeen[Letter] = true; // add the letter to the map as seen
		}
	}
	return true; // for example in cases when 0/ is entered
}

bool FCowBullGame::IsLowercase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter)) // if not a lowercase letter
		{
			return false;
		}
	}
	return true;
}
