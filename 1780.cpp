/*
2016.9.3
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1780
종이의 개수
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > table;
int cnt[3];

void solve(int sy, int sx, int ey, int ex) {
	//종이의 크기가 1이면
	if (sy == ey - 1) {
		cnt[table[sy][sx] + 1]++;
		return;
	}
	int comp = table[sy][sx];
	int delta = (ey - sy) / 3;
	int x1 = sx, x2 = sx + delta, x3 = sx + 2 * delta;
	int y1 = sy, y2 = sy + delta, y3 = sy + 2 * delta;
	for (int i = sy; i < ey; i++)
		for (int j = sx; j < ex; j++)
			if (comp != table[i][j]) {
				//종이 안의 수가 모두 같지 않으면 분할정복.
				solve(y1, x1, y2, x2);
				solve(y1, x2, y2, x3);
				solve(y1, x3, y2, ex);
				solve(y2, x1, y3, x2);
				solve(y2, x2, y3, x3);
				solve(y2, x3, y3, ex);
				solve(y3, x1, ey, x2);
				solve(y3, x2, ey, x3);
				solve(y3, x3, ey, ex);
				return;
			}

	//종이 안의 수가 모두 같으면
	cnt[table[sy][sx] + 1]++;
	return;
}

int main() {
	int n, input;
	cin.sync_with_stdio(false);
	cin >> n;
	table.assign(n, vector<int>(n, 0));
	cnt[0] = cnt[1] = cnt[2] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> input;
			table[i][j] = input;
		}
	}
	solve(0, 0, n, n);
	cout << cnt[0] << endl;
	cout << cnt[1] << endl;
	cout << cnt[2] << endl;
	return 0;
}
