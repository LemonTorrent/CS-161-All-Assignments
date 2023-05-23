/******************************************************************************
 ** Program: assignment5.cpp
 ** Author: Nicole Yarbrough
 ** Date: 03/16/2020
 ** Description: This program is a connect 4 game. Also, this is my second 
 ** version of my code because we got an extension.
 ** Input: size of board (row and columns), number of players (1 or 2)
 ** Output: game board, winner of the game
 *****************************************************************************/ 

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <ctime>
#include <cmath>

using namespace std;

void get_inputs(char** argv, int* rows, int* column, int* players);
bool check_start(int argc, char** argv, int* rows, int* column, int* players);
bool check_int_c(char a[]);
void start(char** b, int rows, int column, int players);
void single_player(char** b, int rows, int column);
void two_player(char** b, int rows, int column);
int get_move(char** b, int row, int column);
bool is_int(string num);
int get_int(string prompt);
void move (char** b, int row, int column, char marker);
bool check_move(char** b, int row, int column, int c_column);
int find_row(char** b, int row, int column, int c_column);
bool check_winner(char** b, int row, int column, char* winner);
bool check_left_diag(char** b, int row, int column, char* winner);
bool check_right_diag(char** b, int row, int column, char* winner);
bool check_rows(char** b, int row, int column, char* winner);
bool check_columns(char** b, int row, int column, char* winner);
bool check_full(char** b, int row, int column);
void delete_board(char** b, int row);
int computer_mov(char** b, int row, int column);
void print_board(char** board, int row, int col);
int get_players();
int get_rows();
int get_column();
bool play_again(int* column, int* rows, int* players);
bool player1_choice(char* player_marker, char* c_marker);
void get_comp_marker(char* c_marker, char player_marker);
void turn(char** b, int rows, int column, char marker);
void computer_turn(char** b, int rows, int column, char marker);
void declare_winner(char marker1, char marker2, char winner);
void single_player_winner(char player_marker, char winner);
void check_args(int argc, char** argv, int* rows, int* column, int* players);
void check_players(int argc, char** argv, int* rows, int* column, int* players);
void check_rows(int argc, char** argv, int* rows, int* column, int* players);
void check_columns(int argc, char** argv, int* rows, int* column, int* players);

/*******************************************************************
** Function: main()
** Description: The main function takes command line input and
** initializes the game board.
** Parameters: number of players, rows, and columns
** Pre-Conditions: parameters entered in command line
** Post-Conditions: None
*******************************************************************/ 
int main(int argc, char** argv) {
	int column, rows, players;
	if (check_start(argc, argv, &column, &rows, &players) == true) // check if # args, players, and rows/columns
		get_inputs(argv, &rows, &column, &players); // turn c string into int

	do {
		char** board = new char* [rows]; //create 1d array of pointers
		for (int i = 0; i < rows; i++) {   //create 2d array
			board[i] = new char [column];
			for (int n = 0; n < column; n++) {
				board[i][n] = ' ';
			}
		}
		start(board, rows, column, players);
		delete_board(board, rows);
	} while (play_again(&column, &rows, &players) == true);
	return 0;
}


/*******************************************************************
** Function: gets_inputs()
** Description: Changes c string inputs into integers
** Parameters: argv, rows, column, playeres
** Pre-Conditions: argv, rows, column, and players must exist/ have
** been initialized
** Post-Conditions: None
*******************************************************************/ 
void get_inputs(char** argv, int* rows, int* column, int* players){
	*rows = atoi(argv[2]);
	*column = atoi(argv[3]);
	*players = atoi(argv[1]);
}


