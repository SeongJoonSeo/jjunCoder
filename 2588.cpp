#include <iostream>

using namespace std;

int main(){
	int a,b,c;
	cin.sync_with_stdio(false);
	cin >> a >> b;
	c=b;
	cout << a*(b%10)<<endl;
	b/=10;
	cout << a*(b%10)<<endl;
	b/=10;
	cout << a*b<<endl;
	cout << a*c;
	return 0;
}