/*
2016.9.20
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#3062
수 뒤집기
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin.sync_with_stdio(false);
	cin >> t;
	for (int i = 0; i < t; i++) {
		string a;
		cin >> a;
		//원래 숫자
		int temp = atoi(a.c_str());
		reverse(a.begin(), a.end());
		//뒤집힌 숫자
		int temp2 = atoi(a.c_str());
		temp += temp2;
		//temp는 더한 숫자.
		a = to_string(temp);
		auto left = a.begin();
		auto right = a.end()-1;
		bool palindrome = true;
		while (left < right) {
			if ((*left) != (*right))
				palindrome = false;
			left++; right--;
		}
		if (palindrome)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}