/*******************************************************************
** Function: check_start()
** Description: The function that checks initial inputs
** Parameters: number of players, rows, and columns
** Pre-Conditions: parameters entered in command line
** Post-Conditions: None
*******************************************************************/ 
bool check_start(int argc, char** argv, int* rows, int* column, int* players) { // row and columns both less than 20
	if (argc < 4) { //Gets initializing input if there aren't enough arguments
		check_args(argc, argv, rows, column, players);
	} else {
		check_players(argc, argv, rows, column, players); //gets amount of players
		check_rows(argc, argv, rows, column, players); //gets number of rows
		check_columns(argc, argv, rows, column, players); // gets number of columns
	}

	if (argc >= 4 && 
	(check_int_c(argv[1]) == true && (atoi(argv[1]) == 1 || 
	atoi(argv[1]) == 2)) && (check_int_c(argv[2]) && (atoi(argv[2]) >= 4 && 
	atoi(argv[2]) <= 20)) && (check_int_c(argv[3]) && (atoi(argv[3]) >= 4 && 
	atoi(argv[3]) <= 20))){
		return true; // return true if the user inputted everything correctly
	}
	return false;
}

/*******************************************************************
** Function: check_args()
** Description: This is function checks if the test value is within
** the upper and lower bounds.
** Parameters: argc, argv, rows, column, players
** Pre-Conditions: Parameters initialized
** Post-Conditions: None
*******************************************************************/ 
void check_args(int argc, char** argv, int* rows, int* column, int* players){
	cout << "Too few arguments\n" << endl;
	*players = get_players(); //gets number of players
	*rows = get_rows(); //gets number of rows
	*column = get_column(); //gets number of columns
}

/*******************************************************************
** Function: check_players()
** Description: Checks whether input for number of players is good 
** or bad. If good, the input is converted to an int.
** Parameters: argc, argv, rows, column, players
** Pre-Conditions: parameters initialized
** Post-Conditions: None
*******************************************************************/ 
void check_players(int argc, char** argv, int* rows, int* column, int* players){
	if (check_int_c(argv[1]) == false || (atoi(argv[1]) != 1 && atoi(argv[1]) != 2)) {
		*players = get_players(); //gets number of players if input is bad
	} else {
		*players = atoi(argv[1]); //gets number of players from command prompt info if input is good
	}
}

/*******************************************************************
** Function: check_rows()
** Description: Checks whether input for number of rows is good 
** or bad. If good, the input is converted to an int.
** Parameters: argc, argv, rows, column, players
** Pre-Conditions: parameters initialized
** Post-Conditions: None
*******************************************************************/ 
void check_rows(int argc, char** argv, int* rows, int* column, int* players){
	if (check_int_c(argv[2]) == false || atoi(argv[2]) < 4 || atoi(argv[2]) > 20) {
		*rows = get_rows(); //gets number of rows if input is bad
	} else {
		*rows = atoi(argv[2]); //gets number of rows if input is good
	}
}

/*******************************************************************
** Function: check_columns()
** Description: Checks whether input for number of columns is good 
** or bad. If good, the input is converted to an int.
** Parameters: argc, argv, rows, column, players
** Pre-Conditions: parameters initialized
** Post-Conditions: None
*******************************************************************/ 
void check_columns(int argc, char** argv, int* rows, int* column, int* players) {
	if (check_int_c(argv[3]) == false || atoi(argv[3]) < 4 || atoi(argv[3]) > 20) {
		*column = get_column(); //gets number of columns if input is bad
	} else {
		*column = atoi(argv[3]); //gets number of columns if input is good
	}
}

/*******************************************************************
** Function: get_players()
** Description: Gets number of players from user
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
int get_players() {
	string players;

	do {
		cout << "Please enter the number of players (1 or 2): ";
		cin >> players;
	} while (players != "1" && players != "2"); // only accepts if there are 1 or 2 players

	return get_int(players);
}

/*******************************************************************
** Function: get_rows()
** Description: Gets number of rows from user
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
int get_rows() {
	string rows;
	int int_rows = 0;

	do {
		cout << "Please enter the number of rows (4 - 20): ";
		cin >> rows;
		if (is_int(rows) == true) {
			int_rows = get_int(rows);
		}
	} while (get_int(rows) < 4 || get_int(rows) > 20); // only accepts if there are 4-20 rows

	return int_rows;
}

/*******************************************************************
** Function: get_column()
** Description: Gets number of columns from user
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
int get_column() {
	string col;
	int int_col = 0;

	cout << "yoyo";
	do {
		cout << "Please enter the number of columns (4 - 20): ";
		cin >> col;
		if (is_int(col) == true) {
			int_col = get_int(col);
		}
	} while (get_int(col) < 4 || get_int(col) > 20); // only accepts if there are 4-20 rows

	return int_col;
}

/*******************************************************************
** Function: check_int_c()
** Description: The function that checks if input can become int
** Parameters: c string
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
bool check_int_c(char a[]){    //check if c string inputs can become ints
	for (int i; i < strlen(a); i++){
		if (a[i] < '0' || a[i] > '9') {
			return false;
		}
	}
	return true;
}


/*******************************************************************
** Function: start()
** Description: Directs the game the 1 player or 2 player route.
** Parameters: number of players, rows, and columns
** Pre-Conditions: parameters entered in command line
** Post-Conditions: None
*******************************************************************/ 
void start(char** b, int rows, int column, int players){ 	//1 player or 2 player
	if (players == 1) {
		single_player(b, rows, column);
	} else {
		two_player(b, rows, column);
	}
}

