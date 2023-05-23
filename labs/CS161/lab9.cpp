// Dynamic

#include <iostream>

using namespace std;

void print_board(int b[][3]);
void towers(int num_disks, int b[][3], int f_col, int t_col, int spare, int rows);
void move(int num_disks, int b[][3], int f_col, int t_col, int spare, int rows);

int main() {
	const int col = 3;
	int num_disks;

	cout << "How many disks would you like to use? ";
	cin >> num_disks;

	int b [num_disks][3];

	print_board(b);

	cout << endl;

	for (int i = 0; i < num_disks; i++) {
		if (i == 0) {
			for (int n = 0; n < col; n++){
				b[n][i] = n + 1;
			}
		} else {
			for (int j = 0; j < col; j++) {
				b[j][i] = 0;
			}
		}
	}

	print_board(b);

	towers(num_disks, b, 0, 2, 1, num_disks);

	return 0;
}

void towers(int num_disks, int b[][3], int f_col, int t_col, int spare, int rows) {
	if (num_disks > 1) {
		towers(num_disks-1, b, f_col, spare, t_col, rows);
		move(num_disks, b, f_col, t_col, spare, rows); 
		print_board(b);
		towers(num_disks-1, b, spare, t_col, f_col,rows);
	}
}

void move(int num_disks, int b[][3], int f_col, int t_col, int spare, int rows){
	int top = b[0][num_disks-1];
	cout<< top << endl;

	b[0][num_disks-1] = 0;
	b[rows][2] = top;

	for (int i= 1; i < 3; i++) {
		for (int j = 0; j < num_disks; j++) {
			if (b[j][i] == 0){
				b[j][i] = top;
			}
		}
	}

	print_board(b);

}

void print_board(int b[][3]) {
//	int s = sizeof(b);
	int s = 3;

	for (int i = 0; i < s; i++) {
		for (int j = 0; j < 3; j++) {
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
}
