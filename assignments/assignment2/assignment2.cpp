/******************************************************************************
 ** Program: assignment2.cpp
 ** Author: Nicole Yarbrough
 ** Date: 02/02/2020
 ** Description: This program 
 ** Input: 
 ** Output: 
 *****************************************************************************/ 
#include <iostream>
#include <cmath>

using namespace std;

/*******************************************************************
** Function: letters_present()
** Description: This is function checks if the test value is within
** the upper and lower bounds.
** Parameters: l_bound, u_bound, test_val
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 


bool check_range(int l_bound, int u_bound, int test_val) {

	if (test_val < l_bound) {
		return false;
	} else if (test_val > u_bound) {
		return false;
	}
	return true;

}

/*******************************************************************
** Function: is_capital()
** Description: This is the function to check if a character is an
** uppercase letter.
** Parameters: sentence
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 


bool is_capital(char letter) {

	if (letter >= 'A' && letter <= 'Z')
		return true;
	return false;

}

/*******************************************************************
** Function: is_even()
** Description: This is the function where integers are checked to
** be even.
** Parameters: num
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 


bool is_even(int num) {

	float remainder;

	remainder = float(num) / 2;
	if (remainder == int (remainder))
		return true;
	return false;

}

/*******************************************************************
** Function: is_odd()
** Description: This is the function where integers are checked to
** be odd.
** Parameters: num
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 


bool is_odd(int num) {

	float remainder;

	remainder = float(num) / 2;
	if (remainder > int (remainder))
		return true;
	return false;

}

/*******************************************************************
** Function: equality_test()
** Description: This is the function where two integers are compared
** to test their equality.
** Parameters: num1, num2
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 


int equality_test(int num1, int num2) {

	if (num1 < num2)
		return -1;
	if (num1 == num2)
		return 0;
	if (num1 > num2)
		return 1;

}

/*******************************************************************
** Function: float_is_equal()
** Description: This is the function that compares floats with each
** other and a certain precision to determine whether they are equal.
** Parameters: num1, num2, precision
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 


bool float_is_equal(float num1, float num2, float precision) {

	if ((num1 >= num2 - precision) && (num1 <= num2 + precision))
		return true;
	return false;

}

/*******************************************************************
** Function: is_int()
** Description: This is the function where the string is checked to
** be an integer.
** Parameters: num
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 


bool is_int(string num) {

	for (int i = 0; i < num.length(); i++) {
		if (num[i] < '0' or num[i] > '9')
			return false;
	}
	return true;

}

/*******************************************************************
** Function: nums_present()
** Description: This is the function where numbers are found within
** a string.
** Parameters: sentence
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 


bool num_present(string sentence) {

	for (int i = 0; i < sentence.length(); i++) {
		if (sentence[i] >= '0' and sentence[i] <= '9')
			return true;
	}
	return false;

}

/*******************************************************************
** Function: letters_present()
** Description: This is the function letters are found within a
** string.
** Parameters: sentence
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 


bool letters_present(string sentence) {

	for (int i = 0; i <  sentence.length(); i++) {
		if ((sentence[i] >= 'A' and sentence[i] <= 'Z') or (sentence[i] >= 'a' 
		and sentence[i] <= 'z')) 
			return true;
	}
	return false;

}

/*******************************************************************
** Function: contains_sub_string()
** Description: This is a function that checks whether the sentence
** contains the substring.
** Parameters: sentence
** Pre-Conditions: None
** Post-Conditions: True or False
*******************************************************************/ 

bool contains_sub_string(string sentence, string substring) {
	int n = 1;
	int m;
	cout << sentence << endl;
	for (int i = 0; i < sentence.length(); i++) {
		if (sentence[i] == substring[0]) {
			m = i + 1;
			do {
				if (n == substring.length())
					return true;
				n += 1;
				m += 1;
			} while (sentence[m] == substring[n]);
		}
	}

	return false;
}

/*******************************************************************
** Function: word_count()
** Description: This is the function counts the words in a string.
** Parameters: sentence
** Pre-Conditions: None
** Post-Conditions: Amount of words in string
*******************************************************************/ 

int word_count(string sentence) {
	int space_count = 1;

	for (int i = 0; i < sentence.length(); i++) {
		if (sentence[i] == ' ')
			space_count += 1;
	}

	return space_count;
}

/*******************************************************************
** Function: to_upper()
** Description: This is the function where lowercase letters are
** changed to uppercase letters within a string.
** Parameters: sentence
** Pre-Conditions: None
** Post-Conditions: Fully uppercase string.
*******************************************************************/ 

