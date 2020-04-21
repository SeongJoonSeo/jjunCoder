#include <iostream>

using namespace std;

int main(){
	int t;
	cin.sync_with_stdio(false);
	cin >> t;
	for(int i=0;i<t;i++){
		int a,b;
		cin>>a>>b;
		printf("%d\n",a+b);
	}
	return 0;
}