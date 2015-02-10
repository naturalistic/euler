#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

int get_max_pp(string &n_str, vector<int> &digits, int len); 
bool is_prime(long n);
bool is_pan_digital(string &n_str);

int main() {
	for (int l = 9; l >= 1; l--) {
		string n_str;
		vector<int> digits { 9,8,7,6,5,4,3,2,1 };
		int max_pp = get_max_pp(n_str, digits, l);
		if(max_pp != 0) {
			cout << max_pp << endl;
			return 0;
		}		
	}
	cout << "No pp primes found..." << endl;
}

int get_max_pp(string &n_str, vector<int> &digits, int len) {
	if(n_str.size() == len) {
		long n = stol(n_str);
		if (is_pan_digital(n_str) && is_prime(n)) {
			return n; 
		}
		return 0;
	}
	for (int digit : digits) {
		string n_str_c(n_str);
		n_str_c.append(to_string(digit));
		vector<int> digits_c(digits);
		digits_c.erase(remove(digits_c.begin(), digits_c.end(), digit), digits_c.end());
		int pp = get_max_pp(n_str_c, digits_c, len);
		if (pp != 0) {
			return pp;
		}
	}
	return 0;
}

bool is_pan_digital(string &n_str) {
	int s = n_str.size();
	for(char c : n_str) {
		if (c - '0' > s) {
			return false;
		}	
	}	
	return true;
}


bool is_prime(long n) {
	if (n % 2 == 0) {
		return false;
	}
	long limit = (long)sqrt(n);
	for (long i = 3; i <= limit; i+=2) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
