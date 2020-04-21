#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	int n;
	cin.sync_with_stdio(false);
	cin >> n;
	vector<string> v;
	string input;
	for(int i=0;i<n;i++){		
		cin>>input;
		v.push_back(input);
	}
	input = v[0];
	for(int i=1;i<n;i++){
		for(int j=0;j<input.size();j++){
			if(input[j]!=v[i][j])
				input[j]='?';
		}
	}
	cout << input;
	return 0;
}