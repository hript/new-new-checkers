#include<iostream>
#include<string>
#include<Windows.h>

using namespace std;

#define SIZE 8
#define CHECKER '*'
#define EMPTY '-'

class Checker {
public:
	bool isQueen = false;
	bool isEmpty = true;
	bool isWhite;
	char space = EMPTY;

	void init(bool color) {
		isWhite = color;
	}
};

void showField(Checker** field) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (field[i][j].isWhite == true) {
				if (field[i][j].isQueen == true) {
					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 12));
				}
				else {
					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 4));
				}
			}
			else {
				if (field[i][j].isQueen == true) {
					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 1));
				}
				else {
					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 0));
				}
			}
			cout << field[i][j].space << " ";
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 0));
		}
		cout << endl;
	}
}

void startingField(Checker** field) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (((i + j) % 2 == 0 && (i < 3)) || ((i + j) % 2 != 0 && (i >= 5))) {
				if (i < 3) {
					if ((i + j) % 2 == 0) {
						field[i][j].space = CHECKER;
						field[i][j].isWhite = false;
						field[i][j].isEmpty = false;
					}
				}
				if (i >= 5) {
					if ((i + j) % 2 != 0) {
						field[i][j].space = CHECKER;
						field[i][j].isWhite = true;
						field[i][j].isEmpty = false;
					}
				}
			}
		}
	}
}

bool enemiesAround(Checker** field, int row, int column) {
	if (row - 1 >= 0 && column - 1 >= 0) {	
			if (field[row - 1][column - 1].isEmpty == false && field[row][column].isEmpty == false) {
				if (field[row - 1][column - 1].isWhite != field[row][column].isWhite) {
					return true;
				}
			}
			if (row + 1 < SIZE && column + 1 < SIZE) {
				if (field[row + 1][column + 1].isEmpty == false && field[row][column].isEmpty == false) {
					if (field[row + 1][column + 1].isWhite != field[row][column].isWhite) {
						return true;
					}
				}
				if (field[row - 1][column + 1].isEmpty == false && field[row][column].isEmpty == false) {
					if (field[row - 1][column + 1].isWhite != field[row][column].isWhite) {
						return true;
					}
				}
				if (field[row + 1][column - 1].isEmpty == false && field[row][column].isEmpty == false) {
					if (field[row + 1][column - 1].isWhite != field[row][column].isWhite) {
						return true;
					}
				}
			}	
	}
	return false;
}

bool canHit(Checker** field, int row, int column) {
	if (row - 2 >= 0 && column - 2 >= 0) {
		if (field[row - 2][column - 2].isEmpty == true) {
			return true;
		}
		if (row + 2 < SIZE && column + 2 < SIZE) {
			if (field[row + 2][column + 2].isEmpty == true) {
				return true;
			}
			if (field[row + 2][column - 2].isEmpty == true) {
				return true;
			}
			if (field[row - 2][column + 2].isEmpty == true) {
				return true;
			}
		}
	}
	return false;
}

/*int shouldHit (Checker** field, int numPlayer) {
	int result = -1;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (numPlayer % 2 == field[i][j].isWhite) {
				
			}
		}
	}
}*/

int main() {
	system("color F0");
	Checker** field = new Checker * [SIZE];
	for (int i = 0; i < SIZE; i++) {
		field[i] = new Checker[SIZE];
	}
	startingField(field);

	int numPlayer = 1;
	string firstPlayer, secondPlayer;
	cout << "First player name " << endl;
	cin >> firstPlayer;
	cout << "Second player name" << endl;

	return 0;
}