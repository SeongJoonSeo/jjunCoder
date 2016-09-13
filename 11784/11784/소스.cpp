/*
2016.9.13
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#11784
Hex Code
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	string input;
	getline(cin, input);
	while(!cin.eof()) {		
		int temp;
		for (int i = 0; i < input.size(); i += 2) {
			if (input[i] >= 65 && input[i] <= 70)
				temp = (input[i] - 55) * 16;
			else
				temp = (input[i] - 48) * 16;
			if (input[i + 1] >= 65 && input[i + 1] <= 70)
				temp += (input[i + 1] - 55);
			else
				temp += (input[i + 1] - 48);
			printf("%c", static_cast<char>(temp));
		}
		printf("\n");
		getline(cin, input);
	}	
	return 0;
}