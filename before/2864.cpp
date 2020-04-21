#include <iostream>
#include <string>

using namespace std;

int main(){
	string x,y;
	cin.sync_with_stdio(false);
	cin >> x >> y;
	string xMin,yMin,xMax,yMax;
	int mini,maxi;
	for(int i=0;i<x.size();i++){
		if(x[i]=='5' || x[i]=='6'){
			xMin[i]='5';
			xMax[i]='6';			
		}
		else{
			xMin[i]=x[i];
			xMax[i]=x[i];
		}
	}
	for(int i=0;i<y.size();i++){
		if(y[i]=='5' || y[i]=='6'){
			yMin[i]='5';
			yMax[i]='6';			
		}
		else{
			yMin[i]=y[i];
			yMax[i]=y[i];
		}
	}
	mini = atoi(xMin.c_str())+atoi(yMin.c_str());
	maxi = atoi(xMax.c_str())+atoi(yMax.c_str());
	cout << mini << " " << maxi;
	return 0;
}