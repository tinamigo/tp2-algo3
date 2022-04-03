#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	srand(17);
	int row,column;
	row = atoi(argv[1]);
	column = atoi(argv[2]);
	cout << row << " " << column << endl;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < column ; ++j) {
			cout << rand()%256 << " ";
		}
		cout << endl;
	}
}