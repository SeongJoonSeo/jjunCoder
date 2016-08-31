/*
2016.8.29
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#11401
이항 계수 3
나머지 연산의 곱셈 역원 개념,
페르마의 소정리 개념을 적용시킨다.
아래 코드는 https://www.acmicpc.net/blog/view/29 의 코드이다.
*/

#include <iostream>
using namespace std;
long long mul(long long x, long long y, long long p) {
	long long ans = 1;
	while (y > 0) {
		if (y % 2 != 0) {
			ans *= x;
			ans %= p;
		}
		x *= x;
		x %= p;
		y /= 2;
	}
	return ans;
}
int main() {
	long long n, r, p;
	cin >> n >> r;
	p = 1000000007LL;
	long long ans = 1;
	long long t1 = 1;
	long long t2 = 1;
	for (long long i = 1; i <= n; i++) {
		t1 *= i;
		t1 %= p;
	}
	for (long long i = 1; i <= r; i++) {
		t2 *= i;
		t2 %= p;
	}
	for (long long i = 1; i <= n - r; i++) {
		t2 *= i;
		t2 %= p;
	}
	long long t3 = mul(t2, p - 2, p);
	t3 %= p;
	ans = t1*t3;
	ans %= p;
	cout << ans << '\n';
	return 0;
}