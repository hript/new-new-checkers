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
				if (i < 3) {
					
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