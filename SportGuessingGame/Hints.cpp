/* Hints.cpp
*  Carter McCall
*  8 November 2022
*  Purpose:
*		Hold the hintRead() and hints() function
*/

#include "Main.h"

vector<string> baseballHints, basketballHints, tennisHints, pickleballHints, footballHints, soccerHints, hockeyHints,
golfHints, volleyballHints, badmintonHints, rugbyHints, boxingHints, cricketHints, poolHints, dartsHints, skiingHints,
cornholeHints, horseshoesHints, archeryHints, bowlingHints, f1Hints, droneRacingHints, motogpHints, discGolfHints, surfingHints,
bikingHints, eSportsHints, airRacingHints, martialArtsHints, wakeBoardingHints, extra;

void transfer::hintRead() {
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

int transfer::hints(vector<string> a, int b) { //more or less the actual code for the game, checking if hints have already been used, using new hints, etc.
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