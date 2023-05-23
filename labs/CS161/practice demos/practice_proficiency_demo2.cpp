#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

bool fun(int a[][3]);
int check_row(int a[][3], int row);
int check_column(int a[][3], int column);
int check_left_diag(int a[][3]);
int check_right_diag(int a[][3]);

int main() {
    int a[3][3];
    srand(time(NULL));

    for (int i; i < 3; i++) {
        a[i][0] = rand() % 10;
        a[i][1] = rand() % 10;
        a[i][2] = rand() % 10;
    }

    fun(a);

    return 0;
}

bool fun(int a[][3]){
    int row1 = check_row(a, 0);
    int row2 = check_row(a, 1);
    int row3 = check_row(a, 2);

    int column1 = check_column(a, 0);
    int column2 = check_column(a, 1);
    int column3 = check_column(a, 2);

    int l_diag = check_left_diag(a);
    int r_diag = check_right_diag(a);

    if (row1 == row2 && row1 == row3 && row1 == column1 && row1 == column2 && row1 == column3 && row1 == l_diag && row1 == r_diag){
        cout << "True" << endl;
        return true;
    } else {
        cout << "False" << endl;
        return false;
    }

}

int check_row(int a[][3], int row) {
    int value = 0;

    for (int i = 0; i < 3; i++){
        value += a[row][i];
    }

    cout << value << endl;

    return value;
}

int check_column(int a[][3], int column){
    int value = 0;

    for (int i = 0; i < 3; i++){
        value += a[i][column];
    }

    cout << value << endl;

    return value;
}

int check_left_diag(int a[][3]){
    int value = 0;

    for (int i = 0; i < 3; i++) {
        value += a[i][i];
    }
    cout << value << endl;

    return value;
}

int check_right_diag(int a[][3]){
    int value = 0;

    for (int i = 0; i < 3; i++) {
        value += a[i][2-i];
    }
    cout << value << endl;

    return value;
}