#include <iostream>

using namespace std;

void funct1() {
    int *i = NULL;
    i = new int;
    *i = 2;
}

void funct2() {
    int *j = NULL;
    j = new int;
    *j = 3;
}

void funct3() {
    int *k = NULL;
    k = new int;
    *k = 2;
}

int main() {
    int *i, *k, *j;
    funct1();
    funct2();
    funct3();
    cout << i << j << k << endl;
    return 0;
}