/*
2016.8.22
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#4673
¼¿ÇÁ ³Ñ¹ö
*/

#include <iostream>
#include <vector>

using namespace std;

vector<bool> isSelfNum;

void selfNum(int n) {
	int digit = 10, ret = n;
	while (n != 0) {
		ret += n % digit;
		n /= digit;		
	}
	if(ret<10001)
		isSelfNum[ret] = false;
}

int main() {
	isSelfNum.assign(10001, true);
	for (int i = 1; i < 10001; i++) {
		selfNum(i);
	}
	for (int i = 1; i < 10001; i++) {
		if (isSelfNum[i])
			printf("%d\n", i);
	}
	return 0;
}