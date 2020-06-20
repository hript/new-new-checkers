#include<iostream>
#include<Windows.h>

using namespace std;

#define SIZE 8
#define CHECKER '*'
#define EMPTY '-'

class Checker {
public:
	bool isQueen = false;
	bool isAlive = true;
	bool isEmpty = false;
	bool isWhite;
	char space = EMPTY;

	void init(bool color) {
		isWhite = color;
	}
};

void startingField(Checker** field) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (((i + j) % 2 == 0 && (i < 3)) || ((i + j) % 2 != 0 && (i >= 5))) {
				field[i][j].isEmpty = true;
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

int main() {
	Checker** field = new Checker * [SIZE];
	for (int i = 0; i < SIZE; i++) {
		field[i] = new Checker[SIZE];
	}


}