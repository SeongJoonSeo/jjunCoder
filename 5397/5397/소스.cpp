/*
2016.9.20
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#5397
키로거
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	int t;
	cin.sync_with_stdio(false);
	cin >> t;
	for (int i = 0; i < t; i++) {
		string input,ret;
		cin >> input;
		auto it = input.begin();
		auto it2 = ret.begin();
		while ((*it) == '<' || (*it) == '>' || (*it) == '-')
			it++;
		for (it; it != input.end(); it++) {
			if ((*it) == '<') {
				if (it2 != ret.begin())
					it2--;						
			}				
			else if ((*it) == '>') {
				if (it2 != ret.end())
					it2++;
			}
			else if ((*it) == '-') {
				if (it2 != ret.begin()) {					
					auto endIt = it2;
					it2--;
					while ((it + 1) != input.end() && (*(it + 1)) == '-') {
						it++;
						if (it2 != ret.begin())
							it2--;
					}
					auto startIt = it2;
					it2 = ret.erase(startIt,endIt);
				}
			}
			else {
				it2 = ret.insert(it2, (*it));
				it2++;
			}	
		}
		printf("%s\n", ret.c_str());
	}
	return 0;
}