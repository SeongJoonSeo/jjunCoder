/*
2016.9.4

BaekJoon Online Judge
Problem Solving
Seong Joon Seo (ID: jjunCoder)

Problem
#9660
돌 게임 6
*/

#include <iostream>

using namespace std;

int main(){
	long long n;
	cin.sync_with_stdio(false);
	cin >> n;
	if(n==1)
		cout << "SK";
	else if(n==2)
		cout << "CY";
	else{
		n-=2;
		if(n%7==0||n%7==5)
			cout << "CY";
		else
			cout << "SK";
	}
	return 0;
}