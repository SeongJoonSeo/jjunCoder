/*
2016.9.21
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1027
고층 건물
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
	int n,a;
	cin.sync_with_stdio(false);
	cin >> n;
	vector<double> v;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);//a가 y좌표이고 index가 x좌표이다.
	}
	int maxi = -1, cnt = 0;
	double x1, y1, x2, y2;
	double m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			//0~i-1까지
			set<int> s;			
			x1 = i, y1 = v[i];
			y1 = j, y2 = v[j];
			m = (y2 - y1) / (x2 - x1);
			s.insert(j);//가장 앞에 보이는 건물
			for (int k = 0; k <= j; k++) {
				if (v[k] > m*(k - x1) + y1)
					s.insert(k);
				else {
					if (s.find(k) != s.end())
						s.erase(k);
				}
				
			}
		}
		for (int j = i+1; j < n; j++) {
			//i+1~n-1까지
			x1 = i, y1 = v[i];
			y1 = j, y2 = v[j];
		}
	}

	return 0;
}