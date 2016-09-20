#include <iostream>
#include <map>

using namespace std;

int main(){
	int n,p;
	cin.sync_with_stdio(false);
	cin >> n >> p;
	int temp = n*n%p;
	if(temp==n){
		cout << 1;
		return 0;
	}
	map<int,int> m;
	//값과 갯수
	int count = 1;
	m.insert(make_pair(n,count++));	
	while(m.find(temp)==m.end()){
		m.insert(make_pair(temp,count++));
		temp=temp*n%p;
	}
	auto it = m.find(temp);
	cout << m.size()-(*it).second + 1;
	return 0;
}