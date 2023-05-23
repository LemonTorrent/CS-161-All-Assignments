/******************************************************************************
 ** Program: assignment4.cpp
 ** Author: Nicole Yarbrough
 ** Date: 03/01/2020
 ** Description: This program performs 
 ** Input: paragraph/string, choice of what to do
 ** Output: either the amount of consonants vs. vowels, a string with swapped
 ** letters, whether the string contains a palindrome, the frequency of words,
 ** or a string with reversed order.
 *****************************************************************************/ 

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <cmath>


using namespace std;

int starting_input(int *paragraph, int *choice);
string get_file();
void change_str(string temp_par, int *paragraph);
bool file_exist(string file_name);
void get_task(int *choice);
int get_int(string prompt);
bool is_int(string num);
void choose_funt(int *choice, char paragraph[], int len_paragraph);
void cons_vow(char paragraph[], int len_paragraph);
bool is_vow(char character);
bool is_cons(char character);
void swap_letters(int paragraph, int len_paragraph);
void reverse_order(char paragraph[], int len_paragraph);
void is_palindrome(char paragraph[], int len_paragraph);
void fix_case(char temp_paragraph[], int len_paragraph);
void check_palindrome(char temp_paragraph[], int len_temp, int len_paragraph);
bool cont_program();
bool bool_input(string input);
void reverse_char(char paragraph[], int len_paragraph);
void word_freq(char paragraph[], int len_paragraph);

/*******************************************************************
** Function: main()
** Description: This is the function that initiates the other
** functions
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 

int main() {
	do {
		int *paragraph;
		int *choice;
		int len_paragraph;

		len_paragraph = starting_input(paragraph, choice);
		choose_funt(choice, paragraph, len_paragraph);
		delete [] paragraph;
		delete choice;
	} while (cont_program() == true);

	return 0;
}

/*******************************************************************
** Function: starting_input()
** Description: This is the function that gets input for other
** functions
** Parameters: paragraph, choice
** Pre-Conditions: paragraph and choice must have been created
** Post-Conditions: None
*******************************************************************/ 

int starting_input(int *paragraph, int *choice) {
	string temp_par;
	int len_paragraph;
	int const_size;

	temp_par = get_file();
	get_task(choice);

	const_size = temp_par.length() + 1;
	paragraph = new int[const_size];
	change_str(temp_par, paragraph);
	len_paragraph = temp_par.length();
	return len_paragraph;
}


/*******************************************************************
** Function: get_file()
** Description: this function takes the information from a text file
** and stores the data in a string.
** Parameters: none
** Pre-Conditions: None
** Post-Conditions: none
*******************************************************************/ 
string get_file(){
	string temp_par;
	string file_address;

	do {
		cout << "What is the address of the file? ";
		getline(cin, file_address);
	} while (file_exist(file_address) == true);

	ifstream myfile (file_address.c_str());
	getline(myfile, temp_par);
	
	myfile.close();
	return temp_par;
}


/*******************************************************************
** Function: change_str()
** Description: This is the function changes a c++ string to c
** style string
** Parameters: temp_par, *paragraph
** Pre-Conditions: paragraph and temp_par must have been created
** Post-Conditions: None
*******************************************************************/ 
void change_str(string temp_par, int *paragraph) {
	for (int i; i < temp_par.length(); i++) {
		paragraph[i] = temp_par[i];
	}
}

/*******************************************************************
** Function: file_exist()
** Description: checks whether the file exists
** Parameters: file_name
** Pre-Conditions: user must have inputted file name
** Post-Conditions: None
*******************************************************************/ 
bool file_exist(string file_name){
	ifstream MyFile (file_name.c_str());
	if (MyFile.is_open()){
		return true;
	} else {
		return false;
	}
}

