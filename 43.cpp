// Euler 43

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_div(string &n_str);
long sum_dpp(string &n_str, vector<int> &digits);

int main() {
	string n_str = "";
	vector<int> digits {0,1,2,3,4,5,6,7,8,9};
	cout << sum_dpp(n_str, digits) << endl;
	return 0;
}

long sum_dpp(string &n_str, vector<int> &digits) {
	if(digits.size() == 0) { // have our 0-9 pan digital...
		if(is_div(n_str)) {
			return stol(n_str);
		} else {
			return 0;
		}
	}
	long sum = 0;
	for (int digit : digits) {
		if(digit == 0 && n_str.size() == 0) { // don't count 0xxxxxxxxx numbers
			continue;
		}
		string n_str_c(n_str);
		n_str_c.append(to_string(digit));
		vector<int> digits_c(digits);
		digits_c.erase(remove(digits_c.begin(), digits_c.end(), digit), digits_c.end());
		sum += sum_dpp(n_str_c, digits_c);	
	}
	return sum;
}

bool is_div(string &n_str) {	

	if(stoi(n_str.substr(1,3)) % 2 != 0) {
		return false;
	}
	if(stoi(n_str.substr(2,3)) % 3 != 0) {
		return false;
	}
	if(stoi(n_str.substr(3,3)) % 5 != 0) {
		return false;
	}
	if(stoi(n_str.substr(4,3)) % 7 != 0) {
		return false;
	}
	if(stoi(n_str.substr(5,3)) % 11 != 0) {
		return false;
	}
	if(stoi(n_str.substr(6,3)) % 13 != 0) {
		return false;
	}
	if(stoi(n_str.substr(7,3)) % 17 != 0) {
		return false;
	}
	return true;
}
