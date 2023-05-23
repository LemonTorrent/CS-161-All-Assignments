#include <iostream>
#include <string.h>

using namespace std;

int print_array(string array[], int size);

int main() {
	int num_words;
	char paragraph[21];

	cout << "Please enter a string with 20 char or less: ";
	cin.getline(paragraph, 20);

	cout << "How many words? ";
	cin >> num_words;
	
	string *words = new string[num_words+1];

	for (int i = 0; i <= num_words; i++)
		getline(cin, words[i]);

	print_array(words, num_words + 1);
	
	delete [] words;

	return 0;
}

int print_array(string array[], int size){
	for (int i = 0; i < size; i++)
		cout << array[i] << ' ';
	cout << endl;
	return 0;
}	
