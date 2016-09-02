/*
2016.9.2
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#9507
Generations of Tribbles
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t, n;
	cin.sync_with_stdio(false);
	cin >> t;
	vector<long long> dp(68, 0);
	dp[0] = dp[1] = 1;
	dp[2] = 2; dp[3] = 4;
	for (int i = 4; i < 68; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];	
	for (int i = 0; i < t; i++) {
		cin >> n;
		printf("%lld\n", dp[n]);
	}		
	return 0;
}