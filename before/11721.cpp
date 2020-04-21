#include <iostream>
#include <string>

using namespace std;

int main(){
	string input;	
	cin.sync_with_stdio(false);
	cin >> input;
	for(int i=0;i<input.size();){
		for(int j=0;j<10&&i<input.size();j++){
			printf("%c",input[i++]);
		}
		printf("\n");
	}
	return 0;
}