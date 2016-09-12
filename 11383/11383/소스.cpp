/*
2016.9.12
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#11383
뚊
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n, m;
	vector<string> v,v2;
	string input;
	cin.sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> input;
		v.push_back(input);		
	}
	for (int i = 0; i < n; i++) {
		cin >> input;
		v2.push_back(input);
	}
	bool isEyfa = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			if ((v[i][j] != v2[i][j*2]) || (v[i][j] != v2[i][j*2 + 1])) {
				isEyfa = false;
				break;
			}
		}
	}
	if (isEyfa)
		cout << "Eyfa";
	else
		cout << "Not Eyfa";
	return 0;
}