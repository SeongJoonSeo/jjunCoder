/*
2016.9.20
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#2869
달팽이는 올라가고 싶다
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double a, b, v;
	//v미터인 나무 막대
	//낮에 a미터 올라가고 밤에 b미터 미끄러진다.
	//모두 올라가는데 며칠 걸리냐
	cin.sync_with_stdio(false);
	cin >> a >> b >> v;
	int x = ceil((v - a) / (a - b));
	cout << x + 1;
	return 0;
}