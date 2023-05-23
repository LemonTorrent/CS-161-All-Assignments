#include <iostream>
#include <string.h>

using namespace std;

int main() {
	char cstr[60];
	cin.getline(cstr, 70);

	if (cin.fail()) {
		cin.ignore(60, '\n');
		cin.clear();
	}
	cout << cstr << endl;

	return 0;

}
