/*
2016.9.29
Seong Joon Seo (ID: jjunCoder)

Problem
#CSI 3108-02 Fall 2016 Algorithm Analysis
승혁이가 풀어보라고 한 부분 곱 문제!
n^2보다 빠른 시간에 풀어보자.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
	ifstream inputFile("input.txt");
	ofstream outputFile("output.txt");

	int n, input;
	string inputStr;
	cin.sync_with_stdio(false);
	inputFile >> n;
	vector<float> inputs(10000000);
	for (int i = 0; i < n; i++) {
		//get inputs.
		inputFile >> inputStr;
		//parsing and insert into vector.
		if (inputStr.front() != '.')
			inputs[i] = atof(inputStr.c_str());
		else {
			inputStr = "0" + inputStr;
			inputs[i] = atof(inputStr.c_str());
		}
	}
	vector<float> maxVec;
	bool currentlyNegative = false;
	float maxi = 1;//empty set case.
	for (int i = 0; i < n; i++) {
		if (inputs[i] >= 1 )
			maxi *= inputs[i];
		else if (inputs[i] > 0 && inputs[i] < 1) {
			//greator than zero and less than one.
			//then,can be no more maximum value.
			maxVec.push_back(maxi);//save our previous maximum value;
			maxi *= inputs[i];
		}
		else if (inputs[i] == 0) {
			//zero. our maxi value cannot be greator than 1.
			maxVec.push_back(maxi);//save our previous maximum value;
			maxi = 1;
		}
		else {
			if (currentlyNegative) {
				//maxi is already neg.
				maxi *= inputs[i];
				currentlyNegative = false;
			}
			else {
				//negative value.
				maxVec.push_back(maxi);//save our previous maximum value;
				maxi *= inputs[i];
				currentlyNegative = true;//our maxi is currently Negative value.
			}
		}
	}
	


	

	inputFile.close();
	outputFile.close();
	return 0;
}