/*******************************************************************
** Function: get_task()
** Description: gets task from user
** Parameters: *choice
** Pre-Conditions: choice must have been initialized
** Post-Conditions: None
*******************************************************************/ 
void get_task(int *choice){
	string temp_choice;
	do {
		cout << "Enter 1 to count the amount of consonants and vowels, 2 to ";
		cout << "swap letters, 3 to reverse the string, 4 to detect if the ";
		cout << "string is a palindrome, or 5 to find frequency of words: ";
		cin >> temp_choice;
	} while (is_int(temp_choice) == false);

	*choice = get_int(temp_choice);
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
** Function: is_int()
** Description: This is the function where the string is checked to
** be an integer that is desired.
** Parameters: num
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
bool is_int(string num) {

	for (int i = 0; i < num.length(); i++) {
		if (num[i] < '1' or num[i] > '5')
			return false;
	}
	return true;

}

/*******************************************************************
** Function: choose_funct()
** Description: sends program to the function that the user wants to
** use
** Parameters: paragraph, choice, len_paragraph
** Pre-Conditions: paragraph and choice must have been created
** Post-Conditions: None
*******************************************************************/ 
void choose_funt(int *choice, char paragraph[], int len_paragraph){
	if (*choice == 1)
		cons_vow(paragraph, len_paragraph);
	else if (*choice == 2)
		swap_letters(paragraph, len_paragraph);
	else if (*choice == 3)
		reverse_order(paragraph, len_paragraph);
	else if (*choice == 4)
		is_palindrome(paragraph, len_paragraph);
	else if (*choice == 5)
		word_freq(paragraph, len_paragraph);
	else
		exit;

}

/*******************************************************************
** Function: cons_vow()
** Description: checks the amount of vowels and consonents and returns
** whether they are equal.
** Parameters: paragraph, len_paragraph
** Pre-Conditions: paragraph and choice must have been created
** Post-Conditions: None
*******************************************************************/ 
void cons_vow(char paragraph[], int len_paragraph) {
	int vowel = 0, consonant = 0;

	for (int i; i <= len_paragraph; i++){
		if (is_vow(paragraph[i]) == true) {
			vowel += 1;
		} else if (is_cons(paragraph[i]) == true) {
			consonant += 1;
		}
	}
	if (vowel > consonant) {
		cout << "vowels > consonants" << endl;
	} else if (vowel < consonant) {
		cout << "vowels < consonants" << endl;
	} else {
		cout << "vowels = consonants" << endl;
	}
}

bool is_vow(char character) {
	if (character == 'A' || character == 'a' || character == 'E' 
	|| character == 'e' || character == 'I' || character == 'i' 
	|| character == 'O' || character == 'o' || character == 'U' 
	|| character == 'u') {
		return true;
	} else {
		return false;
	}
}

bool is_cons(char character) {
	if (character == 'B' || character == 'b' || character == 'C' 
	|| character == 'c' || character == 'D' || character == 'd' 
	|| character == 'F' || character == 'f' || character == 'G' 
	|| character == 'g' || character == 'H' || character == 'h' 
	|| character == 'J' || character == 'j' || character == 'K' 
	|| character == 'k' || character == 'L' || character == 'l' 
	|| character == 'M' || character == 'm' || character == 'N' 
	|| character == 'n' || character == 'P' || character == 'p' 
	|| character == 'Q' || character == 'q' || character == 'R' 
	|| character == 'r' || character == 'S' || character == 's' 
	|| character == 'T' || character == 't' || character == 'V' 
	|| character == 'v' || character == 'W' || character == 'w' 
	|| character == 'X' || character == 'x' || character == 'Y' 
	|| character == 'y' || character == 'Z' || character == 'z'){
		return true;
	} else {
		return false;
	}
}

void swap_letters(int paragraph, int len_paragraph){


}

void reverse_order(char paragraph[], int len_paragraph){
	int temp_paragraph [len_paragraph + 1];
	for (int i; i <= len_paragraph; i++){
		temp_paragraph[i] = paragraph[-i-1];
	}
	cout << "Reversed string: ";

	for (int j; j <= len_paragraph; j++) {
		cout << temp_paragraph[j];
	}

	cout << endl;
}

void is_palindrome(char paragraph[], int len_paragraph){
	char *temp_paragraph = new char [len_paragraph+1];
	int len_temp = 0;

	for (int i; i <= len_paragraph; i++){
		if ((paragraph[i] >= 'A' && paragraph[i] <= 'Z')||(paragraph[i] >= 'a' 
		&& paragraph[i] <= 'z')) {
			temp_paragraph += paragraph[i];
			len_temp += 1;
		}
	}

	fix_case(temp_paragraph, len_paragraph);
	check_palindrome(temp_paragraph, len_temp, len_paragraph);

	delete [] temp_paragraph;
}

void fix_case(char temp_paragraph[], int len_paragraph) {
	for (int i; i <= len_paragraph; i++){
		if (temp_paragraph[i] >= 'A' && temp_paragraph[i] <= 'Z') {
			temp_paragraph[i] = temp_paragraph[i] + 32;
		}
	}
}

void check_palindrome(char temp_paragraph[], int len_temp, int len_paragraph){
	for (int i; i <= (len_paragraph/2); i++) {
		if (temp_paragraph[i] != temp_paragraph[-i-1]){
			cout << "String is not a palindrome" << endl;
		}
	}
	cout << "String is a palindrome" << endl;
}

bool cont_program() {
	string cont_choice;

	do {
		cout << "Enter 1 to use this tool again, 0 to exit: ";
		cin >> cont_choice;
	} while(bool_input(cont_choice) == true);

	if (cont_choice == "0")
		return false;
	else
		return true;
}

void reverse_char(char paragraph[], int len_paragraph) {

}

void word_freq( char paragraph[], int len_paragraph){

}


bool bool_input(string input){
	if ((input.length() == 1) && (input == "0" || input == "1"))
		return true;
	else
		return false;
}