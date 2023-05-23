#include <iostream>
using namespace std;
int a_to_i(char a) {
	int i;

	i = a;

	cout << i << endl;

	return 0;

}



int main() {

	char a;

	cout << "Enter character";
	cin >> a;

	a_to_i(a);

	return 0;
}
