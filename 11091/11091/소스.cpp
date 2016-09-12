/*
2016.9.12
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#11091
알파벳 전부 쓰기
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n;
	string input,m;
	cin.sync_with_stdio(false);
	getline(cin, m);
	n = stoi(m);
	for (int i = 0; i < n; i++) {
		vector<bool> v(26, false);
		bool first = true;
		bool pan = true;
		getline(cin, input);
		for (int j = 0; j < input.size(); j++) {
			if (input[j] >= 65 && input[j] <= 90) {
				v[input[j] - 65] = true;
			}
			else if (input[j] >= 97 && input[j] <= 122) {
				v[input[j] - 97] = true;
			}
		}
		for (int j = 0; j < v.size(); j++) {
			if (first && !v[j]) {
				printf("missing ");
				printf("%c", j + 97);
				first = false;
				pan = false;
			}
			else if (!v[j])
				printf("%c", j+97);	
		}
		if (pan)
			printf("pangram\n");
		else
			printf("\n");
	}

	return 0;
}