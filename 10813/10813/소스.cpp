/*
2016.
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#10813
공 바꾸기
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m, a, b;
	cin.sync_with_stdio(false);
	cin >> n >> m;
	vector<int> v;
	v.push_back(-1);//0번 인덱스 없앤다.
	for (int i = 1; i <= n; i++)
		v.push_back(i);//1번 인덱스부터 1~n의 숫자를 넣는다.	
	for (int i = 0; i < m; i++) {
		//a번 바구니와 b번 바구니를 교환한다.
		cin >> a >> b;
		iter_swap(v.begin() + a, v.begin() + b);
	}
	for (auto it = v.begin()+1; it != v.end(); it++)
		printf("%d ", *it);
	return 0;
}