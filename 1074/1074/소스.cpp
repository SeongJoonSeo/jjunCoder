/*
2016.9.21
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1074
Z
*/

#include <iostream>
#include <cmath>

using namespace std;

int n,r,c;

//(r,c)에 몇번째로 방문하는지 반환.
int solve(int x, int y, int len, int N, int start) {
	if (N == 0) {
		//basis case
		return start;
	}
	int midX = x + len / 2;
	int midY = y + len / 2;
	int size = pow(2, N)*pow(2, N) / 4;

	if (r < midY && c < midX) {
		//1사분면
		return solve(x, y, len / 2, N - 1, start);
	}
	else if (r < midY && c >= midX) {
		//2사분면
		return solve(midX, y, len / 2, N - 1, start + size);
	}
	else if (r >= midY && c < midX) {
		//3사분면
		return solve(x, midY, len / 2, N - 1, start + size * 2);
	}
	else {
		//4사분면
		return solve(midX, midY, len / 2, N - 1, start + size * 3);
	}
}

int main() {
	cin.sync_with_stdio(false);	
	while (cin >> n >> r >> c)
		printf("%d\n", solve(0, 0, pow(2, n), n, 0));
	return 0;
}