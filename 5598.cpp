#include <iostream>
#include <string>

using namespace std;

int main(){
	string input;
	cin.sync_with_stdio(false);
	cin >> input;
	for(int i=0;i<input.size();i++){
		if(input[i]>=68)
			input[i]-=3;
		else
			input[i]+=23;
	}
	cout <<input;
	return 0;
}