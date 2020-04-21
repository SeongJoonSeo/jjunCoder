/*
2016.9.4

BaekJoon Online Judge
Problem Solving
Seong Joon Seo (ID: jjunCoder)

Problem
#9661
돌 게임 7
*/

#include <iostream>

using namespace std;

int main(){
	long long n;
	cin.sync_with_stdio(false);
	cin >> n;
	if(n%5==0||(n-2)%5==0) cout << "CY";
	else cout << "SK";
	return 0;
}