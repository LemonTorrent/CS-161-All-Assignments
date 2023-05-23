#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main () {

	int x;
	srand(time(NULL));

	x = rand() % 6;

	cout << "x = " << x << endl;

	if (x == 0) {
		cout << "Bummer, I'm 0!" << endl;
	} else if ((x == 2) or (x == 4)) {
		cout << "I'm an even number!" << endl;
	} else {
		cout << "I'm an odd number!" << endl;
	}
	return 0;

}
