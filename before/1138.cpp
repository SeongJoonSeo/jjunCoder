#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n,h;
	cin.sync_with_stdio(false);
	cin >> n;
	vector<int> v;
	v.push_back(-1);
	for(int i=0;i<n;i++){
		cin>>h;
		v.push_back(h);
	}
	return 0;
}