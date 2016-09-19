/*
2016.9.19
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1485
정사각형
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Point {
public:
	int x, y;
	Point(int a, int b) {
		x = a; y = b;
	}
	Point middle(Point other) {
		return Point((other.x + x) / 2, (other.y + y) / 2);
	}
	int sqlen(Point other) {
		return (other.x - x)*(other.x - x) + (other.y - y)*(other.y - y);
	}
	bool eq(Point other) {
		return (x == other.x) && (y == other.y);
	}
	Point minus(Point other) {
		return Point(other.x - x, other.y - y);
	}
	int product(Point other) {
		return (other.x*x + other.y*y);
	}
};

int main() {
	int t;
	cin.sync_with_stdio(false);
	cin >> t;
	for (int i = 0; i < t; i++) {
		int x, y;
		vector<pair<int,int> > v;
		vector<Point> pts;
		for (int j = 0; j < 4; j++) {
			cin >> x >> y;
			v.push_back(make_pair(x,y));
		}
		sort(v.begin(), v.end());
		for (int j = 0; j < 4; j++)
			pts.push_back(Point(v[j].first, v[j].second));
		if (pts[0].middle(pts[3]).eq( pts[1].middle(pts[2]))) {
			if (pts[0].sqlen(pts[3]) == pts[1].sqlen(pts[2])) {
				if ((pts[3].minus( pts[0])).product((pts[2].minus( pts[1]))) == 0) {
					cout << 1 << endl;
					continue;
				}
			}
		}
		cout << 0 << endl;
	}
	return 0;
}