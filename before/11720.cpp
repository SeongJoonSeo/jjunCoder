#include <iostream>
#include <string>

using namespace std;

int main(){
	int n,sum=0;
	string input;
	cin.sync_with_stdio(false);
	cin >> n;
	cin>>input;
	for(int i=0;i<n;i++){
		sum+=input[i]-48;
	}
	cout << sum;
	return 0;
}