/*
2016.8.22
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#10809
¾ËÆÄºª Ã£±â
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;
	int alphabet[26];
	for (int i = 0; i < 26; i++) {
		alphabet[i] = -1;
	}
	for (int i = 0; i < str.size(); i++) {
		if(alphabet[str[i]-97]==-1)
			alphabet[str[i] - 97] = i;
	}
	for (int i = 0; i < 26; i++) {
		cout << alphabet[i] << " ";
	}
	return 0;
}