/* Main.cpp
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
*	Modified 8 November 2022:
*		Moved hints() and hintRead() functions to a different module 
*	Modified 9 November 2022:
*		Added inFile.close()
*	Modified 10 November 2022:
*		Added tiddlywinks
*/

#include "Hints.h"

extern vector<string> baseballHints, basketballHints, tennisHints, pickleballHints, footballHints, soccerHints, hockeyHints,
golfHints, volleyballHints, badmintonHints, rugbyHints, boxingHints, cricketHints, poolHints, dartsHints, skiingHints,
cornholeHints, horseshoesHints, archeryHints, bowlingHints, f1Hints, droneRacingHints, motogpHints, discGolfHints, surfingHints,
bikingHints, eSportsHints, airRacingHints, martialArtsHints, wakeBoardingHints, tiddlywinksHints, extra;

int main() {
	srand(time(NULL));
	int hintReturn = 0;
	char repChar = 'y';
	double averageNumberOfGuesses = 0, numberOfGames = 0, totalNumberOfGuesses = 0;
	bool clear = false;
	string gamesFile = "Games.txt", guessesFile, temp, input, username;
	vector<string> games;
	ifstream inFile;
	ofstream outFile;
	Hints::hintRead();
	inFile.open(gamesFile);
	if (!inFile) {
		cout << "Problem reading games from file (Error Function: main())";
		abort();
	}
	else while (getline(inFile, temp)) games.push_back(temp);
	inFile.close();
	cout << "What is your name? ";
	getline(cin, username);
	guessesFile = username + ".txt";
	inFile.open(guessesFile);
	inFile >> numberOfGames >> totalNumberOfGuesses;
	inFile.close();
	do {
		system("cls");
		cout << "You have 5 chances to guess a sport from a list of " << games.size() << " different sports, " <<
			"you will get a starting hint and a hint each time you get a guess wrong. Good luck!\n" << endl;
		int gameSelection = rand() % games.size();
		//int gameSelection = 30; //*this line is for hint/game testing use only*
		switch (gameSelection) { //uses the random number "game selection" too choose what sport/game the current game will be using
		case 0:
			hintReturn = { Hints::hints(baseballHints, 0) }; //gets the return value and sets hintReturn equal too it
			totalNumberOfGuesses += hintReturn; //adds hintReturns value to totalNumberOfGuesses
			break;
		case 1:
			hintReturn = { Hints::hints(basketballHints, 1) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 2:
			hintReturn = { Hints::hints(tennisHints, 2) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 3:
			hintReturn = { Hints::hints(pickleballHints, 3) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 4:
			hintReturn = { Hints::hints(footballHints, 4) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 5:
			hintReturn = { Hints::hints(soccerHints, 5) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 6:
			hintReturn = { Hints::hints(hockeyHints, 6) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 7:
			hintReturn = { Hints::hints(golfHints, 7)};
			totalNumberOfGuesses += hintReturn;
			break;
		case 8:
			hintReturn = { Hints::hints(volleyballHints, 8) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 9:
			hintReturn = { Hints::hints(badmintonHints, 9) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 10:
			hintReturn = { Hints::hints(rugbyHints, 10) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 11:
			hintReturn = { Hints::hints(boxingHints, 11) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 12:
			hintReturn = { Hints::hints(cricketHints, 12) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 13:
			hintReturn = { Hints::hints(poolHints, 13) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 14:
			hintReturn = { Hints::hints(dartsHints, 14) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 15:
			hintReturn = { Hints::hints(skiingHints, 15) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 16:
			hintReturn = { Hints::hints(cornholeHints, 16) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 17:
			hintReturn = { Hints::hints(horseshoesHints, 17) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 18:
			hintReturn = { Hints::hints(archeryHints, 18) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 19:
			hintReturn = { Hints::hints(bowlingHints,19) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 20:
			hintReturn = { Hints::hints(f1Hints, 20) };
			totalNumberOfGuesses += hintReturn;;
			break;
		case 21:
			hintReturn = { Hints::hints(droneRacingHints, 21) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 22:
			hintReturn = { Hints::hints(motogpHints, 22) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 23:
			hintReturn = { Hints::hints(discGolfHints, 23) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 24:
			hintReturn = { Hints::hints(surfingHints, 24) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 25:
			hintReturn = { Hints::hints(bikingHints, 25) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 26:
			hintReturn = { Hints::hints(eSportsHints, 26) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 27:
			hintReturn = { Hints::hints(airRacingHints, 27) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 28:
			hintReturn = { Hints::hints(martialArtsHints, 28) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 29:
			hintReturn = { Hints::hints(wakeBoardingHints, 29) };
			totalNumberOfGuesses += hintReturn;
			break;
		case 30:
			hintReturn = { Hints::hints(tiddlywinksHints, 30) };
			totalNumberOfGuesses += hintReturn;
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