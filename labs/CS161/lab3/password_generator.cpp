#include <iostream>

include namespace std;

int check_int(str) {
	bool checked = true;
	while (i = 0, i < str.size(), i++) {
		
		if ((i < '0') or (i > '9')) { 
			return false;
		}
	
	}

	return true;
}

int main () {

	short len_pass;
	char x;


	cout << "Welcome to the password generator." << endl;

	do {
		cout << "How long would you like your password to be? ";
		cin >> len_pass;
		if (check_int(len_pass) == false)
			cout << "Please enter an integer greater than 0."
	
	while (check_int(len_pass) == false);
	
	if (len_pass == '0') {
		cout << "Length of password is 0";
		return 0
	}

	char upper_letter;
	string pass_components;

	cout << "Would you like to have upper case letters? (0-false, 1-true) " << endl;
	cin >> upper_letter;

	if (upper_letter == '1') {
		short amount_upper;
		
		do {
			cout << "How many uppercase letters?" << endl;
			cin >> amount_upper;
			if (check_int(amount_upper) == false)
				cout << "Please enter an integer greater than 0." << endl;
		} while (check_int(amount_upper) == false);
		

		if (amount_upper > '0') {
			while (i=0, i < int len_pass, i++) {
				x = (rand() % 26) + 'A';
				pass_components += x;
			}
		}

	char lower_letter;
	
	cout << "Would you like to have lower case letters? (0-false, 1-true) " << endl;
	cin >> lower_letter;
		
	if (lower_letter == '1') {
		short amount_lower;
		
		do {
			cout << "How many uppercase letters?" << endl;
			cin >> amount_lower;
			if (check_int(amount_lower)  == false)
				cout << "Please enter an integer greater than 0." << endl;
		} while (check_int(amount_lower) == false);
		
		if (pass_components.size() + int amount_lower > len_pass)
			return 0;

		if (amount_upper > '0') {
			while (i=0, i < int len_pass, i++) {
				x = (rand() % 26) + 'A';
				pass_components += x;
			}
		}
			
		

	}

}
