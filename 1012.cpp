//미완성코드

#include <iostream>
#include <vector>

using namespace std;

int m,n,k,group;
vector<vector<int> > board;
vector<pair<int,int> > retuce;

int main(){
	int t;
	cin.sync_with_stdio(false);
	cin >> t;
	for(int i=0;i<t;i++){		
		cin>>m>>n>>k;		
		group=0;
		vector<vector<bool> > visited;
		visited.assign(n,vector<bool>(m,false));
		board.assign(n,vector<int>(m,0));
		for(int j=0;j<k;j++){
			int x,y;
			cin>>x>>y;
			retuce.push_back(make_pair(x,y));
			board[y][x]=1;
		}
		for(int j=0;j<retuce.size();j++){
			if(board[retuce[j].second][retuce[j].first]==1){
				//상추가 있고 아직 방문하지 않은 그룹.
			}
		}
	}
	return 0;
}