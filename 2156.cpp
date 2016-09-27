#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> grape;
//dp[i]는 끝부터 i까지 마셔온 것들의 최대치.
vector<int> dp;

int solve(int here, int step){
	//가장 처음 불릴떄는 step이 0이고 0번째이다.
	//step=1이 되며 첫번째거 부터 먹는것과 두번째거 부터 먹는 것으로 시작할 수 있다.
	int next = here+1;
	
	//기저문
	if(here==grape.size()-1) return grape[here];
	if(here==grape.size()-2 && step==2) return grape[here];

	int& ret = dp[here];
	if(ret!=-1) return ret;

	//지금 연속으로 마신게 아니면 바로 다음것 또는 다다음걸 마셔도 된다.
	if(step==1)	ret = max(ret, solve(next, step+1)+grape[here]);
	
	//step이 1이 아니면 바로 다음건 못마시므로 다다음걸 먹어야 한다.
	//다다음걸 마실때는 연속해서 먹은 것이 아니므로 step 을 1로 초기화해준다.
	ret = max(ret, solve(next+1, 1)+grape[here]);

	//지금까지 마신것을 ret.
	return ret;
}

int main(){
	int n,amt;
	cin.sync_with_stdio(false);
	cin >> n;
	dp.assign(n+1,-1);
	grape.push_back(0);
	for(int i=0;i<n;i++){
		cin>>amt;
		grape.push_back(amt);
	}
	cout << solve(0,0);
	return 0;
}