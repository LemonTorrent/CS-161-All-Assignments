/******************************************************************************
 ** Program: patterns_a3.cpp
 ** Author: Nicole Yarbrough
 ** Date: 02/16/2020
 ** Description: This program outputs a pattern of either asterisks or
 ** integers depending on the user's preference.
 ** Input: numerator, denominator
 ** Output: simplified numerator and denominator
 *****************************************************************************/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int print_design(int rows, int remainder, int characters, int spaces, int pattern);

int print_star(int rows);

int take_input(int &pattern, int &rows);

bool check_int(string term);

int print_row(int spaces, int characters);

int print_ints(int spaces, int characters);

bool run_again();

int design_const(int rows, int pattern);

int get_int(string prompt);

/*******************************************************************
** Function: main()
** Description: The main function of the program.
** Parameters: none
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
int main() {
    bool run = true;
    int pattern, rows;

    while (run == true){
        take_input(pattern, rows);
        design_const(rows, pattern);
        run = run_again();
    }
    return 0;
}


/*******************************************************************
** Function: take_input()
** Description: Takes input for the the pattern type and rows.
** Parameters: none
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
int take_input(int &pattern, int &rows) {
    string input;

    do{
        cout << "Would you like a number pattern (1) or an asterisk pattern (2)? ";
        cin >> input;
    } while (check_int(input) == false && (input != "1" || input != "2"));
    pattern = get_int(input);

    do{
        cout << "How many rows would you like to print? ";
        cin >> input;
    } while(check_int(input) == false);
    rows = get_int(input);

    return 0;
}

/*******************************************************************
** Function: check_int()
** Description: Checks if the input is an integer.
** Parameters: term
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
bool check_int(string term){
    for (int i = 0; i < term.length(); i++) {
        if (term[i] = '-' && (term[i] < '0' || term[i] > '9'))
            return false;
    }

    return true;
}

/*******************************************************************
** Function: get_int()
** Description: Exports string input as integer.
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
** Function: design_const()
** Description: Establishes constants for print_design().
** Parameters: rows, pattern
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
int design_const(int rows, int pattern) {
        int remainder = rows / 2;
        int spaces, characters = 1;
        print_design(rows, remainder, characters, spaces, pattern);

}

/*******************************************************************
** Function: print_design()
** Description: Prints the design.
** Parameters: rows, remainder, characters, spaces, pattern
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
int print_design(int rows, int remainder, int characters, int spaces, int pattern){
        for (int i = 0; i < (rows - remainder); i++) {
            spaces = rows - characters;
            if (pattern == 2)
                print_row(spaces, characters);
            else
                print_ints(spaces, characters);
            characters += 2;
        }
        characters -= 2;
        for (int i = remainder -1; i >= 0; i--) {
            characters -= 2;
            spaces = rows - characters;
            if (pattern == 2)
                print_row(spaces, characters);
            else
                print_ints(spaces, characters);
        }
    return 0;
}

/*******************************************************************
** Function: print_row()
** Description: Prints row of asterisks to screen.
** Parameters: spaces, character
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
int print_row(int spaces, int characters) {
    for (int i = 0; i < (spaces / 2); i++){
        cout << " ";
    }
    for (int i = 0; i < characters; i++){
        cout << "*";
    }
    for (int i = 0; i < (spaces / 2); i++) {
        cout << " ";
    }

    cout << endl;

    return 0;
}

/*******************************************************************
** Function: print_ints()
** Description: Prints row of integers to the screen.
** Parameters: spaces, characters
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
int print_ints(int spaces, int characters){
    for (int i = 0; i < spaces / 2; i++){
        cout << " ";
    }
    for (int n = 1; n <= characters; n++){
        cout << n;
    }
    for (int i = 0; i < spaces / 2; i++){
        cout << " ";
    }

    cout << endl;

    return 0;
}

/*******************************************************************
** Function: run_ again()
** Description: Checks whether the user wants to print another
** pattern
** Parameters: none
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
bool run_again() {
    string input;
    do {
        cout << "Would you like to run the program again? (0 for no and 1 for yes) ";
        cin >> input;
    } while (input !=  "0" && input != "1");

    if (input == "0")
        return 0;
    else
        return 1;
}