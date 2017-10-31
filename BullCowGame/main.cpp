/* This is the console executable that makes use of the BullCow Class
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FbullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
FText GetValidGuess();
void PlayGame();
bool AskToPlayAgain();
void PrintGameSummary();

FbullCowGame BCGame;

// the entry point for our Program
int main()
{
	

	do {
		
		PrintIntro();
		PlayGame();
		BCGame.Reset();
		
	}
	while (AskToPlayAgain() == true);
	std::cout << "Goodbye!\n\n";
	return 0; // Exit application
}

void PrintIntro() 
{
	

	// introduce the game
	std::cout << "\n\nWelcome to Bull Cow Game, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLenth() << " letter isogram I'm thinking of?\n\n";
}


// loop coninually until we get a valid guess from the player
FText GetValidGuess() 
{
	FText Guess = "";

	EGuessStatus Status = EGuessStatus::INVALID;
	do {
	int32 CurrentTry = BCGame.GetCurrentTry();
	
	
	std::cout << "Try " <<  CurrentTry << ". Enter your Guess: ";
	getline(std::cin, Guess);

	Status = BCGame.CheckGuessValidity(Guess);
	switch (Status)
	{
	case EGuessStatus::Wrong_Length:
		std::cout << "Please enter a " << BCGame.GetHiddenWordLenth() << " letter word.\n";
		break;
	case EGuessStatus::Not_Isogram:
		std::cout << "Word is not an Isogram.";
		break;
	case EGuessStatus::Not_Lowercase:
		std::cout << "Please enter all lowercase letters.";
		break;
	case EGuessStatus::Not_All_Letters:
		std::cout << "Not a word please enter all letters.";
		break;
	default:
		// assume the guess is valid
		break;
	}
	std::cout << std::endl;
	} while (Status != EGuessStatus::OK); // Keep looping until no errors
	return Guess;
}




//play the game
void PlayGame() 
{
	BCGame.Reset();

	FText Guess;
	
	
	int32 MaxTries = BCGame.GetMaxTries();
	
	// loop for the number of turns asking for guesses while the game is not won and there are still tries remaining

	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries){
		Guess = GetValidGuess(); 

		

		// Submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";

		
		
	} 
	PrintGameSummary();
	



}


//ask user if they want to play again
bool AskToPlayAgain()
{
	std::cout << "Do you want to play again with the same hidden word? (y/n): ";
	FText Response = "";
	getline(std::cin, Response);
	std::cout << std::endl;
	return (Response[0] == 'y' || Response[0] == 'Y');
}

void PrintGameSummary() 
{
	if (BCGame.IsGameWon())
	{
		std::cout << "WELL DONE  -  YOU WIN!\n";
	}
	else 
	{
		std::cout << "Better luck next time!\n";
	}
}



