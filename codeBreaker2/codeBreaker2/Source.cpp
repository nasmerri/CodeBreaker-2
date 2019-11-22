/*
1. Display Title of the program to the user 
 2.Ask the recruit to log in using their name 
 3.Hold the recruit's name in a var, and address them by it throughout the simulation. 
 4.Display an overview of what Keywords II is to the recruit 
 5.Display directions to the recruit on how to use Keywords 
 6.Create a collection of 10 words you had written down manually 
 7.Create an int var to count the number of simulations being run starting at 1
 8.Display the simulation # is starting to the recruit. 
 9.Pick new 3 random words from your collection as the secret code word the recruit has to guess. 
 10.While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
 11.Tell recruit how many incorrect guesses he or she has left
 12.Show recruit the letters he or she has guessed
 13.Show player how much of the secret word he or she has guessed
 14.Get recruit's next guess
 15.While recruit has entered a letter that he or she has already guessed
 16.Get recruit ’s guess 
 17.add the new guess to the group of used letters
 18.If the guess is in the secret word
 19.Tell the recruit the guess is correct
 20.Update the word guessed so far with the new letter
 21.Otherwise Tell the recruit the guess is incorrect
 22.Increment the number of incorrect guesses the recruit has made
23.If the recruit has made too many incorrect guesses
 24.Tell the recruit that he or she has failed the Keywords II course.
Otherwise
 25.Congratulate the recruit on guessing the secret word
 26.Ask the recruit if they would like to run the simulation again
 27.If the recruit wants to run the simulation again
 28.Increment the number of simulations ran counter
 29.Move program execution back up to // Display the simulation # is starting to the recruit. 
 Otherwise 
 30.Display End of Simulations to the recruit
 31.Pause the Simulation with press any key to continue */

	

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	string answer;
	do
	{
		// welcome user 
		cout << "\t\t\tWelcome to Keywords 2.\n\n";
		cout << "Please give us something to call you.\n";

		//store user name
		string name;
		cin >> name;


		//explanation of the game
		cout << "Welcome, " << name << ", Keywords 2 is basically hangman.";
		cout << "You guess what letters are in the given blanks of said words within the 3 guesses you have.\n";


		// Stores the 10 words for the key word test 
		enum fields { WORD, NUM_FIELDS };
		const int NUM_WORDS = 10;
		const string WORDS[NUM_WORDS][NUM_FIELDS] =

		{
		{"target"},
		{"gun"},
		{"laser"},
		{"suit"},
		{"Googles"},
		{"handgun"},
		{"chopper"},
		{"jet"},
		{"poison"},
		{"sneak"},
		};


		//simulation value
		int simulation = 1;

		srand(static_cast<unsigned int>(time(0)));
		int choice = (rand() % NUM_WORDS);
		string theWord = WORDS[choice][WORD];
		string guessedLetters;
		string guess(theWord.length(), '_');
		string guessLetter;
		int incorrect = 0;

		cout << "Your word is: " << guess << ".";
		cout << " Total incorrect guesses 3/" << incorrect << ".";
		cout << "\nThe letters already guessed: " << guessedLetters << " .";
		cout << "\n\n Your guess: ";


		while (guess != theWord && incorrect < 3)
		{
			cin >> guessLetter;

			while (guessedLetters.find(guessLetter) != string::npos)
			{

				cin >> guessLetter;
			}

			if (theWord.find(guessLetter) != string::npos)
			{
				//letter correct 
				for (int i = 0; i < theWord.length(); i++)
				{
					if (theWord[i] == guessLetter[0])
					{
						guess[i] = guessLetter[0];

						cout << "Correct!";
						cout << "\nTotal incorrect guesses 3/" << incorrect << ".";
						cout << "\nThe letters already guessed: " << guessedLetters << " .";
						cout << "\nYour word is: " << guess << ".";
						cout << "\n\nYour guess: ";



					}







				}
			}



			if (guessLetter != theWord)
			{
				incorrect++;

				cout << "Incorrect.";
				cout << "\nTotal incorrect guesses 3/" << incorrect << ".";
				cout << "\nThe letters already guessed: " << guessedLetters << " .";
				cout << "\nYour word is: " << guess << ".";
				cout << "\n\nYour guess: ";


				// main algorithm
			}
			
			if (guess == theWord)
			{
				cout << "\n\nCongratulations that is the word!";
			}



		}

		
		cout << "\nWould you like to play again? y/n ";
		cin >> answer;


	}while (answer != "n");


	









}

