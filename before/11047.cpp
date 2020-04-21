/*
2016.9.6
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#11047
동전 0
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n,k,c,ret=0;
	cin.sync_with_stdio(false);
	cin >> n >> k;
	vector<int> coins;
	for(int i=0;i<n;i++){
		cin >> c;
		coins.push_back(c);
	}
	for(int i=n-1;i>=0;i--){
		if(k>=coins[i]){
			ret += k/coins[i];
		}
	}
	return 0;
}