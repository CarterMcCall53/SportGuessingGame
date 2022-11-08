/* SportGuessingGame
*  Carter McCall
*  19 October 2022
*  Purpose:
*		Make a game where the user guesses a random sport
*  Modified 27 October 2022:
*		Fixed an issue where vectors coudn't read in due to an incorrectly typed operator
*		Made the input not caps sensitive and added drone racing as a game
*  Modified 28 October 2022:
*		Added archery, bowling, f1, and motogp
*       Made checks to make sure there arent too many or too little hints in the hints file
*		Changed the if statement checking if there are enough hints in the file from i < 115 to i < games.size() * 5 so 
*  it doesn't have to be manually updated
*		Added disc golf and surfing
*	Modified 31 October 2022:
*		Added biking, ESports, and air racing
*		Added a guess counter at the end of each round
*	Modified 1 November 2022:
*		Added hint counter for the "not enough hints" check (ln. 87)
*	Modified 2 November 2022:
*		Added martial arts
*	Modified 3 November 2022:
*		Added wake boarding
*	Modified 7 November 2022:
*		Added ability to keep track of average guesses per game
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <ctime>
#include <stdlib.h>
using namespace std;

vector<string> baseballHints, basketballHints, tennisHints, pickleballHints, footballHints, soccerHints, hockeyHints,
golfHints, volleyballHints, badmintonHints, rugbyHints, boxingHints, cricketHints, poolHints, dartsHints, skiingHints,
cornholeHints, horseshoesHints, archeryHints, bowlingHints, f1Hints, droneRacingHints, motogpHints, discGolfHints, surfingHints,
bikingHints, eSportsHints, airRacingHints, martialArtsHints, wakeBoardingHints, extra;

void hintRead() {
	int i = 0;
	ifstream inFile;
	string temp, hintsFile = "Hints.txt", gamesFile = "Games.txt";
	vector<string> games;
	inFile.open(gamesFile);
	if (!inFile) cout << "Problem reading games from file";
	else while (getline(inFile, temp)) games.push_back(temp);
	inFile.close();
	inFile.open(hintsFile);
	if (!inFile) cout << "Problem reading hints from file";
	else
	{
		while (getline(inFile, temp)) //reads in hints from the file until there is nothing else to read in
		{
			if (i < 5) baseballHints.push_back(temp);
			else if (i < 10 && i > 4) basketballHints.push_back(temp);
			else if (i < 15 && i > 9) tennisHints.push_back(temp);
			else if (i < 20 && i > 14) pickleballHints.push_back(temp);
			else if (i < 25 && i > 19) footballHints.push_back(temp);
			else if (i < 30 && i > 24) soccerHints.push_back(temp);
			else if (i < 35 && i > 29) hockeyHints.push_back(temp);
			else if (i < 40 && i > 34) golfHints.push_back(temp);
			else if (i < 45 && i > 39) volleyballHints.push_back(temp);
			else if (i < 50 && i > 44) badmintonHints.push_back(temp);
			else if (i < 55 && i > 49) rugbyHints.push_back(temp);
			else if (i < 60 && i > 54) boxingHints.push_back(temp);
			else if (i < 65 && i > 59) cricketHints.push_back(temp);
			else if (i < 70 && i > 64) poolHints.push_back(temp);
			else if (i < 75 && i > 69) dartsHints.push_back(temp);
			else if (i < 80 && i > 74) skiingHints.push_back(temp);
			else if (i < 85 && i > 79) cornholeHints.push_back(temp);
			else if (i < 90 && i > 84) horseshoesHints.push_back(temp);
			else if (i < 95 && i > 89) archeryHints.push_back(temp);
			else if (i < 100 && i > 94) bowlingHints.push_back(temp);
			else if (i < 105 && i > 99) f1Hints.push_back(temp);
			else if (i < 110 && i > 104) droneRacingHints.push_back(temp);
			else if (i < 115 && i > 109) motogpHints.push_back(temp);
			else if (i < 120 && i > 114) discGolfHints.push_back(temp);
			else if (i < 125 && i > 119) surfingHints.push_back(temp);
			else if (i < 130 && i > 124) bikingHints.push_back(temp);
			else if (i < 135 && i > 129) eSportsHints.push_back(temp);
			else if (i < 140 && i > 134) airRacingHints.push_back(temp);
			else if (i < 145 && i > 139) martialArtsHints.push_back(temp);
			else if (i < 150 && i > 144) wakeBoardingHints.push_back(temp);
			else extra.push_back(temp);
			i++;
		}
		inFile.close();
	}
	if (i < games.size() * 5) //checks too make sure that there are enough hints present in the hints file
	{
		cout << "THERE ARE NOT ENOUGH HINTS IN THE HINTS FILE. PLEASE MAKE SURE YOU HAVE "
			<< games.size() * 5 << " HINTS AND 5 HINTS FOR EACH GAME" << endl;
		cout << "YOU CURRENTLY HAVE " << i << " HINTS!" << endl;
		abort();
	}
	else if (extra.size() != 0) {
		cout << "THERE ARE EXTRA HINTS IN THE HINT FILE. THE EXTRA HINTS ARE AS FOLLOWS" << endl;
		for (string nm : extra) cout << nm << endl;
		abort();
	}
}

int hints(vector<string> a, int b) { //more or less the actual code for the game, checking if hints have already been used, using new hints, etc.
	srand(time(NULL));
	bool check = false, check2 = false;
	int hintNum[] = { 0, 0, 0, 0, 0 }, randNum, inputLength, numberOfGuesses = 0;
	string input, temp, answer, gamesFile = "Games.txt";
	ifstream inFile;
	vector<string> games;
	inFile.open(gamesFile);
	if (!inFile) {
		cout << "Problem reading games from file";
		abort();
	}
	else while (getline(inFile, temp)) games.push_back(temp);
	inFile.close();
	for (int i = 0; i < 5; i++)
	{
		randNum = rand() % 5;
		while (check == true) { //while loop makes sure we don't use a hint thats already been used
			for (int i = 0; i < 5; i++)
			{
				if (hintNum[i] != NULL) {
					if (randNum == i) {
						randNum = rand() % 5;
						check = true;
						break;
					}
					else if (randNum != i) check = false;
				}
			}
		}
		cout << "\n" << a[randNum] << endl; //prints the hint
		getline(cin, input);
		for (int i = 0; i < input.length(); i++) input[i] = tolower(input[i]); //makes the users input lowercase
		if (input == games[b]) //prints correct winning statement depending on guess number
		{
			if (i == 0) {
				cout << "\nCongratulations! You guessed it in 1 guess!" << endl;
				break;
			}
			else 
			{
				cout << "\nCongratulations! You guessed it in " << i + 1 << " guesses!" << endl;
				numberOfGuesses = i + 1;
				break;
			}
		}
		else if (i < 4) cout << "\nWrong, try again" << endl; //prints correct incorrect statement depending on guess number
		else cout << "\nWrong! The answer was " << games[b] << "!" << endl;
		if (hintNum[randNum] == 0) hintNum[randNum] = randNum + 1;
		check = true;
		numberOfGuesses = i + 1;
	}
	return numberOfGuesses;
}

int main() {
	srand(time(NULL));
	int hintReturn = 0;
	char repChar = 'y';
	double averageNumberOfGuesses = 0, numberOfGames = 0, totalNumberOfGuesses = 0;
	string gamesFile = "Games.txt", guessesFile, temp, input, username;
	vector<string> games;
	ifstream inFile;
	ofstream outFile;
	hintRead();
	inFile.open(gamesFile);
	if (!inFile) cout << "Problem reading games from file";
	else while (getline(inFile, temp)) games.push_back(temp);
	inFile.close();
	cout << "What is your name? ";
	getline(cin, username);
	guessesFile = username + ".txt";
	inFile.open(guessesFile);
	inFile >> numberOfGames >> totalNumberOfGuesses;
	cout << "You have 5 chances to guess a sport from a list of " << games.size() << " different sports, " <<
		"you will get a starting hint and a hint each time you get a guess wrong.Good luck!\n" << endl;
	do {
		int gameSelection = rand() % games.size();
		//int gameSelection = 29; //*this line is for hint/game testing use only*
		switch (gameSelection) { //uses the random number "game selection" too choose what sport/game the current game will be using
		case 0:
			hintReturn = { hints(baseballHints, 0) }; //gets the return value and sets hintReturn equal too it
			totalNumberOfGuesses += hintReturn; //adds hintReturns value to totalNumberOfGuesses
			break;
		case 1:
			hintReturn = { hints(basketballHints, 1) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 2:
			hintReturn = { hints(tennisHints, 2) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 3:
			hintReturn = { hints(pickleballHints, 3) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 4:
			hintReturn = { hints(footballHints, 4) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 5:
			hintReturn = { hints(soccerHints, 5) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 6:
			hintReturn = { hints(hockeyHints, 6) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 7:
			hintReturn = { hints(golfHints, 7)};
			totalNumberOfGuesses += hintReturn;
			break;
		case 8:
			hintReturn = { hints(volleyballHints, 8) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 9:
			hintReturn = { hints(badmintonHints, 9) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 10:
			hintReturn = { hints(rugbyHints, 10) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 11:
			hintReturn = { hints(boxingHints, 11) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 12:
			hintReturn = { hints(cricketHints, 12) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 13:
			hintReturn = { hints(poolHints, 13) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 14:
			hintReturn = { hints(dartsHints, 14) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 15:
			hintReturn = { hints(skiingHints, 15) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 16:
			hintReturn = { hints(cornholeHints, 16) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 17:
			hintReturn = { hints(horseshoesHints, 17) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 18:
			hintReturn = { hints(archeryHints, 18) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 19:
			hintReturn = { hints(bowlingHints,19) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 20:
			hintReturn = { hints(f1Hints, 20) };
			totalNumberOfGuesses += hintReturn;;
			break;
		case 21:
			hintReturn = { hints(droneRacingHints, 21) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 22:
			hintReturn = { hints(motogpHints, 22) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 23:
			hintReturn = { hints(discGolfHints, 23) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 24:
			hintReturn = { hints(surfingHints, 24) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 25:
			hintReturn = { hints(bikingHints, 25) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 26:
			hintReturn = { hints(eSportsHints, 26) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 27:
			hintReturn = { hints(airRacingHints, 27) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 28:
			hintReturn = { hints(martialArtsHints, 28) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 29:
			hintReturn = { hints(wakeBoardingHints, 29) };
			totalNumberOfGuesses += hintReturn;
			break;
		}
		numberOfGames++; //increments number of games after every game played
		averageNumberOfGuesses = totalNumberOfGuesses / numberOfGames; //calculates current average number of guesses
		do {
			cout << "Do you want to play again? (Y|N): ";
			getline(cin, input);
			repChar = tolower(input[0]);
		} while (repChar != 'y' && repChar != 'n');
	} while (repChar == 'y');
	cout << "Your overall average guesses per game is " << averageNumberOfGuesses << "!" << endl;
	outFile.open(guessesFile);
	outFile << numberOfGames << " " << totalNumberOfGuesses; //saves numberOfGames and totalNumberOfGuesses to the player file
	outFile.close();
}