/*******************************************************************
** Function: single_player()
** Description: The function initializes game play for single players
** Parameters: number of players, rows, and columns
** Pre-Conditions: parameters entered in command line
** Post-Conditions: None
** Justification: I had two really long if statements, so I had to
** divide it between 2 lines.
*******************************************************************/ 
void single_player(char** b, int rows, int column){
	int move;
	char player_marker, c_marker, winner;
	bool order = player1_choice(&player_marker, &c_marker);

	if (order == true) { // runs if player indicates they want to go first
		turn(b, rows, column, player_marker);
	}

	do {
		computer_turn(b, rows, column, c_marker);
		if (check_full(b, rows, column) == false &&
		check_winner (b, rows, column, &winner) == false) { // runs until board is full or winner is found
			turn(b, rows, column, player_marker);
		}
	} while (check_full(b, rows, column) == false &&
	check_winner (b, rows, column, &winner) == false); // runs until board is full or winner is found

	print_board(b, rows, column);
	single_player_winner(player_marker, winner);
}

/*******************************************************************
** Function: single_player_winner()
** Description: Congratulates player depending on whether they won
** Parameters: player_marker, winner
** Pre-Conditions: parameters exist
** Post-Conditions: None
*******************************************************************/ 
void single_player_winner(char player_marker, char winner) {
	if (player_marker == winner) {
		cout << "Congratulations Player 1 you have won!" << endl;
	} else {
		cout << "Good job playing! You got 2nd place ;)" << endl;
	}
}

/*******************************************************************
** Function: to_upper()
** Description: This is the function where lowercase letters are
** changed to uppercase letters within a string.
** Parameters: sentence
** Pre-Conditions: None
** Post-Conditions: Fully uppercase string.
*******************************************************************/ 
string to_upper(string sentence) {
	string new_sentence;

	for (int i = 0; i < sentence.length(); i++) {
		if (sentence[i] >= 'a' and sentence[i] <= 'z')
			new_sentence += char (sentence[i] - 32);
		else
			new_sentence += sentence[i];
	}

	return new_sentence;

}

/*******************************************************************
** Function: player1_choice()
** Description: Player is asked for their preferances with order of
** play and marker (O or X) choice.
** Parameters: player_marker, c_marker
** Pre-Conditions: parameters must have been initialized
** Post-Conditions: None
*******************************************************************/ 
bool player1_choice(char* player_marker, char* c_marker){
	string choice, marker_choice;
	do {
		cout << "Would you like to move before the computer? (1=yes, 0=no) ";
		cin >> choice;
	} while (choice != "1" && choice != "0"); // only accepts yes/no as answers

	do {
		cout << "Would you like to use O or X? (letter O, letter X) ";
		cin >> marker_choice;
		marker_choice = to_upper(marker_choice);
	} while (marker_choice != "O" && marker_choice != "X"); // only 2 options, X or O

	*player_marker = marker_choice[0];
	get_comp_marker(c_marker, *player_marker);

	if (choice == "1")
		return true;
	return false;
}

