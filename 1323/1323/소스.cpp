/*
2016.9.19
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1323
숫자 연결하기
*/

#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
	cin.sync_with_stdio(false);
	long long n, k, temp;
	int count = 1;
	string origin, str;
	set<long long> s;
	cin >> n >> k;
	origin = to_string(n);
	temp = n;
	while (1) {
		temp %= k; //나머지
		if (temp == 0) {
			printf("%d", count);
			return 0;
		}
		count++;
		str = to_string(temp); // 나머지를 스트링화
		str += origin; // 나머지 뒤에 원래 수를 붙인다.
		temp = stoll(str); // 그것을 정수화.
		if (s.find(temp) != s.end()) {
			//이미 존재하면 싸이클이 생긴다. 그렇다면 -1을 출력하고 종료.
			printf("-1");
			return 0;
		}
		else
			s.insert(temp); // set에 저장해 놓는다. 싸이클 탐지용.
	}
}