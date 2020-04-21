/*
2016.9.11
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#2352
반도체 설계
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n,a;
	cin.sync_with_stdio(false);
	cin >> n;
	vector<int> connected(n);
	for(int i=0;i<n;i++){
		cin >> a;
		connected[i] = a;
	}
	return 0;
}