/*
2016.9.4

BaekJoon Online Judge
Problem Solving
Seong Joon Seo (ID: jjunCoder)

Problem
#9656
돌 게임 2
*/

#include <iostream>

using namespace std;

int main(){
	int n;
	cin.sync_with_stdio(false);
	cin >> n;
	if(n%2==1)
		cout << "CY";
	else
		cout << "SK";
	return 0;
}