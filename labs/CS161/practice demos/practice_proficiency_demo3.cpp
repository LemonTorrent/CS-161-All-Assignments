#include <iostream>

using namespace std;

int fun(char *a);

int main() {
    char a[256];

    cout << "Enter an integer: ";
    cin >> a;

    int sum = fun(a);

    cout << "The sum is " << sum << endl;

    return 0;
}

int fun(char *a) {
    int sum = 0;

    int i = 0;
    while ('0' <= a[i] && a[i] <= '9'){
        sum += a[i] - 48;
        i++;
    }

    return sum;
}