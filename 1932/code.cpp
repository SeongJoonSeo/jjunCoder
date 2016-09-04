/*
coded in Mac OS X
2016.8.29
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1932
숫자삼각형
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){	
	std::vector<std::vector<int> > dp,table;
	int n,input;
	cin.sync_with_stdio(false);
	cin >> n;	
	table.assign(n,vector<int>(n,0));
	dp.assign(n,vector<int>(n,0));
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			cin >> input;
			table[i-1][j] = input;
		}
	}
	dp[0][0] = table[0][0];
	for(int i=1;i<n;i++){
		for(int j=0;j<i+1;j++){
			if(j==0)
				dp[i][j] = table[i][j] + dp[i-1][j];
			else if(j==i)
				dp[i][j] = table[i][j] + dp[i-1][j-1];
			else
				dp[i][j] = table[i][j] + max(dp[i-1][j-1],dp[i-1][j]);
		}
	}
	int maxi = -1;
	for(int i=0;i<n;i++)
		maxi = max(dp[n-1][i],maxi);
	cout << maxi;
	return 0;
}



