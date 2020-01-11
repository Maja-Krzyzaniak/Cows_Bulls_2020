#include "FCowBullGame.h"

using int32 = int;

FCowBullGame::FCowBullGame() { Reset(); }

int32 FCowBullGame::GetMaxTries() const { return MyMaxTries; }
int32 FCowBullGame::GetCurrentTry() const { return MyCurrentTry; }

void FCowBullGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	MyCurrentTry = 1;
}

bool FCowBullGame::IsGameWon() const
{
	return false;
}

bool FCowBullGame::CheckGuessValidity(FString)
{
	return false;
}
