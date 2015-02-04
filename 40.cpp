// Euler Problem 40

#include <iostream>
#include <string>
using namespace std;

int main() {
	int value = 1;
	int mult_char = 1;
	int char_count = 1;
	int n = 1;
	while (char_count <= 1000000) {
		string n_str = to_string(n);
		for (string::iterator it = n_str.begin(); it < n_str.end(); it++) {
			int digit = (int)*it - '0';
			if (char_count == mult_char) {
				value *= digit;			
				mult_char *= 10;
			}
			char_count++;
		}
		n++;
	}	
	cout << value << endl;
}
