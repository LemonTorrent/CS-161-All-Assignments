#include namespace <iostream>

using namespace std;

int main() {

    int user_opinion;

    cout << "Do you like vim as an editor? (Enter 0 for no and 1 for yes.)" << endl;
    cin >> user_opinion;

    if (user_opinion == 1)
	cout << "You love vi!";
    else if (user_opinion == 0)
	cout << "You hate vi!";


    return 0;
}
