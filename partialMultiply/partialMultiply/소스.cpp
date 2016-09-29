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
	vector<double> pmul(10000000);//partial multiply
	pmul[0] = inputs[0];
	vector<int> zeroIdx;
	for (int i = 1; i < n; i++) {
		if (inputs[i] != 0)
			pmul[i] = pmul[i - 1] * inputs[i];
		else {
			zeroIdx.push_back(i);
			pmul[i] = 1;
		}
	}
	int startIdx = 0, endIdx;
	for (int i = 0; i < zeroIdx.size(); i++) {

	}


	

	inputFile.close();
	outputFile.close();
	return 0;
}