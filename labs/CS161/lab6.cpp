#include <iostream>
#include <sys/time.h>
#include <cstdlib>

using namespace std;

int fib_recurs(int n);
int fib_iter(int n);

int main() {

	typedef struct timeval time;
	time stop, start;
	gettimeofday(&start, NULL);

	int n;

	cout << "Enter an integer >= 0: ";
	cin >> n;

	cout << "Fib num: " << fib_recurs(n) << endl;

	//Time your iterative or recursive function here.
	gettimeofday(&stop, NULL);
	if(stop.tv_sec > start.tv_sec)
		cout << "Seconds: " << stop.tv_sec-start.tv_sec << endl;
	else
		cout << "Micro: " << stop.tv_usec-start.tv_usec << endl;
	
	return 0;
} 

int fib_iter(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	int num1 = 0;
	int num2 = 1;

	for (int i = 2; i <= n; i++) {
		int temp;

		temp = num1 + num2;
		num1 = num2;
		num2 = temp;
	}

	return num2;


}

int fib_recurs(int n) {


	if (n == 0) {
		return 0;
	} else if (n == 1) {
		return 1;
	} else {
		return (fib_recurs(n - 1) + fib_recurs(n - 2));
	}

}


