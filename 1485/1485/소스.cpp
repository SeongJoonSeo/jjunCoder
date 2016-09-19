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
	Point middle(Point& other) {
		return Point((other.x + x) / 2, (other.y + y) / 2);
	}
	int sqlen(Point& other) {
		return (other.x - x)*(other.x - x) + (other.y - y)*(other.y - y);
	}
};

int main() {
	int t;
	cin.sync_with_stdio(false);
	cin >> t;
	for (int i = 0; i < t; i++) {
		int x, y;
		vector<Point> v;
		for (int j = 0; j < 4; j++) {
			cin >> x >> y;
			v.push_back(Point(x,y));
		}
		vector<int> len;
		for (int j = 0; j < v.size() - 1; j++) 
			for (int k = j + 1; k < v.size(); k++) 
				len.push_back(v[j].sqlen(v[k]));
		sort(len.begin(), len.end());
		
	}
	return 0;
}