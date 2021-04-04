#include <iostream>

using namespace std;

void print(int x, int y, int n);

int main() 
{
	int x;
	int y;
	int n;
	cin >> x >> y >> n;
	
	//Check for proper input
	if (x < 1 || y <= x || n < y || n > 100) {
		cout << "error" << endl;
		return -1;
	}
	else {
		print (x, y, n);
	}
	
}

void print(int x, int y, int n)
{
	for (int i = 1; i <= n; i++) {
		if (i % x == 0 && i % y == 0) {
			cout << "FizzBuzz" << endl;
		}
		else if (i % y == 0) {
			cout << "Buzz" << endl;
		}
		else if (i % x == 0) {
			cout << "Fizz" << endl;
		}
		else {
			cout << i << endl;
		}
	}
}


