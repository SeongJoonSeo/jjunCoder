/*
2016.9.13
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#11094
꿍 가라사대
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	string input, m, simon = "Simon says";
	cin.sync_with_stdio(false);
	getline(cin, m);
	n = stoi(m);
	for (int i = 0; i < n; i++) {
		getline(cin, input);
		size_t found = input.find(simon);
		if (found != string::npos) {
			//string::npos 는 find가 실패했을때 반환되는 값이다.
			for (int j = found + 10; j < input.size(); j++) {
				printf("%c", input[j]);
			}
			printf("\n");
		}		
	}
	return 0;
}