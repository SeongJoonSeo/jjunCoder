/*
2016.9.22
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1275
커피숍2
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, q, k;
	cin.sync_with_stdio(false);
	cin >> n >> q;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> k;
		v.push_back(k);
	}
	vector<long long> psum(n,0);
	vector<pair<int, int> > diff;
	psum[0] = v[0];
	for (int i = 1; i < n; i++)
		psum[i] = psum[i - 1] + v[i];

	int x, y, a, b;
	for (int i = 0; i < q; i++) {
		cin >> x >> y >> a >> b;
		
		x--; y--;
		if (x != 0) {
			printf("%lld\n", psum[y] - psum[x - 1]);
		}
		else {
			printf("%lld\n", psum[y]);
		}
		
	}
	return 0;
}