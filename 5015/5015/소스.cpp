/*
2016.8.30
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#5015
ls
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int> > cache;

string W, S;

bool matchMemoized(int w, int s) {
	int& ret = cache[w][s];
	if (ret != -1) return ret;
	while (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])) {
		++w;
		++s;
	}
	//wildcard 가 끝났다면 길이가 같아야지 매칭된다.
	if (w == W.size()) return ret = (s == S.size());
	//끝이 * 이라면 * wildcard의 다음 글자들과 string의 substr들이 매칭되는지 확인한다.
	if (W[w] == '*')
 		for (int skip = 0; skip + s <= S.size(); skip++)
			if (matchMemoized(w + 1, s + skip))
				return ret = 1;
	return ret = 0;
}

int main() {
	int n;
	cin.sync_with_stdio(false);
	cin >> W >> n;
	for (int i = 0; i < n; i++) {
		cache.clear();
		cache.assign(101, vector<int>(101, -1));
		cin >> S;
		if (matchMemoized(0, 0))
			cout << S << endl;
	}
	return 0;
}