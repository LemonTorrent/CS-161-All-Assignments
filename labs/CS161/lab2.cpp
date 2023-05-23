#include <iostream>
#include <cmath>

using namespace std;

int main() {

	int bits;
	cout << "How many bits? ";
	cin >> bits;

	int max_sign, min_sign, max_unsig;

	max_sign = pow(2, (bits - 1)) - 1;
	min_sign = (-1) * pow(2, (bits - 1));

	max_unsig = pow(2, bits) - 1;

	cout << "The maximum signed number is  " << max_sign << endl;
	cout << "The minimum signed number is " << min_sign << endl;
	cout << "The maximum unsigned number is " << max_unsig << endl;
	return 0;
}
