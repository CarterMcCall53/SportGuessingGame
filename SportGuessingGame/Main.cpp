/* SportGuessingGame
*  Carter McCall
*  19 October 2022
*  Purpose:
*		Make a game where the user guesses a random sport
*  Modified 27 October 2022:
*		Fixed an issue where vectors coudn't read in due to an incorrectly typed operator
*		Made the input not caps sensitive and added drone racing as a game
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <ctime>
using namespace std;

vector<string> baseballHints, basketballHints, tennisHints, pickleballHints, footballHints, soccerHints, hockeyHints,
golfHints, volleyballHints, badmintonHints, rugbyHints, boxingHints, cricketHints, poolHints, dartsHints, skiingHints,
cornholeHints, horseshoesHints, archeryHints, bowlingHints;

void hintRead(int a) {
	int i = 0;
	string temp;
	ifstream inFile;
	string hintsFile = "Hints.txt";
	inFile.open(hintsFile);
	if (!inFile) cout << "Problem reading hints from file"; //checks to see if it can read in a file named Hints.txt
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
			i++;
		}
		inFile.close();
	}
	
}

void hints(vector<string> a, int b) { //more or less the actual code for the game, checking if hints have already been used, using new hints, etc.
	srand(time(NULL));
	bool check = false, check2 = false;
	int hintNum[] = { 0, 0, 0, 0, 0 }, randNum, inputLength;
	string input, temp, answer, gamesFile = "Games.txt";
	ifstream inFile;
	vector<string> games;
	inFile.open(gamesFile);
	if (!inFile) cout << "Problem reading games from file";
	else
	{
		while (inFile >> temp) games.push_back(temp);
	}
	inFile.close();
	for (int i = 0; i < 5; i++)
	{
		randNum = rand() % 5;
		while (check == true) {
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
		cout << a[randNum] << endl;
		cin >> input;
		for (int i = 0; i < input.length(); i++) input[i] = tolower(input[i]);
		if (input == games[b])
		{
			cout << "Correct! Congratulations!" << endl;
			break;
		}
		else if (i < 4) cout << "Wrong, try again" << endl;
		else cout << "Wrong! The answer was " << games[b] << "!" << endl;
		if (hintNum[randNum] == 0) hintNum[randNum] = randNum + 1;
		check = true;
	}
}

int main() {
	srand(time(NULL));
	char repChar = 'y';
	string gamesFile = "Games.txt", temp, input;
	vector<string> games;
	ifstream inFile;
	hintRead(1);
	inFile.open(gamesFile);
	if (!inFile) cout << "Problem reading games from file";
	else
	{
		while (inFile >> temp) games.push_back(temp);
	}
	inFile.close();
	cout << "You have 5 chances to guess a sport from a list of 18 different sports, you will get a starting hint and a hint each time you get a guess wrong. Good luck!\n" << endl;
	do {
		int gameSelection = rand() % games.size();
		switch (gameSelection) {
		case 0:
			hints(baseballHints, 0);
			break;
		case 1:
			hints(basketballHints, 1);
			break;
		case 2:
			hints(tennisHints, 2);
			break;
		case 3:
			hints(pickleballHints, 3);
			break;
		case 4:
			hints(footballHints, 4);
			break;
		case 5:
			hints(soccerHints, 5);
			break;
		case 6:
			hints(hockeyHints, 6);
			break;
		case 7:
			hints(golfHints, 7);
			break;
		case 8:
			hints(volleyballHints, 8);
			break;
		case 9:
			hints(badmintonHints, 9);
			break;
		case 10:
			hints(rugbyHints, 10);
			break;
		case 11:
			hints(boxingHints, 11);
			break;
		case 12:
			hints(cricketHints, 12);
			break;
		case 13:
			hints(poolHints, 13);
			break;
		case 14:
			hints(dartsHints, 14);
			break;
		case 15:
			hints(skiingHints, 15);
			break;
		case 16:
			hints(cornholeHints, 16);
			break;
		case 17:
			hints(horseshoesHints, 17);
			break;
		case 18:
			hints(archeryHints, 18);
			break;
		case 19:
			hints(bowlingHints, 19);
			break;
		}
		do {
			cout << "Do you want to play again? (Y|N): ";
			cin >> input;
			repChar = tolower(input[0]);
		} while (repChar != 'y' && repChar != 'n');
	} while (repChar == 'y');
}