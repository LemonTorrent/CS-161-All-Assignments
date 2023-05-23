/******************************************************************************
 ** Program: assignment3.cpp
 ** Author: Nicole Yarbrough
 ** Date: 02/16/2020
 ** Description: This program simplifies fractions.
 ** Input: numerator, denominator
 ** Output: simplified numerator and denominator
 *****************************************************************************/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int take_input(int &numerator, int &denominator);

bool check_int(string term);

int get_int(string prompt);

bool to_lowest_terms(int &numerator, int &denominator);

int g_c_d(int num1, int num2);


/*******************************************************************
** Function: main()
** Description: The main function of the program.
** Parameters: none
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 

int main() {
    int numerator, denominator;

    take_input(numerator, denominator);
    to_lowest_terms(numerator, denominator);

    cout << numerator << " / " << denominator << endl;

    return 0;
}

/*******************************************************************
** Function: take_input()
** Description: Takes user input for numerator and denominator.
** Parameters: numerator, denominator
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
int take_input(int &numerator, int &denominator) {
    string input;

    do{
        cout << "Enter an integer for your numerator: ";
        cin >> input;
    } while (check_int(input) == false);
    numerator = get_int(input);

    do{
        cout << "Enter a nonzero integer for your denominator: ";
        cin >> input;
    } while(check_int(input) == false || input == "0");
    denominator = get_int(input);

    return 0;
}

/*******************************************************************
** Function: check_int()
** Description: Checks to see if the input is an integer.
** Parameters: term
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/
bool check_int(string term){
    if (term[0] != '-' and (term[0] < '0' or term[0] > '9'))
        return false;

    if (term.length() > 1) {
        for (int i = 1; i < term.length(); i++) {
            if (term[i] < '0' || term[i] > '9')
                return false;
        }
    }
    return true;
}

/*******************************************************************
** Function: get_int()
** Description: Outputs string input as integer.
** Parameters: prompt
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
int get_int(string prompt) {
  int output_int = 0;

  if (prompt[0] == '-') {
    for (int i = 1; i < prompt.length(); i++){
      output_int += ((prompt[prompt.length()-i] - 48) * pow(10, i-1));
    }

    output_int *= -1;
  } else {    
    for (int i = 0; i < prompt.length(); i++){
    output_int += ((prompt[prompt.length()-1-i] - 48) * pow(10, i));
    }
  }
	return output_int;
}

/*******************************************************************
** Function: to_lowest_terms()
** Description: Simplifies the fraction to lowest terms.
** Parameters: numerator, denominator
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
bool to_lowest_terms(int &numerator, int &denominator) {
    int gcd = g_c_d(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;

    if (denominator < 0) {
        denominator *= -1;
        numerator *= -1;
    }

    return true;
}

/*******************************************************************
** Function: g_c_d()
** Description: Finds the greatest common denominator.
** Parameters: num1, num2
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
int g_c_d(int num1, int num2){
    if (num2 == 0)
        return num1;
    else
        return g_c_d(num2, num1 % num2);
}