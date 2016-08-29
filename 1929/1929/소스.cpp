/*
2016.8.22
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1929
소수 구하기
(에라토스테네스의 체)
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	vector<int> prime;
	vector<bool> isPrime(n + 1);
	fill(isPrime.begin(), isPrime.end(), true);
	isPrime[0] = isPrime[1] = false;
	//에라토스테네스의 체 부분 (개선 전)
	/*for (int i = 2; i < n + 1; i++) {
		if (isPrime[i])
			prime.push_back(i);
		for (int j = i*2; j < n + 1; j += i)
			isPrime[j] = false;
	}*/
	//에라토스테네스의 체 부분 (개선 후)
	//2를 제외한 짝수를 일단 모두 걸러낸다.
	for (int i = 4; i < n + 1; i+=2)
		isPrime[i] = false;
	for (int i = 3; i < n + 1; i++) {
		if (isPrime[i]) prime.push_back(i);
		//j는 i*i에서 시작하여도 된다. 또한 j가 i*2만큼 증가한다.
		for (int j = i * i; j < n + 1; j += i*2)
			isPrime[j] = false;
	}
	for (int i = 0; i < prime.size(); i++) {
		if (prime[i] >= m && prime[i] <= n)
			printf("%d\n", prime[i]);
	}
	return 0;
}