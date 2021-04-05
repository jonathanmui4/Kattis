#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, set_no = 1; //No of strings, set number
	string tmp;
	cin >> n;
	while (n != 0) {
		vector <string> v_string;
		for (int i = 0; i < n; i++) { //Create a dynamic array of strings and adding input strings in
			cin >> tmp;
			v_string.push_back(tmp);
		}
		cout << "SET " << set_no << "\n";
		for (int i = 0; i < n; i++) {
			if (i%2 == 0) { //Even indexes printed first
				cout << v_string[i] << "\n";
			}
		}
		for (int i = v_string.size() - 1; i >= 0; i--) { //Odd indexes printed later
			if (i%2 != 0) {
				cout << v_string[i] << "\n";
			}
		}
		set_no++;
		cin >> n;
	}
}