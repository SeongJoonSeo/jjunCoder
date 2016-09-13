/*
2016.9.13
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#2730
오늘은 OS 숙제 제출일
*/

#include <iostream>
#include <string>

using namespace std;
int submit_y;
bool isPrior(int d_m, int d_d, int s_m, int s_d, int y) {
	//같은 달 일때.
	if (d_m == s_m && d_d - s_d > 0 && d_d - s_d < 7) {
		submit_y = y;
		return true;
	}
	//다른 달 일때.
	bool leap = false;
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
		leap = true;
	//n년 1월 제출일인데 n-1년 12월 제출 했을 때.
	if (d_m == 1 && s_m == 12)
		if ((s_d + 7) % 31 > d_d) {
			submit_y = y-1;
			return true;
		}
	submit_y = y;
	//윤년일때 2월에 제출했는데 3월 제출마감일이면
	if (leap && d_m==3 && s_m==2 && ((s_d + 7) % 29 > d_d))
		return true;
	//윤년아닐때
	if (d_m == 3 && s_m == 2 && ((s_d + 7) % 28 > d_d))
		return true;
	if (s_m == 1 || s_m == 3 || s_m == 5 || s_m == 7 || s_m == 8 || s_m == 10 || s_m == 12) {
		//이 제출 월 들은 다 31일까지 있다.
		if (s_m + 1 == d_m && ((s_d + 7) % 31 > d_d))
			return true;
	}
	if (s_m == 4 || s_m == 6 || s_m == 9 || s_m == 11) {
		//이 제출 월 들은 다 30일까지 있다.
		if (s_m + 1 == d_m && ((s_d + 7) % 30 > d_d))
			return true;
	}
	return false;
}

bool isAfter(int d_m, int d_d, int s_m, int s_d, int y) {
	//같은 달 일때.
	if (d_m == s_m && s_d - d_d > 0 && s_d - d_d < 7) {
		submit_y = y;
		return true;
	}
	//다른 달 일때.
	bool leap = false;
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
		leap = true;
	//n년 12월 마감일인데 n+1년 1월 제출 했을 때.
	if (s_m == 1 && d_m == 12)
		if ((d_d + 7) % 31 > s_d) {
			submit_y = y+1;
			return true;
		}
	submit_y = y;
	//윤년일때 2월에 마감했는데 3월 제출이면
	if (leap && s_m == 3 && d_m == 2 && ((d_d + 7) % 29 > s_d))
		return true;
	//윤년아닐때
	if (s_m == 3 && d_m == 2 && ((d_d + 7) % 28 > s_d))
		return true;
	if (d_m == 1 || d_m == 3 || d_m == 5 || d_m == 7 || d_m == 8 || d_m == 10 || d_m == 12) {
		//이 제출 월 들은 다 31일까지 있다.
		if (d_m + 1 == s_m && ((d_d + 7) % 31 > s_d))
			return true;
	}
	if (d_m == 4 || d_m == 6 || d_m == 9 || d_m == 11) {
		//이 제출 월 들은 다 30일까지 있다.
		if (d_m + 1 == s_m && ((d_d + 7) % 30 > s_d))
			return true;
	}
	return false;
}

int main() {
	int t, m, d, y;
	int submit_m, submit_d;
	string deadLine, submit;
	cin.sync_with_stdio(false);
	cin >> t;
	for (int i = 0; i < t; i++) {
		//날짜 2개로 이루어져 있다
		//첫번째 날짜는 '숙제 마감일'			월/일/연 형식
		//두번째 날짜는 '보고서에 적힌 날짜'	월/일 형식
		cin >> deadLine >> submit;
		int j = 0;
		if (deadLine[j+2] == '/') {
			m = stoi(deadLine.substr(j, 2));
			j = j+3;
		}
		else if (deadLine[j+1] == '/') {
			m = stoi(deadLine.substr(j, 1));
			j = j+2;
		}
		if (deadLine[j + 2] == '/') {
			d = stoi(deadLine.substr(j, 2));
			j = j+3;
		}
		else if (deadLine[j + 1] == '/') {
			d = stoi(deadLine.substr(j, 1));
			j = j+2;
		}
		y = stoi(deadLine.substr(j, 4));
		j = 0;
		if (submit[j + 2] == '/') {
			submit_m = stoi(submit.substr(j, 2));
			j = j + 3;
		}
		else if (submit[j + 1] == '/') {
			submit_m = stoi(submit.substr(j, 1));
			j = j + 2;
		}
		submit_d = stoi(submit.substr(j));
		int comp_d = abs(submit_d - d);
		//comp_d가 양수면 늦게 제출한거
		// 음수면 먼저 제출한거
		// 0 이면 당일에 제출한거
		if (isPrior(m, d, submit_m, submit_d,y)) {
			//Prior
			cout << submit_m << "/" << submit_d << "/" << submit_y << " ";
		}
		else if (isAfter(m, d, submit_m, submit_d,y)) {
			//After
		}
		else if (submit_m == m&&comp_d == 0) {
			//SAME DAY
			printf("SAME DAY\n");
		}
		else{
			//OUT OF RANGE
			printf("OUT OF RANGE\n");
		}
	}
	return 0;
}