string to_upper(string sentence) {
	string new_sentence;

	for (int i = 0; i < sentence.length(); i++) {
		if (sentence[i] >= 'a' and sentence[i] <= 'z')
			new_sentence += char (sentence[i] - 32);
		else
			new_sentence += sentence[i];
	}

	return new_sentence;

}

/*******************************************************************
** Function: to_lower()
** Description: This is the function where uppercase letters in the
** string are converted to lower case letters.
** Parameters: sentence
** Pre-Conditions: None
** Post-Conditions: An entirely lower case string.
*******************************************************************/ 

string to_lower(string sentence) {
	string new_sentence;

	for (int i = 0; i < sentence.length(); i++) {
		if (sentence[i] >= 'A' and sentence[i] <= 'Z')
			new_sentence += char (sentence[i] + 32);
		else
			new_sentence += sentence[i];
	}

	return new_sentence;

}

/*******************************************************************
** Function: get_int()
** Description: This is the function where strings of number
** characters are turned into an integer.
** Parameters: prompt
** Pre-Conditions: None
** Post-Conditions: The integer resulting from the string prompt.
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
** Function: main()
** Description: This is the function where the other functions are
** tested.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Expected and actual results of each of the
** functions as well as whether the functions passed or failed.
*******************************************************************/ 

