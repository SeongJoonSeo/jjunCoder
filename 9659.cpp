/*
2016.9.4

BaekJoon Online Judge
Problem Solving
Seong Joon Seo (ID: jjunCoder)

Problem
#9659
돌 게임 5
*/

#include <iostream>

using namespace std;

int main(){
	long long n;
	cin.sync_with_stdio(false);
	cin >> n;
	if(n%2==1)
		cout << "SK";
	else
		cout << "CY";
	return 0;
}