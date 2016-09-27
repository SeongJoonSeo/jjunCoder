#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin.sync_with_stdio(false);
	cin >> n;
	vector<vector<long long> > dp;
	dp.assign(n+1,vector<long long>(2,0));
	//dp는 (n+1)x(2) 의 2차원 배열.
	//(i,0): n자리 이친수 중 끝이 0인 것들의 개수와
	//(i,1): 끝이 1인 것들의 개수
	dp[1][0] = 0;
	dp[1][1] = 1;
	for(int i=2;i<=n;i++){
		dp[i][0] = dp[i-1][0]+dp[i-1][1];
		dp[i][1] = dp[i-1][0];
	}
	cout << dp[n][0]+dp[n][1];
	return 0;
}
