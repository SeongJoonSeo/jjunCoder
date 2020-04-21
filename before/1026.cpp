#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n,cost;
	cin.sync_with_stdio(false);
	cin >> n;
	vector<int> a,b;
	for(int i=0;i<n;i++){
		cin>>cost;
		a.push_back(cost);
	}
	sort(a.begin(),a.end());
	for(int i=0;i<n;i++){
		cin>>cost;
		b.push_back(cost);
	}
	sort(b.begin(),b.end());
	reverse(b.begin(),b.end());
	int sum=0;
	for(int i=0;i<n;i++){
		sum += a[i]*b[i];
	}
	cout << sum;
	return 0;
}