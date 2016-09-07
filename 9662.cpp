/*
2016.9.4

BaekJoon Online Judge
Problem Solving
Seong Joon Seo (ID: jjunCoder)

Problem
#9662
돌 게임 8
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
	int m, k, cost;
	cin.sync_with_stdio(false);
	cin >> m >> k;
	vector<int> dp(k+1,-1),costs;
	for(int i=0;i<k;i++){
		cin >> cost;
		costs.push_back(cost);
	}
	for(int i=1;i<=m;i++){
		
	}
	
	return 0;
}