int main() {
	bool actual_bool;
	int actual_int;
	string actual_string;
	string int_input;

	cout << "Testing check_range(1, 5, 6). Expected: 0" << endl;
	actual_bool = check_range(1, 5, 6);
	cout <<"Actual: " <<  actual_bool << endl;
	if (actual_bool == true)
		cout << "FAILED" << endl;
	else
		cout << "PASSED" << endl;

	cout << "Testing check_range(1, 5, 2). Expected: 1" << endl;
	actual_bool = check_range(1, 5, 2);
	cout <<"Actual: " <<  actual_bool << endl;
	if (actual_bool == false)
		cout << "FAILED" << endl;
	else
		cout << "PASSED" << endl;

	cout << "Testing is_capital('a'). Expected: 0" << endl;
	actual_bool = is_capital('a');
	cout <<"Actual: " <<  actual_bool << endl;
	if (actual_bool == true)
		cout << "FAILED" << endl;
	else
		cout << "PASSED" << endl;

	cout << "Testing is_capital('B'). Expected: 1" << endl;
	actual_bool = is_capital('B');
	cout <<"Actual: " <<  actual_bool << endl;
	if (actual_bool == false)
		cout << "FAILED" << endl;
	else
		cout << "PASSED" << endl;

	cout << "Testing is_even(9). Expected: 0" << endl;
	actual_bool = is_even(9);
	cout <<"Actual: " <<  actual_bool << endl;
	if (actual_bool == true)
		cout << "FAILED" << endl;
	else
		cout << "PASSED" << endl;

	cout << "Testing is_even(8). Expected: 1" << endl;
	actual_bool = is_even(8);
	cout <<"Actual: " <<  actual_bool << endl;
	if (actual_bool == false)
		cout << "FAILED" << endl;
	else
		cout << "PASSED" << endl;

	cout << "Testing is_odd(5). Expected: 1" << endl;
	actual_bool = is_odd(5);
	cout <<"Actual: " <<  actual_bool << endl;
	if (actual_bool == false)
		cout << "FAILED" << endl;
	else
		cout << "PASSED" << endl;

	cout << "Testing is_odd(6). Expected: 0" << endl;
	actual_bool = is_odd(6);
	cout <<"Actual: " <<  actual_bool << endl;
	if (actual_bool == true)
		cout << "FAILED" << endl;
	else
		cout << "PASSED" << endl;


	cout << "Testing equality_test(8, 10). Expected: -1" << endl;
	actual_int = equality_test(8, 10);
	cout <<"Actual: " <<  actual_int << endl;
	if (actual_int != -1)
		cout << "FAILED" << endl;
	else
		cout << "PASSED" << endl;

	cout << "Testing equality_test(8, 8). Expected: 0" << endl;
	actual_int = equality_test(8, 8);
	cout <<"Actual: " <<  actual_int << endl;
	if (actual_int != 0)
		cout << "FAILED" << endl;
	else
		cout << "PASSED" << endl;

	cout << "Testing float_is_equal(2.01, 2.18, .5). Expected: 1" << endl;
	actual_bool = float_is_equal(2.01, 2.18, .5);
	cout <<"Actual: " <<  actual_bool << endl;
	if (actual_bool == false)
		cout << "FAILED" << endl;
	else
		cout << "PASSED" << endl;

	cout << "Testing float_is_equal(2.01, 6.03, 1.0). Expected: 0" << endl;
	actual_bool = float_is_equal(2.01, 6.03, 1.0);
	cout <<"Actual: " <<  actual_bool << endl;
	if (actual_bool == true)
		cout << "FAILED" << endl;
	else
		cout << "PASSED" << endl;

	cout << "Testing is_int(\"fluffy\"). Expected: 0" << endl;
	actual_bool = is_int("fluffy");
	cout <<"Actual: " <<  actual_bool << endl;
	if (actual_bool == true)
		cout << "FAILED" << endl;
	else
		cout << "PASSED" << endl;

	cout << "Testing is_int(\"13495930\"). Expected: 1" << endl;
	actual_bool = is_int("13495930");
	cout <<"Actual: " <<  actual_bool << endl;
	if (actual_bool == false)
		cout << "FAILED" << endl;
	else
		cout << "PASSED" << endl;

	cout << "Testing num_present(\"My favorite number is 1\"). Expected: 1"
	<< endl;
	actual_bool = num_present("My favorite number is 1");
	cout <<"Actual: " <<  actual_bool << endl;
	if (actual_bool == false)
		cout << "FAILED" << endl;
	else
		cout << "PASSED" << endl;

	cout << "Testing num_present(\"I like food\"). Expected: 0" << endl;
	actual_bool = num_present("I like food");
	cout <<"Actual: " <<  actual_bool << endl;
	if (actual_bool == true)
		cout << "FAILED" << endl;
	else
		cout << "PASSED" << endl;

	cout << "Testing letters_present(\"12390hello\"). Expected: 1" << endl;
	actual_bool = letters_present("12390hello");
	cout <<"Actual: " <<  actual_bool << endl;
	if (actual_bool == false)
		cout << "FAILED" << endl;
	else
		cout << "PASSED" << endl;

	cout << "Testing letters_present(\"123@3194\"). Expected: 0" << endl;
	actual_bool = letters_present("123@3194");
	cout <<"Actual: " <<  actual_bool << endl;
	if (actual_bool == true)
		cout << "FAILED" << endl;
	else
		cout << "PASSED" << endl;

	cout << "Testing contains_sub_string(\"Chicken noodle soup\", \"soup\").";
	cout << "Expected: 1" << endl;
	actual_bool = contains_sub_string("Chicken noodle soup", "soup");
	cout <<"Actual: " <<  actual_bool << endl;
	if (actual_bool == false)
		cout << "FAILED" << endl;
	else
		cout << "PASSED" << endl;

	cout << "Testing contains_sub_string(\"Chicken noodle soup\", \"turkey\").";
	cout << " Expected: 0" << endl;
	actual_bool = contains_sub_string("Chicken noodle soup", "turkey");
	cout <<"Actual: " <<  actual_bool << endl;
	if (actual_bool == true)
		cout << "FAILED" << endl;
	else
		cout << "PASSED" << endl;

	cout << "Testing word_count(\"Chairs and tables\"). Expected: 3" << endl;
	actual_int = word_count("Chairs and tables");
	cout <<"Actual: " <<  actual_int << endl;
	if (actual_int != 3)
		cout << "FAILED" << endl;
	else
		cout << "PASSED" << endl;

	cout << "Testing word_count(\"FredMeyers\"). Expected:1" << endl;
	actual_int = word_count("FredMeyers");
	cout << "Actual: " << actual_int << endl;
	if (actual_int != 1)
		cout << "FAILED" << endl;
	else
		cout << "PASSED" << endl;

	cout << "Testing to_upper(\"I like cheese\").";
	cout << "Expected: \"I LIKE CHEESE\"" << endl;
	actual_string = to_upper("I like cheese");
	cout << "Actual: " << actual_string << endl;
	if (actual_string != "I LIKE CHEESE")
		cout << "FAILED" << endl;
	else
		cout << "PASSED" << endl;

	cout << "Testing to_lower(\"whIteBOARd MarKER\").";
	cout << "Expected: \"whiteboard marker\"" << endl;
	actual_string = to_lower("whIteBOARd MarKER");
	cout << "Actual: " << actual_string << endl;
	if (actual_string != "whiteboard marker")
		cout << "FAILED" << endl;
	else
		cout << "PASSED" << endl;

	cout << "Give intput an whole number to turn into an integer: ";
	cin >> int_input;
	cout << get_int(int_input) << endl;

	return 0;
}
