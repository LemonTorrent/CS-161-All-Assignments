/******************************************************************************
 ** Program Filename: sales_income.cpp
 ** Author: Nicole Yarbrough
 ** Date: 1/18/2020
 ** Description: This program calculates the gross income, tax paid, and net 
 	income of a car salesman.
 ** Input: Monthly salary, months worked, car cost, cars sold, misconducts 
 	involved in, tax year, and state of residency.
 ** Output: Gross income, taxes paid, and net income.
 *****************************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

/******************************************************************************
 ** Function: calculate_gross()
 ** Description: Calculates the gross salary of a car salesman.
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: gross_income
 *****************************************************************************/

int calculate_gross () {

	srand(time(NULL));

	int monthly_salary;
	short months_worked;
	float car_cost;
	int cars_sold;
	int misconducts;
	float gross_income;

	/* Takes monthly salary as input */
	cout << "What is the monthly salary to the nearest dollar? ";
	cin >> monthly_salary;
	if (monthly_salary < 0) {
		while (monthly_salary < 0) {
			cout << "Please enter a value >= 0. " << endl;
			cin >> monthly_salary;
			if (monthly_salary >=  0) {
				break;
			}
		}
	}

	/* Takes months worked as input */
	while ((months_worked < 0) || (months_worked > 12)) {
		cout << "How many months did the salesman work? ";
		cin >> months_worked;
		if ((months_worked < 0) || (months_worked > 12))
			cout << "Please enter a value between 0 and 12 inclusive." << endl;
		else
			break;
		}

	/* Takes cost per car as input */
	cout << "What is the cost per car for the car dealership? ";
	cin >> car_cost;
	if (car_cost <= 0) {
		while (car_cost < 0) {
			cout << "Please enter a value > 0. " << endl;
			cin >> car_cost;
			if (car_cost > 0) {
				break;
			}
		}
	}

	/* Takes cars sold as input */
	cout << "How many cars did the dealership sell? ";
	cin >> cars_sold;
	if (cars_sold <= 0) {
		while (cars_sold < 0) {
			cout << "Please enter a value >= 0. " << endl;
			cin >> cars_sold;
			if (cars_sold >= 0) {
				break;
			}
		}
	}

	/* Takes number of misconducts as input */
	cout << "How many misconducts was the salesman involved in? ";
	cin >> misconducts;
	if (misconducts < 0) {
		while (misconducts < 0) {
			cout << "Please enter a value >= 0. " << endl;
			cin >> misconducts;
			if (misconducts >= 0) {
				break;
			}
		}
	}

	/* Calculates price per car */
	float price = car_cost * ((rand() % 6 + 5) * .01 + 1);

	/* Calculates profit per car sold */
	float profit = price - car_cost;

	/* Calculates gross salary */
	float salary = monthly_salary * months_worked + (.02 * cars_sold * profit);
	gross_income = salary - (100 * pow(2, misconducts));

	return gross_income;
}


/******************************************************************************
 ** Function: tax()
 ** Description: This function calculates the taxes that the car salesman will
 	pay.
 ** Parameters: salary
 ** Pre-Conditions: None
 ** Post-Conditions: Tax
 *****************************************************************************/

int tax(int salary) {

	float tax;

	char state = 'Z';
	short year = 0;
	
	/* Takes tax year as input */
	while ((year != 2016) and (year != 2017)) {
		cout << "Are taxes being calculated for 2016 or 2017? ";
		cin >> year;
	}
	
	/* Takes state of residence as input */
	while ((state != 'A') and (state != 'B') and (state != 'C')
	and (state != 'a') and (state != 'b') and (state != 'c')) {
		cout << "Did the salesman live in state A, B, or C? ";
		cin >> state;
	}

	/* Calculates tax based off of year and state */
	if (salary <= 0) {
		tax = 0;
	} else {
		if (year == 2016) {
			if (state == 'A' or state == 'a') {
				tax = .06 * salary;
			} else if (state == 'B' or state == 'b') {
				if (salary <= 2000) {
					tax = 0;
				} else if (salary <= 10000) {
					tax = 100;
				} else {
					tax = (salary - 10000) * .1 + 200;
				}
			} else {
				if (salary <= 3500) {
					tax = salary * .05;
				} else if (salary <= 9000) {
					tax = (salary - 3500) * .07 + 175;
				} else if (salary <= 125000) {
					tax = (salary - 9000) * .09 + 560;
				} else {
					tax = (salary - 125000) * .099 + 11000;
				}
			}
		} else {
			if (state == 'A' or state == 'a') {
				tax = salary * .08;
			} else if (state == 'B' or state == 'b') {
				if (salary <= 2500) {
					tax = 0;
				} else if (salary <= 10000) {
					tax = 115;
				} else {
					tax = (salary - 10000) * .105 + 115;
				}
			} else {
				if (salary <= 3450) {
					tax = salary * .05;
				} else if (salary <= 8700) {
					tax = (salary - 3450) * .07 + 172.5;
				} else if (salary <= 125000) {
					tax = (salary - 8700) * .09 + 540;
				} else {
					tax = (salary - 125000) * .099 + 1107;
				}
			}
		}
	}
	return tax;
}

/******************************************************************************
 ** Function: calculate_net()
 ** Description: Calculates the net salary of the car salesman.
 ** Parameters: gross_salary, tax_paid
 ** Pre-Conditions: None
 ** Post-Conditions: net_salary
 *****************************************************************************/

int calculate_net(int gross_salary, int tax_paid) {

	int net_salary = gross_salary - tax_paid;
	
	return net_salary;
}

/******************************************************************************
 ** Function: main()
 ** Description: The main function that creates variables for gross salary,
 	net salary, and taxes paid as well as outputs the calculations to the
	screen.
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: Gross salary, taxes, and net salary are outputted to the
 	screen.
 *****************************************************************************/

int main() {

	int gross_salary;
	int net_salary;
	int tax_paid;

	gross_salary = calculate_gross();
	tax_paid = tax(gross_salary);
	net_salary = calculate_net(gross_salary, tax_paid);

	/* Outputs desired calculations */
	cout << "Gross salary: " << gross_salary << endl;
	cout << "Taxes: " << tax_paid << endl;
	cout << "Net salary: " << net_salary << endl;

	return 0;
}