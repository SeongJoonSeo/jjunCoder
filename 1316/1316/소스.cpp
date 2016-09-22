/*
2016.9.22
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1316
그룹 단어 체커
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {	
	int n,ret;
	cin.sync_with_stdio(false);
	cin >> n;
	ret = n;
	for (int i = 0; i < n; i++) {
		vector<bool> alpha(26, false);		
		string input;
		cin >> input;
		for (int j = 0; j < input.size(); j++) {
			if (alpha[input[j] - 'a']) {
				ret--;
				break;
			}				
			alpha[input[j] - 'a'] = true;
			while (input[j + 1] == input[j])
				j++;
		}
	}
	cout << ret;
	return 0;
}