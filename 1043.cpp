#include <iostream>
#include <vector>

using namespace std;

class person{
public:
	int id;
	bool know;
	vector<person*> v;
	person(){
		id=-1;
		know = false;
	}
	person(int i){
		id = i;		
		know = false;
	}
	void update(){
		if(know)
			for(int i=0;i<v.size();i++)
				v[i]->know=true;			
	}
};

int main(){
	int n,m;
	cin.sync_with_stdio(false);
	cin >> n>>m;
	//n: 사람의 수 m: 파티의 수
	int numOfTruth,who,numOfPeople;
	vector<person> people(n+1);
	for(int i=1;i<=n;i++)
		people[i] = person(i);	
	cin>>numOfTruth;
	for(int i=0;i<numOfTruth;i++){
		cin>>who;
		people[who].know = true;
	}
	vector<vector<int> > parties;
	for(int i=0;i<m;i++){
		cin>>numOfPeople;
		vector<int> party;
		
		for(int j=0;j<numOfPeople;j++){
			cin >> who;			
			party.push_back(who);
		}
		for(int j=0;j<numOfPeople;j++){
			for(int k=0;k!=j&&k<numOfPeople;k++){
				person* pt = &people[party[k]];
				people[j].v.push_back(pt);
			}			
		}
		parties.push_back(party);
	}
	
	for(int i=0;i<people.size();i++)
		people[i].update();
	int ret=m;
	for(int i=0;i<m;i++){
		for(int j=0;j<parties[i].size();j++){
			if(people[parties[i][j]].know){
				ret--;
				break;
			}
		}
	}
	cout << ret;
	return 0;
}



