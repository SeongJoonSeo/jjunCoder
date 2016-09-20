/*
2016.9.20
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#5597
과제 안 내신 분..?
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<bool> v;
	v.push_back(false);
	for (int i = 0; i < 30; i++) {
		v.push_back(false);
	}
	int n;
	for (int i = 0; i < 28; i++) {
		cin >> n;
		v[n] = true;
	}
	
	for (int i = 1; i <= 30; i++) {
		if (!v[i])
			cout << i << endl;
	}
	return 0;
}