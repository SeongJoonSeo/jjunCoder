#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int n,a;
	cin.sync_with_stdio(false);
	cin >> n;
	vector<int> v;
	for(int i=0;i<n;i++){
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	cout << v[0]*v[n-1];
	return 0;
}