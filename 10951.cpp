#include <iostream>

using namespace std;

int main(){
	int a,b;
	cin.sync_with_stdio(false);	
	cin>>a>>b;
	while(!cin.eof()){		
		printf("%d\n",a+b);
		cin>>a>>b;
	}
	return 0;
}