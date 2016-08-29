/*
2016.8.22
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1065
�Ѽ�
(� ���� ���� X�� �ڸ����� ���������� �̷�ٸ� �� ���� �Ѽ���� �Ѵ�.)
*/

#include <iostream>

using namespace std;

bool isHanSu(int n) {
	if (n < 100)
		return true;
	if (n == 1000)
		return false;
	int n1, n2, n3;
	n1 = n % 10;
	n /= 10;
	n2 = n % 10;
	n /= 10;		
	n3 = n % 10;
	n /= 10;
	if (n1 - n2 != n2 - n3)
		return false;
	else
		return true;
}

void theNumofHanSu(int n) {
	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (isHanSu(i))
			count++;
	}
	cout << count;
}

int main() {
	int n;
	cin >> n;
	theNumofHanSu(n);
	return 0;
}