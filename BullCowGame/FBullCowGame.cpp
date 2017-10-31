#include "FBullCowGame.h"
#include <iostream>
#include <map>
#define TMap std::map

using FString = std::string;
using int32 = int;

FbullCowGame::FbullCowGame() { Reset(); }

int FbullCowGame::GetMaxTries() const { return MyMaxTries; }
int FbullCowGame::GetCurrentTry() const { return MyCurrentTry; }
bool FbullCowGame::IsGameWon() const { return bGameIsWon; }

int32 FbullCowGame::GetHiddenWordLenth() const { return MyHiddenWord.length(); }



void FbullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;

}







EGuessStatus FbullCowGame::CheckGuessValidity(FString Guess) const
{
	
	if (!IsIsogram(Guess))// If the guess isn't an isogram, return an error
	{
		
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowercase(Guess)) // if the guess isn't all lowercase, return an error 
	{ // TODO write function
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLenth()) // if the guess length is wrong return an error
	{
		return EGuessStatus::Wrong_Length;
	}
	else if (false) // if word has a number in it return an error
	{
		return EGuessStatus::Not_All_Letters;
	}
	else { return EGuessStatus::OK; }
	
	
	
	
	// else return OK
}






// Reveives a VALID guess, increments turn, and returns count
FBullCowCount FbullCowGame::SubmitValidGuess(FString Guess)
{
	

	FBullCowCount BullCowCount;

	MyCurrentTry++;
	//FBullCowCount BullCowCount;

	// loop through all letters in the guess
	int32 WordLength = MyHiddenWord.length();
	for (int32 MyHWChar = 0; MyHWChar < WordLength; MyHWChar++) 
	{
		for (int32 GChar = 0; GChar < WordLength; GChar++)
		{
			// compare letters against the guess word
			if (MyHiddenWord[MyHWChar] == Guess[GChar]) 
			{
				
				
				// if they match then increment bulls if they are in the same place
				if (MyHWChar == GChar) { BullCowCount.Bulls ++; }

				// increment cows if they are not
				else { BullCowCount.Cows++; }
			}
		
		}
	}

	if (BullCowCount.Bulls == WordLength) { bGameIsWon = true; }
	else { bGameIsWon = false; }

	return BullCowCount;
}

bool FbullCowGame::IsIsogram(FString Guess) const
{
	// treat 0 and 1 letter words as isogramsz`
	if (Guess.length() <= 1) { return true; }
	TMap<char, bool> LetterSeen; // setup TMap
	
	for (auto Letter : Guess) // Loop through each letter
	{
	
		Letter = tolower(Letter); // handle mixed case
		
		if (LetterSeen[Letter]) { return false; } // Check if Letter has already been seen if so return false
		else { LetterSeen[Letter] = true; } // if it has not been seen add it to the map
		
		
	}

	
	return true; // return true after finishing the loop and not finding a dubplicate
}

bool FbullCowGame::IsLowercase(FString Guess) const
{
		for (auto Letter : Guess) // Loop through each letter
		{
			if (!islower(Letter)) {	return false; }
			
		}
		
	return true;
}
