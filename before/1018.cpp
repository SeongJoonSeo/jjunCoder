//1018

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int main(){
	int n,m;
	cin.sync_with_stdio(false);
	cin >> n>>m;
	string input;
	vector<vector<int> > board1,board2,v;
	board1.assign(8, vector<int>(8,0));
	board2.assign(8, vector<int>(8,0));
	v.assign(n,vector<int>(m,0));

	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(i%2==0 && j%2==0)
				board1[i][j] = 0;
			else if(i%2==0 && j%2!=0)
				board1[i][j] = 1;
			else if(i%2!=0 && j%2==0)
				board1[i][j] = 1;
			else
				board1[i][j] = 0;

			if(i%2==0 && j%2==0)
				board2[i][j] = 1;
			else if(i%2==0 && j%2!=0)
				board2[i][j] = 0;
			else if(i%2!=0 && j%2==0)
				board2[i][j] = 0;
			else
				board2[i][j] = 1;
		}
	}
	for(int i=0;i<n;i++){
		cin>>input;
		for(int j=0;j<m;j++){
			if(input[j]=='W')
				v[i][j] = 0;
			else
				v[i][j] = 1;
		}
	}

	int min1=INF;
	for(int i=0;i+8<=n;i++){
		for(int j=0;j+8<=m;j++){
			int matching1 = 0, matching2 = 0;			
			for(int a=0;a<8;a++){
				for(int b=0;b<8;b++){
					if(board1[a][b]!=v[i+a][j+b])
						matching1++;
					if(board2[a][b]!=v[i+a][j+b])
						matching2++;
				}
			}			
			matching1 = min(matching1,matching2);
			min1 = min(min1,matching1);
		}
	}
	cout << min1;
	return 0;
}




