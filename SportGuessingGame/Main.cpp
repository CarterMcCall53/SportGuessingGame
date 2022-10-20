/* SportGuessingGame
*  Carter McCall
*  19 October 2022
*  Purpose:
*		Make a game where the user guesses a random sport
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <ctime>
using namespace std;

string baseballHints[5] = { "It starts with B", "It involves balls", "It is played on a 'diamond'", "It involves hitting balls", "One of the positions is 'Pitcher'" },
basketballHints[5] = { "It starts with B", "It involves balls", "It is played on a 'court'", "It involves baskets", "One of the positions is 'Center'" },
tennisHints[5] = { "It starts with T", "It involves balls", "It is played on a 'court'", "It involves rackets", "A famous player is Serena Williams" },
pickleballHints[5] = { "It starts with P", "It involves balls", "It is played on a 'court'", "It involves rackets", "It is similar to table tennis, but bigger" },
footballHints[5] = { "It starts with F", "It is played on a 'field'", "The ball they use is nicknamed pigskin", "The field is 100 yards long", "One of the positions is called QuarterBack" },
soccerHints[5] = { "In europe is it called football", "It involves kicking", "It involves throwing", "One of the positions is goalie", "It starts with S" },
hockeyHints[5] = { "It uses pucks", "There are many fights", "It is played on an ice rink", "One of the positions is Goalie", "It starts with H" },
golfHints[5] = { "It often takes 2-4 hours", "It starts with G", "It uses clubs", "It is played on a course", "A famous player is Tiger Woods" },
volleyballHints[5] = { "It is more commonly played by Women", "It involves balls", "It uses a net", "It can be played on sand or hard ground", "It starts with V" },
badmintonHints[5] = { "It starts with B", "It involves a racket", "It uses a net", "It is played on a court", "It uses a birdie" },
rugbyHints[5] = { "It starts with R", "It is played on a field", "It is full contact", "It uses a ball", "It is very dangerous" },
boxingHints[5] = { "It starts with B", "It involves a ring", "It involves punching", "It uses gloves", "It is very dangerous" },
cricketHints[5] = { "It starts with C", "It is similar to Baseball", "It is played on a field", "It involves bats", "The name is also a common insect" },
poolHints[5] = { "It is played on a table", "It starts with P", "It uses ques", "It uses balls", "It is generally a 2 player game" },
dartsHints[5] = { "It starts with D", "It involves throwing sharp objects", "It uses a board", "It is generally a 2-8 player game", "It is generally a party game" },
skiingHints[5] = { "It starts with S", "It involves snow", "It is dangerous", "It uses moutains", "It has many variations" };

void hints(string arr[], int a) {
	srand(time(NULL));
	bool check = false, check2 = false, check3 = false;
	int hintNum[] = { 0, 0, 0, 0, 0 }, randNum;
	string input, temp, gamesFile = "Games.txt";
	ifstream inFile;
	vector<string> games;
	inFile.open(gamesFile);
	if (!inFile) cout << "Problem reading games from file";
	else
	{
		while (inFile >> temp) {
			games.push_back(temp);
		}
	}
	inFile.close();
	for (int i = 0; i < 5; i++)
	{
		randNum = rand() % 5;
		while (check3 == true) {
			for (int j = 0; check2 = true;) {
				for (int i = 0; i < 5; i++)
				{
					if (hintNum[i] != NULL) {
						if (randNum == i) {
							randNum = rand() % 5;
							check = true;
							check2 = true;
							check3 = true;
							break;
						}
						else if (randNum != i) {
							check = false;
							check2 = false;
							check3 = false;
						}
					}
				}
				break;
			}
		}
		if (check == false) {
			cout << arr[randNum] << endl;
			cin >> input;
			if (input == games[a])
			{
				cout << "Correct! Congratulations!" << endl;
				break;
			}
			else if (i < 4)
			{
				cout << "Wrong, try again" << endl;
			}
			else
			{
				cout << "Wrong! The answer was " << games[a] << "!" << endl;
			}
		}
		if (hintNum[randNum] == 0)
		{
			hintNum[randNum] = randNum + 1;
		}
		check3 = true;
	}
}

int main() {
	char repChar;
	string gamesFile = "Games.txt", temp, input;
	vector<string> games;
	ifstream inFile;
	inFile.open(gamesFile);
	if (!inFile) cout << "Problem reading games from file";
	else
	{
		while (inFile >> temp) {
			games.push_back(temp);
		}
	}
	inFile.close();
	do {
		srand(time(NULL));
		int gameSelection = rand() % games.size();
		cout << "You have 5 guesses to guess a sport from a list of 16 different sports, you will get a starting hint and a hint each time you get a guess wrong. Good luck!\n" << endl;
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
		}
		do {
			cout << "Do you want to play again? (Y|N): ";
			cin >> input;
			repChar = tolower(input[0]);
		} while (repChar != 'y' && repChar != 'n');
	} while (repChar == 'y');
}