#include <iostream>
#include <string>

using namespace std;

int main() 
{
	constexpr int WORD_LENGTH = 9;
	

	// introduce the game
	cout << "Welcome to Bull Cow Game, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";

	// get a guess from the player
	cout << "Enter your Guess: ";
	string Guess = "";
	getline(cin,Guess);

	// repeat the guess back to them
	cout << "You guessed: " << Guess << endl;
	
	// get a guess from the player
	cout << "Enter your Guess: ";
	getline(cin, Guess);

	// repeat the guess back to them
	cout << "You guessed: " << Guess << endl;
	cout << endl;


	return 0;
}
