#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int expand_is_t_vector(vector<bool> &is_t_vector, int tn, int n);
int get_word_value(string word);

int main() {
	vector<bool> is_t_vector;
	int tn = 1;
	string word;
	ifstream s("words.txt");
	int sum = 0;
	while(getline(s, word, ',')) {
		if(word.size() > 2) {
			int word_value = get_word_value(word.substr(1,word.rfind('"')-1));
			tn = expand_is_t_vector(is_t_vector, tn, word_value);
			if(is_t_vector[word_value]) {
				sum++;
			}
		}
	}
	cout << sum << endl;
	return 0;
}	

int expand_is_t_vector(vector<bool> &is_t_vector, int tn, int n) {
	int max_v = is_t_vector.size();
	int next_t = (tn*(tn+1))/2;	
	while(max_v <= n) {
		if(max_v == next_t) {
			++tn;
			next_t = (tn*(tn+1))/2;
			is_t_vector.push_back(true);
		} else {
			is_t_vector.push_back(false);
		}
		++max_v;
	}
	return tn;	
}

int get_word_value(string word) {
	int value = 0;
	for(char c : word) {
		value += c - 'A' + 1;	
	}
	return value;
}
