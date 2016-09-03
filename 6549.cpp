/*
2016.9.3
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#6549
히스토그램에서 가장 큰 직사각형
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> histogram;

long long solve(int start, int end) {
	if (start == end - 1) return histogram[start];
	int mid = (end + start) / 2;
	long long maxi = solve(start,mid);
	maxi = max(maxi, solve(mid, end));
	int size = end - start;
	int left, right;
	long long k;
	if (size % 2 == 0) {
		left = mid - 1; right = mid;
	}
	else {
		histogram[mid + 1] > histogram[mid - 1] ? right = mid + 1 : right = mid;
		left = right - 1;
	}
	k = min(histogram[left--], histogram[right++]) * 2;
}

int main() {
	int n, input;
	cin.sync_with_stdio(false);
	cin >> n;
	//직사각형의 갯수 n
	while (n != 0) {
		for (int i = 0; i < n; i++) {
			cin >> input;
			histogram.push_back(input);
		}
		printf("%lld\n",solve(0, n));
		cin >> n;
		histogram.clear();
	}
	return 0;
}
