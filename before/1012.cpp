//미완성코드

#include <iostream>
#include <vector>

using namespace std;

int m,n,k;
vector<vector<int> > board;
vector<pair<int,int> > retuce;

void dfs(pair<int,int> p){
	int y=p.second, x=p.first;
	if(board[y][x]==2 || board[y][x]==0)
		return;	
	board[y][x]=2;
	if(y+1<n && board[y+1][x]==1)
		dfs(make_pair(x,y+1));
	
	if(x+1<m && board[y][x+1]==1)
		dfs(make_pair(x+1,y));
	
	if(x-1>=0 && board[y][x-1]==1)
		dfs(make_pair(x-1,y));
	
	if(y-1>=0 && board[y-1][x]==1)
		dfs(make_pair(x,y-1));
	
}

int main(){
	int t;
	cin.sync_with_stdio(false);
	cin >> t;
	for(int i=0;i<t;i++){		
		cin>>m>>n>>k;
		int group=0;
		board.assign(n,vector<int>(m,0));
		for(int j=0;j<k;j++){
			int x,y;
			cin>>x>>y;
			retuce.push_back(make_pair(x,y));
			board[y][x]=1;
		}
		for(int j=0;j<retuce.size();j++){
			int posX = retuce[j].first, posY = retuce[j].second;
			if(board[posY][posX]==1){
				//상추가 있고 아직 방문하지 않은 그룹.
				group++;
				dfs(make_pair(posX,posY));
			}
		}
		printf("%d\n",group);
		board.clear();
		retuce.clear();
	}
	return 0;
}