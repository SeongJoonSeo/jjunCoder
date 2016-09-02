/*
2016.9.2
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1309
동물원
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin.sync_with_stdio(false);
	cin >> n;
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	dp[1] = 3;
	for (int i = 2; i <= n; i++)
		dp[i] = (2 * dp[i - 1] + dp[i - 2]) % 9901;
	cout << dp[n];
	return 0;
}