/*******************************************************************
** Function: get_comp_marker()
** Description: Gets computer's marker
** Parameters: c_marker, player_marker
** Pre-Conditions: parameters initialized
** Post-Conditions: computer's marker
*******************************************************************/ 
void get_comp_marker(char* c_marker, char player_marker) {
	if (player_marker == 'O') {
		*c_marker = 'X';
	} else {
		*c_marker = 'O';
	}
}

/*******************************************************************
** Function: turn()
** Description: board is printed, move gotten from get_move(), 
** board is updated
** Parameters: b, rows, column, marker
** Pre-Conditions: parameters initialized
** Post-Conditions: Updated board
*******************************************************************/ 
void turn(char** b, int rows, int column, char marker) {
	print_board(b, rows, column);
	int move = get_move(b, rows, column); // gets user's move
	b[find_row(b, rows, column, move)][move] = marker;
}

/*******************************************************************
** Function: computer_turn()
** Description: board is printed, move gotten from computer_move(), 
** board is updated
** Parameters: b, rows, column, marker
** Pre-Conditions: parameters initialized
** Post-Conditions: Updated board
*******************************************************************/ 
void computer_turn(char** b, int rows, int column, char marker){
	print_board(b, rows, column);
	int move = computer_mov(b, rows, column); // gets computer's move
	b[find_row(b, rows, column, move)][move] = marker;
	cout << "Computer's turn:" << endl;

}

/*******************************************************************
** Function: computer_mov()
** Description: The function chooses the move for the computer.
** Parameters: board, row, column
** Pre-Conditions: parameters initialized
** Post-Conditions: Computer's move
*******************************************************************/ 
int computer_mov(char** b, int row, int column){
	int mov;
	srand(time(NULL));
	do {
		mov = (rand() % column);
	} while (b[0][mov] != ' '); // doesn't allow computer to choose full column

	return mov;
}

/*******************************************************************
** Function: two_player()
** Description: The function initializes two player game
** Parameters: number of players, rows, and columns
** Pre-Conditions: parameters entered in command line
** Post-Conditions: None
** Justification: There were 2 long if statements that each got 
** divided into two lines.
*******************************************************************/ 
void two_player(char** b, int rows, int column) {
	int mov;
	char marker = 'X';
	char marker2 = 'O';
	char winner;

	do {
		cout << "Player 1's turn." << endl;
		turn(b, rows, column, marker);
		if (check_full(b, rows, column) == false &&
		check_winner(b, rows, column, &winner) == false) { //if game is still going, player 2 goes
			cout << "Player 2's turn." << endl;
			turn(b, rows, column, marker2);
		}
	} while (check_full(b, rows, column) == false &&
	check_winner(b, rows, column, &winner) == false);// checks if game is still going
	print_board(b, rows, column); // prints board after game ends
	declare_winner(marker, marker2, winner); //declare winner
}

/*******************************************************************
** Function: declare_winner()
** Description: Declares winner and prints final board
** Parameters: marker1, marker2, winner
** Pre-Conditions: parameters initialized
** Post-Conditions: None
*******************************************************************/ 
void declare_winner(char marker1, char marker2, char winner) {
	if (marker1 == winner){
		cout << "Congratulations player 1, you are the winner!" << endl;
	} else {
		cout << "Congratulations player 2, you are the winner!" << endl;
	}
}

/*******************************************************************
** Function: get_move()
** Description: The function takes players' choice in move.
** Parameters: number of players, rows, and columns
** Pre-Conditions: parameters entered in command line
** Post-Conditions: None
*******************************************************************/ 
int get_move(char** b, int row, int column){
	string choice;
	int move;

	do {
		cout << "Which column would you like to place a marker in?  ";
		cin >> choice;
	} while (is_int(choice) == false || get_int(choice) < 1 ||
	get_int(choice) > column || b[0][get_int(choice)-1] != ' '); 
	//checks if choice is within boundry and if the collumn is full

	move = get_int(choice) - 1;
	return move;
}

