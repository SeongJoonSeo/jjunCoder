#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
	int n,m;
	cin.sync_with_stdio(false);
	cin >> n>>m;
	//n: 사람의 수 m: 파티의 수
	vector<bool> know(n+1,false);
	int numOfTruth,who;
	cin>>numOfTruth;
	for(int i=0;i<numOfTruth;i++){
		cin>>who;
		know[who]=true;
	}
	
	return 0;
}



