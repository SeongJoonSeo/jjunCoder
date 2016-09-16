#include <iostream>

using namespace std;

int main(){
	int x;
	cin.sync_with_stdio(false);
	cin >> x;
	int node = 64,count=0;
	while(node != x){
		if(node>x){
			node /= 2;
		}
		else{
			x-=node;
			count++;
		}
	}
	cout << count+1;
	return 0;
}