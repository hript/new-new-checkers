#include <iostream>
#include <string>
#include <Windows.h>
#include <cmath>

#define SIZE 9
#define CHECKER '*'
#define EMPTY '-'

using namespace std;

class Checker {
public:
	bool isQueen = false;
	bool isEmpty = true;
	bool isWhite = false;
	char space = EMPTY;

};

void showField(Checker** field) {
	system("cls");
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
		field[0][i].space = i + '0';
		field[0][i].isEmpty = false;
		field[i][0].space = i + '0';
		field[i][0].isEmpty = false;
		for (int j = 1; j < SIZE; j++) {
			if (((i + j) % 2 == 0 && (i <= 3) && (i > 0)) || ((i + j) % 2 != 0 && (i >= 6))) {
				if (i <= 3) {
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

bool enemiesAroundChecker(Checker** field, int row, int column) {
	if (field[row][column].isEmpty == false) {
		if (row - 1 >= 1 && column - 1 >= 1) {
			if (field[row - 1][column - 1].isEmpty == false && field[row][column].isEmpty == false) {
				if (field[row - 1][column - 1].isWhite != field[row][column].isWhite) {
					return true;
				}
			}
		}
		if (row + 1 < SIZE && column + 1 < SIZE) {
			if (field[row + 1][column + 1].isEmpty == false && field[row][column].isEmpty == false) {
				if (field[row + 1][column + 1].isWhite != field[row][column].isWhite) {
					return true;
				}
			}
		}
		if (row - 1 >= 1 && column + 1 < SIZE) {
			if (field[row - 1][column + 1].isEmpty == false && field[row][column].isEmpty == false) {
				if (field[row - 1][column + 1].isWhite != field[row][column].isWhite) {
					return true;
				}
			}
		}
		if (row + 1 < SIZE && column - 1 >= 1) {
			if (field[row + 1][column - 1].isEmpty == false && field[row][column].isEmpty == false) {
				if (field[row + 1][column - 1].isWhite != field[row][column].isWhite) {
					return true;
				}
			}
		}
	}
	return false;
}

bool canHitChecker(Checker** field, int row, int column) {
	if (field[row][column].isEmpty == false) {
		if (row - 2 >= 1 && column - 2 >= 1) {
			if (field[row - 2][column - 2].isEmpty == true) {
				return true;
			}
		}
		if (row + 2 < SIZE && column + 2 < SIZE) {
			if (field[row + 2][column + 2].isEmpty == true) {
				return true;
			}
		}
		if (row + 2 < SIZE && column - 2 >= 1) {
			if (field[row + 2][column - 2].isEmpty == true) {
				return true;
			}
		}
		if (row - 2 >= 1 && column + 2 < SIZE) {
			if (field[row - 2][column + 2].isEmpty == true) {
				return true;
			}
		}
	}
	return false;
}

bool enemiesAroundQueen(Checker** field, int row, int column) {
	for (int i = 1; i < SIZE; i++) {
		for (int j = 1; j < SIZE; j++) {
			if (((i + j == row + column) || (i - j == row - column)) && i != row && j != column) {
				if (field[i][j].isEmpty == false && field[i][j].isWhite != field[i][j].isWhite) {
					return true;
				}
			}
		}
	}
	return false;
}

bool queenCanHit(Checker** field, int row, int column) {
	for (int i = 1; i < SIZE; i++) {
		for (int j = 1; j < SIZE; j++) {
			if (((i + j == row + column) || (i - j == row - column)) && i != row && j != column) {
				if (field[i][j].isEmpty == false && field[i][j].isWhite != field[i][j].isWhite) {
					if (i < row && j < column) {
						if (i - 1 >= 1 && j - 1 >= 1 && field[i - 1][j - 1].isEmpty == true) {
							return true;
						}
					}
					if (i < row && j > column) {
						if (i - 1 >= 1 && j + 1 < SIZE && field[i - 1][j + 1].isEmpty == true) {
							return true;
						}
					}
					if (i > row && j > column) {
						if (i + 1 < SIZE && j + 1 < SIZE && field[i + 1][j + 1].isEmpty == true) {
							return true;
						}
					}
					if (i > row && j < column) {
						if (i + 1 < SIZE && j - 1 >= 1 && field[i + 1][j - 1].isEmpty == true) {
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

bool shouldHit (Checker** field, int numPlayer) {
	for (int i = 1; i < SIZE; i++) {
		for (int j = 1; j < SIZE; j++) {
			if (numPlayer % 2 == field[i][j].isWhite && field[i][j].isEmpty == false) {
				if (field[i][j].isQueen == false) {
					if (enemiesAroundChecker(field, i, j) && canHitChecker(field, i, j)) {
						return true;
					}
				}
				else {
					if (enemiesAroundQueen(field, i, j) && queenCanHit(field, i, j)) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool canRun(Checker** field, int numPlayer, int row, int column) {
	if (numPlayer % 2 == field[row][column].isWhite) {
		if (row - 1 >= 1 && column - 1 >= 1) {
			if (field[row - 1][column - 1].isEmpty == true) {
				return true;
			}
		}
		if (row + 1 < SIZE && column + 1 < SIZE) {
			if (field[row + 1][column + 1].isEmpty == true) {
				return true;
			}
		}
		if (row + 1 < SIZE && column - 1 >= 1) {
			if (field[row + 1][column - 1].isEmpty == true) {
				return true;
			}
		}
		if (row - 1 >= 1 && column + 1 < SIZE) {
			if (field[row - 1][column + 1].isEmpty == true) {
				return true;
			}
		}
	}
	return false;
}

bool checkEnemyBlockChecker(Checker** field, int nowRow, int nowColumn, int nextRow, int nextColumn) {
	if (nowRow < nextRow && nowColumn < nextColumn) {
		if (field[nowRow + 1][nextColumn + 1].isEmpty == false) {
			if (field[nowRow + 1][nowColumn + 1].isWhite != field[nowRow][nowColumn].isWhite) {
				return true;
			}
		}
	}
	if (nowRow < nextRow && nowColumn > nextColumn) {
		if (field[nowRow + 1][nextColumn - 1].isEmpty == false) {
			if (field[nowRow + 1][nowColumn - 1].isWhite != field[nowRow][nowColumn].isWhite) {
				return true;
			}
		}
	}
	if (nowRow > nextRow && nowColumn < nextColumn) {
		if (field[nowRow - 1][nextColumn + 1].isEmpty == false) {
			if (field[nowRow - 1][nowColumn + 1].isWhite != field[nowRow][nowColumn].isWhite) {
				return true;
			}
		}
	}
	if (nowRow > nextRow && nowColumn > nextColumn) {
		if (field[nowRow - 1][nextColumn - 1].isEmpty == false) {
			if (field[nowRow - 1][nowColumn - 1].isWhite != field[nowRow][nowColumn].isWhite) {
				return true;
			}
		}
	}
	return false;
}

bool correctlyChosenNextBlockChecker(Checker** field, int nowRow, int nowColumn, int nextRow, int nextColumn) {
	if (field[nowRow][nowColumn].isQueen == false) {
		if (nowRow == nextRow && nowColumn == nextColumn) {
			return false;
		}
		if (nextColumn >= SIZE || nextColumn <= 0 || nextRow >= SIZE || nextRow <= 0) {
			return false;
		}
		if (field[nextRow][nextColumn].isEmpty == false) {
			return false;
		}
		if ((nowRow + nowColumn != nextRow + nextColumn) || (nowRow - nowColumn != nextRow - nextColumn)) {
			return false;
		}
		if (abs(nowRow - nextRow) > 2 && abs(nowColumn - nextColumn) > 2) {
			return false;
		}
		if (abs(nowRow - nextRow) == 2 && abs(nowColumn - nextColumn) == 2) {
			if (checkEnemyBlockChecker(field, nowRow, nowColumn, nextRow, nextColumn) == false) {
				return false;
			}
		}
		return true;
	}
	return false;
}

bool checkAbilityRunQueen(Checker** field, int nowRow, int nowColumn, int nextRow, int nextColumn) {
	if (nextRow > nowRow && nextColumn > nowColumn) {
		for (int i = nowRow + 1; i < nextRow; i++) {
			for (int j = nowColumn + 1; j < nextColumn; j++) {
				if (i - j == nowRow - nowColumn && field[i][j].isEmpty == false) {
					if (field[i][j].isWhite == field[nowRow][nowColumn].isWhite) {
						return false;
					}
				}
			}
		}
	}
	if (nextRow > nowRow && nextColumn < nowColumn) {
		for (int i = nowRow + 1; i < nextRow; i++) {
			for (int j = nextColumn; j < nowColumn; j++) {
				if (i + j == nowRow + nowColumn && field[i][j].isEmpty == false) {
					if (field[i][j].isWhite == field[nowRow][nowColumn].isWhite) {
						return false;
					}
				}
			}
		}
	}
	if (nextRow < nowRow && nextColumn < nowColumn) {
		for (int i = nextRow + 1; i < nowRow; i++) {
			for (int j = nextColumn + 1; j < nowColumn; j++) {
				if (i - j == nowRow - nowColumn && field[i][j].isEmpty == false) {
					if (field[i][j].isWhite == field[nowRow][nowColumn].isWhite) {
						return false;
					}
				}
			}
		}
	}
	if (nextRow < nowRow && nextColumn > nowColumn) {
		for (int i = nextRow + 1; i < nowRow; i++) {
			for (int j = nowColumn + 1; j < nextColumn; j++) {
				if ( i + j == nowRow + nowColumn && field[i][j].isEmpty == false) {
					if (field[i][j].isWhite == field[nowRow][nowColumn].isWhite) {
						return false;
					}
				}
			}
		}
	}
	return true;
}

bool correctlyChosenNextBlockQueen(Checker** field, int nowRow, int nowColumn, int nextRow, int nextColumn) {
	if (field[nowRow][nowColumn].isQueen == true) {
		if (nowRow == nextRow && nowColumn == nextColumn) {
			return false;
		}
		if (nextColumn >= SIZE || nextColumn <= 0 || nextRow >= SIZE || nextRow <= 0) {
			return false;
		}
		if (field[nextRow][nextColumn].isEmpty == false) {
			return false;
		}
		if ((nowRow + nowColumn != nextRow + nextColumn) || (nowRow - nowColumn != nextRow - nextColumn)) {
			return false;
		}
		if (!checkAbilityRunQueen(field, nowRow, nowColumn, nextRow, nextColumn)) {
			return false;
		}
		return true;
	}
	return false;
}

void killEnemiesOnWayChecker(Checker** field, int nowRow, int nowColumn, int nextRow, int nextColumn) {
	if (abs(nowRow - nextRow) == 2 && abs(nowColumn - nextColumn) == 2) {
		if (nextRow < nowRow && nextColumn < nowColumn) {
			field[nowRow - 1][nowColumn - 1].isEmpty = true;
		}
		if (nextRow < nowRow && nextColumn > nowColumn) {
			field[nowRow - 1][nowColumn + 1].isEmpty = true;
		}
		if (nextRow > nowRow && nextColumn > nowColumn) {
			field[nowRow + 1][nextColumn + 1].isEmpty = true;
		}
		if (nextRow > nowRow && nextColumn < nowColumn) {
			field[nowRow + 1][nowColumn - 1].isEmpty = true;
		}
	}
}

void killEnemiesOnWayQueen(Checker** field, int nowRow, int nowColumn, int nextRow, int nextColumn) {
	if (nextRow > nowRow && nextColumn > nowColumn) {
		for (int i = nowRow + 1; i < nextRow; i++) {
			for (int j = nowColumn + 1; j < nextColumn; j++) {
				if (i - j == nowRow - nowColumn && field[i][j].isEmpty == false) {
					if (field[i][j].isWhite != field[nowRow][nowColumn].isWhite) {
						field[i][j].isEmpty = true;
					}
				}
			}
		}
	}
	if (nextRow > nowRow && nextColumn < nowColumn) {
		for (int i = nowRow + 1; i < nextRow; i++) {
			for (int j = nextColumn; j < nowColumn; j++) {
				if (i + j == nowRow + nowColumn && field[i][j].isEmpty == false) {
					if (field[i][j].isWhite != field[nowRow][nowColumn].isWhite) {
						field[i][j].isEmpty = true;
					}
				}
			}
		}
	}
	if (nextRow < nowRow && nextColumn < nowColumn) {
		for (int i = nextRow + 1; i < nowRow; i++) {
			for (int j = nextColumn + 1; j < nowColumn; j++) {
				if (i - j == nowRow - nowColumn && field[i][j].isEmpty == false) {
					if (field[i][j].isWhite != field[nowRow][nowColumn].isWhite) {
						field[i][j].isEmpty = true;
					}
				}
			}
		}
	}
	if (nextRow < nowRow && nextColumn > nowColumn) {
		for (int i = nextRow + 1; i < nowRow; i++) {
			for (int j = nowColumn + 1; j < nextColumn; j++) {
				if (i + j == nowRow + nowColumn && field[i][j].isEmpty == false) {
					if (field[i][j].isWhite != field[nowRow][nowColumn].isWhite) {
						field[i][j].isEmpty = true;
					}
				}
			}
		}
	}
}

bool yourChecker(Checker** field, int numPlayer, int row, int column) {
	if (numPlayer % 2 == field[row][column].isWhite) {
		return true;
	}
	return false;
}

void moveChecker(Checker** field, int nowRow, int nowColumn, int nextRow, int nextColumn) {
	field[nextRow][nextColumn] = field[nowRow][nowColumn];
	field[nowRow][nowColumn].isEmpty = false;
}

void queen(Checker** field, int nextRow, int nextColumn) {
	if (field[nextRow][nextColumn].isWhite == true) {
		if (nextRow == 1) {
			field[nextRow][nextColumn].isQueen = true;
		}
	}
	else {
		if (nextRow == SIZE - 1) {
			field[nextRow][nextColumn].isQueen = true;
		}
	}
}

bool necessarilyKillEnemyQueen(Checker** field, int nowRow, int nowColumn, int nextRow, int nextColumn) {
	if (nextRow > nowRow && nextColumn > nowColumn) {
		for (int i = nowRow + 1; i < nextRow; i++) {
			for (int j = nowColumn + 1; j < nextColumn; j++) {
				if (i - j == nowRow - nowColumn && field[i][j].isEmpty == false) {
					if (field[i][j].isWhite != field[nowRow][nowColumn].isWhite) {
						return true;
					}
				}
			}
		}
	}
	if (nextRow > nowRow && nextColumn < nowColumn) {
		for (int i = nowRow + 1; i < nextRow; i++) {
			for (int j = nextColumn; j < nowColumn; j++) {
				if (i + j == nowRow + nowColumn && field[i][j].isEmpty == false) {
					if (field[i][j].isWhite != field[nowRow][nowColumn].isWhite) {
						return true;
					}
				}
			}
		}
	}
	if (nextRow < nowRow && nextColumn < nowColumn) {
		for (int i = nextRow + 1; i < nowRow; i++) {
			for (int j = nextColumn + 1; j < nowColumn; j++) {
				if (i - j == nowRow - nowColumn && field[i][j].isEmpty == false) {
					if (field[i][j].isWhite != field[nowRow][nowColumn].isWhite) {
						return true;
					}
				}
			}
		}
	}
	if (nextRow < nowRow && nextColumn > nowColumn) {
		for (int i = nextRow + 1; i < nowRow; i++) {
			for (int j = nowColumn + 1; j < nextColumn; j++) {
				if (i + j == nowRow + nowColumn && field[i][j].isEmpty == false) {
					if (field[i][j].isWhite != field[nowRow][nowColumn].isWhite) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool out(Checker** field) {
	bool flagWhite = false, flagBlack = false;
	for (int i = 1; i < SIZE; i++) {
		for (int j = 1; j < SIZE; j++) {
			if (field[i][j].isEmpty == false) {
				if (field[i][j].isWhite == true) {
					flagWhite = true;
				}
				else {
					flagBlack = true;
				}
			}
		}
	}
	if (flagWhite == false || flagBlack == false) {
		return true;
	}
	return false;
}

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
	cin >> secondPlayer;

	int nowRow, nowColumn;
	int nextRow, nextColumn;

	while (!out(field)) {
		showField(field);
		if (shouldHit(field, numPlayer)) {
			cout << "One checker should hit enemy. Choose right checker" << endl;
			cin >> nowRow >> nowColumn;

			while (!enemiesAroundQueen(field, nowRow, nowColumn) || !queenCanHit(field, nowRow, nowColumn) || !yourChecker(field, numPlayer, nowRow, nowColumn)) {
				if (yourChecker(field, numPlayer, nowRow, nowColumn)) {
					cout << "This checker can't run now. Try another one" << endl;
				}
				else {
					cout << "That's not your checker. Try again!" << endl;
				}
				cin >> nowRow >> nowColumn;
			}

			cout << "Choose next position" << endl;
			cin >> nextRow >> nextColumn;
			
			if (field[nowRow][nowColumn].isQueen) {
				while (!necessarilyKillEnemyQueen(field, nowRow, nowColumn, nextRow, nextColumn)) {
					cout << "Choose another position" << endl;
					cin >> nextRow >> nextColumn;
				}
				killEnemiesOnWayChecker(field, nowRow, nowColumn, nextRow, nextColumn);
			}
			else {
				while (!checkEnemyBlockChecker(field, nowRow, nowColumn, nextRow, nextColumn)) {
					cout << "Choose another next position" << endl;
					cin >> nextRow >> nextColumn;
				}
				killEnemiesOnWayChecker(field, nowRow, nowColumn, nextRow, nextColumn);
			}

		}
		else {
			cout << "Choose fighting checker" << endl;
			cin >> nowRow >> nowColumn;

			while (canRun(field, numPlayer, nowRow, nowColumn) == false) {
				cout << "You can't move this checker. Try another one" << endl;
				cin >> nowRow >> nowColumn;
			}

			cout << "Choose next position" << endl;
			cin >> nextRow >> nextColumn;

			if (field[nowRow][nowColumn].isQueen) {
				while (correctlyChosenNextBlockQueen(field, nowRow, nowColumn, nextRow, nextColumn) == false) {
					cout << "You can't move like that. Try again!" << endl;
					cin >> nextRow >> nextColumn;
				}
				killEnemiesOnWayQueen(field, nowRow, nowColumn, nextRow, nextColumn);
			}
			else {
				while (correctlyChosenNextBlockChecker(field, nowRow, nowColumn, nextRow, nextColumn) == false) {
					cout << "You can't move like that. Try again!" << endl;
					cin >> nextRow >> nextColumn;
				}
				killEnemiesOnWayChecker(field, nowRow, nowColumn, nextRow, nextColumn);
			}
		}
		moveChecker(field, nowRow, nowColumn, nextRow, nextColumn);
		queen(field, nextRow, nextColumn);
		numPlayer += 1;
	}

	if (numPlayer % 2 != 0) {
		cout << firstPlayer << " win!"<<endl;
	}
	else {
		cout << secondPlayer << " win!"<<endl;
	}
	
	return 0;
}