/*******************************************************************
** Function: print_board()
** Description: Prints the board
** Parameters: number of players, rows, and columns
** Pre-Conditions: parameters entered in command line
** Post-Conditions: None
*******************************************************************/ 
void print_board(char** board, int row, int col){
	for (int i = 0; i < col; ++i)
		cout << "  "<< i+1 << " ";
	
	cout << endl;

	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			if (i % 2 == 0 && j % 2 == 0)
				cout << "|\033[30;47m " << board[i][j] << " "; 
			else if (i % 2 == 1 && j % 2 == 1)
				cout << "|\033[30;47m " << board[i][j] << " ";
			else
				cout << "|\033[0m " << board[i][j] << " ";
			cout << "\033[0m";
		}
		cout << endl;
	}
}

/*******************************************************************
** Function: is_int()
** Description: This is the function where the string is checked to
** be an integer.
** Parameters: num
** Pre-Conditions: None
** Post-Conditions: None
*******************************************************************/ 
bool is_int(string num) {

	for (int i = 0; i < num.length(); i++) {
		if (num[i] < '0' or num[i] > '9')
			return false;
	}
	return true;

}

/*******************************************************************
** Function: get_int()
** Description: This is the function where strings of number
** characters are turned into an integer.
** Parameters: prompt
** Pre-Conditions: None
** Post-Conditions: The integer resulting from the string prompt.
*******************************************************************/ 

int get_int(string prompt) {
  int output_int = 0;

  if (prompt[0] == '-') {
    for (int i = 1; i < prompt.length(); i++){
      output_int += ((prompt[prompt.length()-i] - 48) * pow(10, i-1));
    }

    output_int *= -1;
  } else {    
    for (int i = 0; i < prompt.length(); i++){
    output_int += ((prompt[prompt.length()-1-i] - 48) * pow(10, i));
    }
  }
		
	return output_int;
}

/*******************************************************************
** Function: move()
** Description: How the player moves.
** Parameters: number of players, rows, and columns
** Pre-Conditions: parameters entered in command line
** Post-Conditions: None
*******************************************************************/ 
void move (char** b, int row, int column, char marker) {
	int c_column, c_row;

	do {
		cout << "What column would you like to place a marker? ";
		cin >> c_column;
	} while (check_move(b, row, column, c_column) == false);

	c_row = find_row(b, row, column, c_column);

	b[c_row][c_column] = marker;
}

/*******************************************************************
** Function: check_move()
** Description: Checks to make sure that the player's move can be done.
** Parameters: number of players, rows, and columns
** Pre-Conditions: parameters entered in command line
** Post-Conditions: None
*******************************************************************/ 
bool check_move(char** b, int row, int column, int c_column){ // error handle for c_column
	if (c_column < 1 || c_column > column) {
		return false;
	} else if (b[0][c_column] == 'X' || b[0][c_column] == 'O'){
		return false;
	} else if (b[find_row(b, row, column, c_column)][c_column] != ' '){
		return false;
	} else {
		return true;
	}
}

/*******************************************************************
** Function: find_row()
** Description: finds the row in correspondance to the column
** Parameters: number of players, rows, and columns
** Pre-Conditions: parameters entered in command line
** Post-Conditions: None
*******************************************************************/ 
int find_row(char** b, int row, int column, int c_column){
	int c_row, i = 0;

	while (i < row && b[i][c_column] == ' ') {// && b[i][column] != 'O') {
		i++;
	}

	c_row = i - 1;
	return c_row;
}

/*******************************************************************
** Function: check_winner()
** Description: checks if there is a winner
** Parameters: number of players, rows, and columns
** Pre-Conditions: parameters entered in command line
** Post-Conditions: None
*******************************************************************/ 
bool check_winner(char** b, int row, int column, char* winner){
	if (check_left_diag(b, row, column, winner) == true){
		return true;
	} else if (check_right_diag(b, row, column, winner) == true) {
		return true;
	} else if (check_rows(b, row, column, winner) == true) {
		return true;
	} else if (check_columns(b, row, column, winner) == true) {
		return true;
	} else {
		return false;
	}
}

