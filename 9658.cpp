/*
2016.9.4

BaekJoon Online Judge
Problem Solving
Seong Joon Seo (ID: jjunCoder)

Problem
#9658
돌 게임 4
*/

#include <iostream>

using namespace std;

int main(){
	int n;
	cin.sync_with_stdio(false);
	cin >> n;
	int dp[1001];
	//1 : sk, 2: cy
	dp[1]=2; dp[2]=1; dp[3]=2; dp[4]=1;
	for(int i=5;i<=1000;i++){
		if(dp[i-1]==2 || dp[i-3]==2 || dp[i-4]==2)
			dp[i] = 1;
		else
			dp[i] = 2;
	}
	if(dp[n]==1)
		cout << "SK";
	else
		cout << "CY";
	return 0;
}