/*
2016.8.22
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#10989
수 정렬하기 3
*/

#include <iostream>

using namespace std;

int main() {
	int n, input;
	int bucket[10001] = { 0, };
	cin.sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		bucket[input]++;
	}
	for (int i = 0; i < 10001; i++)
		if (bucket[i] != 0)
			for (int j = 0; j < bucket[i]; j++)
				printf("%d\n", i);
	return 0;
}