/*
2016.8.22
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1924
2007³â
*/

#include <iostream>

using namespace std;

int main() {
	int x, y;
	cin >> x >> y;
	int day = 0;
	bool start = true;
	//0=MON ... 1=TUE ... 6=SUN
	switch (x) {
		case 12:
			for (int i = 1; i <= 31; i++) {
				if (start && i == y) {					
					start = false;
					break;
				}
				day = (day+1) % 7;
			}
		case 11:
			for (int i = 1; i <= 30; i++) {
				if (start && i == y) {
					start = false;
					break;
				}
				day = (day+1) % 7;
			}
		case 10:
			for (int i = 1; i <= 31; i++) {
				if (start && i == y) {
					start = false;
					break;
				}
				day = (day+1) % 7;
			}
		case 9:
			for (int i = 1; i <= 30; i++) {
				if (start && i == y) {
					start = false;
					break;
				}
				day = (day+1) % 7;
			}
		case 8:
			for (int i = 1; i <= 31; i++) {
				if (start && i == y) {
					start = false;
					break;
				}
				day = (day+1) % 7;
			}
		case 7:
			for (int i = 1; i <= 31; i++) {
				if (start && i == y) {
					start = false;
					break;
				}
				day = (day+1) % 7;
			}
		case 6:
			for (int i = 1; i <= 30; i++) {
				if (start && i == y) {
					start = false;
					break;
				}
				day = (day+1) % 7;
			}
		case 5:
			for (int i = 1; i <= 31; i++) {
				if (start && i == y) {
					start = false;
					break;
				}
				day = (day+1) % 7;
			}
		case 4:
			for (int i = 1; i <= 30; i++) {
				if (start && i == y) {
					start = false;
					break;
				}
				day = (day+1) % 7;
			}
		case 3:
			for (int i = 1; i <= 31; i++) {
				if (start && i == y) {
					start = false;
					break;
				}
				day = (day+1) % 7;
			}
		case 2:
			for (int i = 1; i <= 28; i++) {
				if (start && i == y) {
					start = false;
					break;
				}
				day = (day+1) % 7;
			}
		case 1:
			for (int i = 1; i <= 31; i++) {
				if (start && i == y) {
					start = false;
					break;
				}
				day = (day+1) % 7;
			}
			break;
	}
	switch (day) {
	case 0:
		cout << "MON";
		break;
	case 1:
		cout << "TUE";
		break;
	case 2:
		cout << "WED";
		break;
	case 3:
		cout << "THU";
		break;
	case 4:
		cout << "FRI";
		break;
	case 5:
		cout << "SAT";
		break;
	case 6:
		cout << "SUN";
		break;
	}
	return 0;
}