#include <iostream>

using namespace std;

int main(){
	int a,b,c;
	int A=300,B=60,C=10;
	int t;
	cin.sync_with_stdio(false);
	cin >> t;
	a = t/A;
	t-=a*A;
	b = t/B;
	t-=b*B;
	c = t/C;
	t-=c*C;
	if(t!=0)
		cout << -1;
	else
		printf("%d %d %d",a,b,c);
	return 0;
}