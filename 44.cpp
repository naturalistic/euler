#include <iostream>
#include <math.h>

using namespace std;

bool is_pent(long pn);

int main() {
	long i = 2;
	while(true) {
		for(long j = 1; j < i; j++) {
			long pd = 3*(i*i - j*j) - i + j;
			if(pd % 2 != 0) {
				continue;
			}
			pd /= 2;
			if(!is_pent(pd)) {
				continue;
			}
			long ps = 3*(i*i + j*j) - i - j;
			if(ps % 2 != 0) {
				continue;
			} 	
			ps /= 2;
			if(is_pent(ps)) {
				cout << pd << endl;
				return 0;
			}
		}
		i++;
	}
}

bool is_pent(long pn) {
	if(pn < 1) {
		return false;
	}
	long n = (1 + (int)sqrt(1 + 24*pn))/6;
	return (n*(3*n -1))/2 == pn;
}
