#include <iostream>

using namespace std;

int main(){
	int n,origin;
	cin.sync_with_stdio(false);
	cin >> n;
	origin = n;
	int cycle=0;
	int temp;
	do{
		temp = (n%10+n/10)%10;
		temp = (n%10)*10 + temp;
		n = temp;
		cycle++;
	} while(temp!=origin);
	cout << cycle;
	return 0;
}