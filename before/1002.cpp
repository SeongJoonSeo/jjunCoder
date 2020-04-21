/*
2016.9.4

BaekJoon Online Judge
Problem Solving
Seong Joon Seo (ID: jjunCoder)

Problem
#1002
터렛
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int t;
	cin.sync_with_stdio(false);
	cin >> t;
	for(int i=0;i<t;i++){
		double x1,x2,y1,y2,r1,r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		double dist = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
		if(x1==x2&&y1==y2&&r1==r2) printf("%d\n",-1);
		else if(abs(r1-r2)<dist&&dist<r1+r2) printf("%d\n",2);
		else if(r1+r2<dist) printf("%d\n",0);
		else if(r1+r2==dist) printf("%d\n",1);
		else if(abs(r1-r2)==dist) printf("%d\n",1);
		else if(dist<abs(r1-r2)) printf("%d\n",0);

	}
	return 0;
}