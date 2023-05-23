#include <iostream>
#include <string>

using namespace std;

void get_string(string *str);

void set_replace_string(string str, string *str2);

int get_search_replace(char a, string str, string &str2);

int main() {
	string str, str2;
	char a;
	int replacement;

	get_string(&str);	

	str2 = str;
	set_replace_string(str, &str2);

	cout << "What character would you like to replace spaces by? ";
	cin >> a;
	cout << "Characters replaced: " << replacement << endl;

	replacement = get_search_replace(a, str, str2);

	return 0;
}

void get_string(string *str) {
	string str2;

	cout << "What string would you like to use? ";
	getline(cin, *str);
	str2 = *str;

}

void set_replace_string(string str, string *str2) {

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ')
			str.replace(i, 1, "-");
	}
	cout << str << endl;

}

int get_search_replace(char a, string str, string &str2) {
	int replace = 0;
	
	for (int i = 0; i < str.length(); i++){
		if (str[i] == ' ') {
			str[i] = a;
			replace += 1;
		}
	}
	cout << str << endl;
	return replace;
}
