#include <iostream>
#include <string>

using namespace std;

void swap(int *cups, int pos1, int pos2)
{
	int temp = cups[pos1];
	cups[pos1] = cups[pos2];
	cups[pos2] = temp;
}

int find_ball(int *cups)
{
	for (int i = 0; i < 3; i += 1) {
		if (cups[i] == 1) {
			return i;
		}
	}
	return -1;
}

int main()
{
	int cups [3]  = {1, 0, 0};
	string moves;
	getline(cin, moves);
	int i = 0;
	while (moves[i] != 0) {
		if (moves[i] == 'A') {
			swap(cups, 0, 1);
		}
		else if (moves[i] == 'B') {
			swap(cups, 1, 2);
		}
		else {
			swap(cups, 0, 2);
		}
		i += 1;
	}
	int final = find_ball(cups) + 1;
	cout << final;	
}
