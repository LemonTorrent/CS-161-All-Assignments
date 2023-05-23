/*
THERE ARE BUGS IN THE FOLLOWING CODE.
*/
#include <iostream> //<iostraem>
#include <string>
#include <sstream>

//using namespace std; // included this

int main(){
	using namespace std;
	
	int x = 3;
	int y;
	char myAnswer;
	bool again = true;
	char task; // initialize string for user to put input into

	y = x;
	cout << "y is set to: " << y << endl;

	cout << "Please input a number: ";
	cin >>  y;
//	again = true; // again was not initialized

	while(again == true){
		if(x > y){
			cout << "X is greater than Y\n";
			cout << "Would you like to input another number?, put 1 if yes, 0 if false. " << endl; // Put string into ""
			cin >> task;
			if (task == '0') {
				again = false;
				break;
			}
			else {
				//again = true;
				cout << "Input: ";
				cin >> y;
			}
		} else if (x < y)  {
			cout << "X is less than Y" << endl;
			cout << "would you like to input another number? 1 if yes 0 if false" << endl;
			cin >> task; // added task, used task to determine value of again
			if (task == '0') {
				again = false;
				break;
			}
			else {
				//again = true;
				cout << "Input ";
				cin >> y;
			}
		} else {
			cout << "X and Y are equal" << endl;
			cout << "would you like to input another number" << endl;
			cin >> task;
			if (task == '0') {
				again = false;
				break;
			}
			else {
				//again = true;
				cout << "Input ";
				cin >> y;
			}

		}
	
	break;

		//hint: what about equal logic?
	}
	while(x = 0, x < 10, x+=1) // += rather than +
		cout << x << endl;
	
	// Yes I know this isn't proper format, but its easier to track the errors to show to TAs checking
	string num_input;
//	int num_in1;
	int num; // initialize 
	int z;
	int factorial = 1;

	cout << "What number would you like to find the factorial for? " << endl;
	cin >> num_input;
//	for (x num_input.length())
//		num_in1 += (-(num_input.length() + 1) * (10 * 

	istringstream(num_input) >> z;

	while (z, z > 0, z--) {
		factorial *= z;				//hint: is this factorial correct?
		cout << factorial << endl;
	}
	cout << "Final factorial " << factorial << endl;

	char  myanswer;

	cout << "Are you enjoying cs161? (y or n) " << endl;
	cin >> myanswer;
	if(myanswer == 'y') //added ''
		cout << "YAY" << endl;
	else
		cout << "YOU WILL SOON!" << endl;

	return 0;
}	// added }
