#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

int count_ints(int a[], int size);

int main(int argc, char** argv) {
    int size;

    size = atoi(argv[1]); // IMPORTANT

    cout << size << endl;

    int* a = new int[size]; // IMPORTANT

    srand (time(NULL));
    for (int j = 0; j < size; j++) {
        a[j] = rand() % 2;
        cout << a[j] << endl;
    }

    count_ints(a, size);

    delete [] a; // IMPORTANT
    a = NULL;

    return 0;
}


int count_ints(int a[], int size){
    int count_one = 0;
    int count_zero = 0;

    for (int i = 0; i < size; i++) {
        if (a[i] == 1){
            count_one += 1;
        } else if (a[i] == 0) {
            count_zero += 1;
        }
    }

    cout << "Amount of 1's: " << count_one << endl;
    cout << "Amount of 0's: " << count_zero << endl;
    return 0;
}