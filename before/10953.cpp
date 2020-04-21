#include <iostream>
#include <string>

using namespace std;

int main(){
	int t;
	cin.sync_with_stdio(false);
	cin >> t;
	for(int i=0;i<t;i++){
		string input;
		cin>>input;
		int a=input[0]-48;
		int b=input[2]-48;
		printf("%d\n",a+b);
	}
	return 0;
}