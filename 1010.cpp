#include <iostream>
#include <vector>

using namespace std;

int main(){
	int t;
	cin.sync_with_stdio(false);
	cin >> t;
	//dp에 이항계수 모두 구해놓기
	int n, k;
    n=30,k=30;
    vector<vector<long long> > dp;
    dp.assign(n + 2, vector<long long>(n + 2, -1));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                dp[i][j] = 1;
            if (j != 0)
                dp[i + 1][j] = (dp[i][j - 1] + dp[i][j]);
        }
    }
    //문제 풀기
	for(int i=0;i<t;i++){
		int a,b;
		cin>>a>>b;
		printf("%lld\n",dp[b][a]);
	}
	return 0;
}
