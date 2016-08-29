/*
2016.8.22
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#8958
OXÄûÁî
*/

#include <iostream>
#include <string>

using namespace std;

void solve(string quiz) {
	int score = 0, ret = 0;
	for (int i = 0; i < quiz.size(); i++) {
		if (quiz[i] == 'X')
			score = 0;
		else {
			score++;
			ret += score;
		}
	}
	cout << ret << endl;
}

int main() {
	int n;
	cin >> n;
	string quiz;	
	for (int i = 0; i < n; i++) {
		cin >> quiz;
		solve(quiz);
	}
	return 0;
}