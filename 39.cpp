// Problem 39
// Daniel Roberts

#include <iostream>
using namespace std;

int get_sol(int p);
int get_max_sol(int p_limit);

int main() {
	cout << get_max_sol(1000) << endl;	
}

int get_sol(int p) {
	int sol = 0;
        for (int a = 1; a <= p/4; a++) { // try every a 
                int n = p*p - 2*a*p;
                int d =  2*p - 2*a;
                if (n % d == 0) { // if b = n / d is int then have sol
                        ++sol;
                }
        }
	return sol;
}

int get_max_sol(int p_limit) {
	int max_sol = 0;
	int max_p = 1;
	for (int p = 1; p <= p_limit; p++) {
		int sol = get_sol(p);
		if (sol > max_sol) {
			max_sol = sol;
			max_p = p;
		}
	}	
	return max_p;
}
