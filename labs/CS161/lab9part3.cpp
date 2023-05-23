//Dynamic

#include <iostream>
#include <cstdlib>

using namespace std;

void print_board(int** b, int size);
void towers(int number_of_disks, int** b, int from_col, int to_col, int spare, int overall);
void move_ring(int number_of_disks, int** b, int from_col, int to_col, int overall);
void reallocate_mem(int** b, int num_disks);


int main(int argc, char** argv) {
	const int col = 3;
	int num_disks = atoi(argv[1]);

	int** b = new int* [num_disks];

    for (int k = 0; k < num_disks; k++) {
        b[k] = new int [3];
    }

	for (int i = 0; i < col; i++) {
		if (i == 0) {
			for (int n = 0; n < num_disks; n++){
				b[n][i] = n + 1;
			}
		} else {
			for (int j = 0; j < num_disks; j++) {
				b[j][i] = 0;
			}
		}
	}

	print_board(b, num_disks);

	towers(num_disks, b, 0, 2, 1, num_disks);

    reallocate_mem(b, num_disks);

	return 0;
}

void reallocate_mem(int** b, int num_disks){
    for (int j = 0; j < num_disks; j++) {
        delete b[j];
    }

    delete b;
}

void towers(int number_of_disks, int ** b, int from_col, int to_col, int spare, int overall) {
    cout << "DONE" << endl;
    if(number_of_disks == 1){
        cout << "ONE" << endl;
        move_ring(number_of_disks, b, from_col, to_col, overall);
        print_board(b, overall);

    } else {
        cout << "ELSE" << endl;
        towers(number_of_disks-1, b, from_col, spare, to_col, overall);

        move_ring(number_of_disks, b, from_col, to_col, overall);
        print_board(b, overall);

        towers(number_of_disks-1, b, spare, to_col, from_col, overall);
        print_board(b, overall);

    }
} 

void move_ring(int number_of_disks, int** b, int from_col, int to_col, int overall) {
    cout << "MOVE";
    int i = 0;
    while (b[i][from_col] != number_of_disks) {
        i++;
    }

    int j = 0;

    while (b[j][to_col] == 0 && j < overall) {
        j++;
    }

    cout << j << endl;
    cout << i << endl;
    b[j-1][to_col] = b[i][from_col];
    b[i][from_col] = 0;
}

void print_board(int** b, int size) {
	int s = size;

	for (int i = 0; i < s; i++) {
		for (int j = 0; j < 3; j++) {
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
    cout << endl;

}
