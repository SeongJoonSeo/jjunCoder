#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	string input;
	vector<string> board;
	for(int i=0;i<8;i++){
		cin>>input;
		board.push_back(input);
	}
	int cnt=0;
	//체스판의 첫칸은 하얀칸이다.
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(i%2==0 && j%2==0){
				//하얀 칸이다.
				if(board[i][j]=='F')
					cnt++;
			}
			else if(i%2!=0 && j%2!=0){
				//하얀 칸이다.	
				if(board[i][j]=='F')
					cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}