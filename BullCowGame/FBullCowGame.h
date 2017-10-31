#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount 
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus 
{
	OK,
	Not_Isogram,
	Not_All_Letters,
	Not_Lowercase,
	Wrong_Length,
	INVALID
};

class FbullCowGame 
{
public:

	FbullCowGame(); // Constructor
	
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	int32 GetHiddenWordLenth() const;
	EGuessStatus CheckGuessValidity(FString) const; 

	

	void Reset(); // TODO make a more rich return value.
	
	FBullCowCount SubmitValidGuess(FString);

// ^^ Please try and ignore this and focus on the interface above ^^
private:
	//See constructor fo rinitialization
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameIsWon;
	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;
};