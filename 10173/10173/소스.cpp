/*
2016.9.13
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#10173
니모를 찾아서
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string input;
	vector<string> n;
	n.push_back("nemo"); n.push_back("Nemo"); n.push_back("nEmo"); n.push_back("neMo");
	n.push_back("nemO"); n.push_back("NEmo"); n.push_back("NeMo"); n.push_back("NemO");
	n.push_back("nEMo"); n.push_back("nEmO"); n.push_back("neMO"); n.push_back("NEMo");
	n.push_back("NEmO"); n.push_back("nEMO"); n.push_back("NeMO"); n.push_back("NEMO");
	getline(cin, input);
	while (input != "EOI") {
		bool found = false;
		for (int i = 0; i < n.size(); i++)
			if (input.find(n[i]) != string::npos)
				found = true;			
		if (found)
			printf("Found\n");
		else
			printf("Missing\n");
		getline(cin, input);
	}
	return 0;
}