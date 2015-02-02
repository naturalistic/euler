#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool is_pdm(string n);
long get_max_pdm(string n, vector<char> r_digits);

int main() {
	string n;
	vector<char> r_digits {'9','8','7','6','5','4','3','2','1'};
	cout << "max pdm: " << get_max_pdm(n, r_digits) << endl;
	return 0;
}

bool is_pdm(string n) {
	for (int m_len = 1; m_len <= 4; m_len++) {
		int m = stoi(n.substr(0, m_len));
		string pot_n = n.substr(0, m_len);
		int i = 2;
		while(pot_n.compare(n.substr(0, pot_n.size())) == 0 && pot_n.size() < n.size()) {
			pot_n.append(to_string(m*i));
			i++;
		}
		if(pot_n.compare(n) == 0) {
			return true;
		} 
	}
	return false;
}

long get_max_pdm(string n, vector<char> r_digits) {

	if (r_digits.size() == 0) {
		if (is_pdm(n)) {
			return stol(n);
		} else {
			return 0;
		}			
	}
	long max_pdm = 0;
	for (vector<char>::iterator d = r_digits.begin(); d != r_digits.end(); ++d) {
		string n_copy(n);
		n_copy += *d;
		vector<char> r_digits_copy(r_digits);
		r_digits_copy.erase(remove(r_digits_copy.begin(),
			 r_digits_copy.end(), *d), r_digits_copy.end());
		long pdm = get_max_pdm(n_copy, r_digits_copy);
		if (pdm > max_pdm) {
			max_pdm = pdm;
		}
		
			
	}
	return max_pdm;	
}
