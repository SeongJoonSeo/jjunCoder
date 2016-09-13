/*
2016.9.13
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1620
나는야 포켓몬 마스터 이다솜
*/

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	int n, m;
	string name;
	cin.sync_with_stdio(false);
	cin >> n >> m;
	map<int, string> Map;
	map<string, int> Map2;
	for (int i = 1; i <= n; i++) {
		cin >> name;
		Map.insert(make_pair(i, name));
		Map2.insert(make_pair(name, i));
	}
	string question;
	for (int i = 0; i < m; i++) {
		cin >> question;
		if (question[0] >= 48 && question[0] <= 57) {
			//문제가 숫자로 들어왔을 때
			int num = stoi(question);
			auto it = Map.find(num);
			printf("%s\n", (*it).second.c_str());
		}
		else {
			//문제가 포켓몬의 이름으로 들어왔을 때
			auto it = Map2.find(question);
			printf("%d\n", (*it).second);
		}
	}
	return 0;
}