/*******************************************************************
** Function: check_left_diagonal()
** Description: Checks left diagonal for winner
** Parameters: number of players, rows, and columns
** Pre-Conditions: parameters entered in command line
** Post-Conditions: None
*******************************************************************/ 
bool check_left_diag(char** b, int row, int column, char* winner) {
	for (int i = 0; i < column - 3; i++) {
		for (int j = 0; j < row - 3; j++) {
			if (b[j][i] != ' ' && b[j][i] == b[j+1][i+1] &&
			b[j][i] == b[j+2][i+2] && b[j][i]== b[j+3][i+3]) {
				*winner = b[j][i];
				return true;
			}
		}
	}
	return false;
}

/*******************************************************************
** Function: check_right diagonal()
** Description: checks right diagonal for winner
** Parameters: number of players, rows, and columns
** Pre-Conditions: parameters entered in command line
** Post-Conditions: None
*******************************************************************/ 
bool check_right_diag(char** b, int row, int column, char* winner) {
	for (int j = 1; j <= row - 3; j++) {
		for (int i = 0; i <= (column-3); i++) {
			if (b[row-j][i] != ' ' && b[row - j][i] == b[row - (j+1)][i+1] &&
			b[row-j][i] == b[row - (j+2)][i+2] &&
			b[row-j][i] == b[row - (j+3)][i+3]) {
				*winner = b[row-j][column - i];
				return true;
			}
		}
	}
	return false;
}


/*******************************************************************
** Function: check_rows()
** Description: checks rows for winner
** Parameters: number of players, rows, and columns
** Pre-Conditions: parameters entered in command line
** Post-Conditions: None
*******************************************************************/ 
bool check_rows(char** b, int row, int column, char* winner) {
	for (int j = 0; j < row; j++){
		for (int i = 0; i < column - 3; i++) {
			if (b[j][i] != ' ' && b[j][i] == b[j][i+1] &&
			b[j][i] == b[j][i+2] && b[j][i] == b[j][i+3]){
				*winner = b[j][i];
				return true;
			}
		}
	}
	return false;
}

/*******************************************************************
** Function: check_columns()
** Description: checks columns for winner
** Parameters: number of players, rows, and columns
** Pre-Conditions: parameters entered in command line
** Post-Conditions: None
*******************************************************************/ 
bool check_columns(char** b, int row, int column, char* winner) {
	for (int i = 0; i < column; i++){
		for (int j = 0; j < row - 3; j++) {
			if (b[j][i] != ' ' && b[j][i] == b[j+1][i] &&
			b[j][i]== b[j+2][i] && b[j][i]== b[j+3][i]){
				*winner = b[j][i];
				return true;
			}
		}
	}
	return false;
}

/*******************************************************************
** Function: check_full()
** Description: checks if function is full
** Parameters: number of players, rows, and columns
** Pre-Conditions: parameters entered in command line
** Post-Conditions: None
*******************************************************************/ 
bool check_full(char** b, int row, int column){
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (b[i][j] != 'O' && b[i][j] != 'X') {
				return false;
			}
		}
	}

	print_board(b, row, column);
	cout << "Board is full, the game is a tie!" << endl;
	return true;
}

/*******************************************************************
** Function: delete_board()
** Description: deletes board
** Parameters: number of players, rows
** Pre-Conditions: parameters entered in command line
** Post-Conditions: None
*******************************************************************/ 
void delete_board(char** b, int rows) {
	for (int j = 0; j < rows; j++) {
		delete b[j];
	}
	delete b;
}

/*******************************************************************
** Function: play_again()
** Description: asks player(s) if they would like to play again, 
** reinitializes inputs to set up game
** Parameters: column, rows, players
** Pre-Conditions: initialized parameters
** Post-Conditions: None
*******************************************************************/ 
bool play_again(int* column, int* rows, int* players) {
	string choice;

	do {
		cout << "Would you like to play again? 1 = yes, 0 = no ";
		cin >> choice;
	} while (choice != "1" && choice != "0");

	if (choice == "1") {
		cout << "You have chosen to play again. " << endl;
		*players = get_players();
		*rows = get_rows();
		*column = get_column();
		return true;
	} else {
		cout << "Thank you for playing!" << endl;
		return false; // tells main function to quit
	}
}