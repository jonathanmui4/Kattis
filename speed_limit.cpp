/**
* [author]: Jonathan Mui (28/11/2020)
* 
*/

#include <iostream>
using namespace std;

int calculate_distance(int n, int *speed, int *time)
{
	int dist = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			dist += speed[i] * time[i];
		}
		else {
			dist += speed[i] * (time[i] - time[i - 1]);
		}
	}
	return dist;
}

int main()
{
	int n = 0;
	cin >> n;
	do {
		if (n == -1) {
			return 1;
		}

		//Allocating memory for arrays
		int* speed = new int[n];
		int* time = new int[n];
		
		//read in values and store them in array
		for (int i = 0; i < n; i++) {
			cin >> speed[i] >> time[i];
		}
		
		int dist = calculate_distance(n, speed, time);
		cout << dist << " miles" << endl;
		
		//Freeing memory for arrays and clearing them by setting them to NULL
		//Clearing memory to prevent invalid memory reference
		delete [] time;
		time = NULL;
		delete [] speed;
		speed = NULL;
		
		cin >> n;	
	} while (n != -1);
}
