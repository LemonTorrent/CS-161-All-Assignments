/********************************************************************
** Function: i_to_a
** Description: turns a decimal value into a character value
** Parameters: int decimal
** Pre-Conditions: the input is an integer
** Post-Conditions: returned the character which represents the
decimal value
********************************************************************/ 
#include <iostream>
using namespace std;

int i_to_a(float num) {
    char a;

	a = num;

	cout << a << endl;

	return 0;

}



int main() {

	float num = 65;

	i_to_a(num);

	return 0;
}
