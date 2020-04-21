/*
2016.9.4
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#6549
히스토그램에서 가장 큰 직사각형
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> histogram;

long long solve(int start, int end) {
	if (start == end - 1) return histogram[start];
	int mid = (end + start) / 2;
	//분할정복 재귀함수의 호출 타이밍을 다시 생각해보자.
	long long maxi = solve(start,mid);
	maxi = max(maxi, solve(mid, end));
	long long left, right, height, length;
	long long area,areaL,areaR;
	left = mid-1, right = mid;
	height = min(histogram[left],histogram[right]);
	length = (right-left+1);
	area = height*length;
	while(start<left || right < end){
		if(start<end && (start==left||histogram[left-1]<histogram[right+1])){
			right++;
			height = min(height,histogram[right]);
		}
		else{
			--left;
			height = min(height,histogram[left]);
		}
		area = max(area, height*(right-left+1) );
	}
	return max(maxi,area);
}

int main() {
	int n, input;
	cin.sync_with_stdio(false);
	cin >> n;
	//직사각형의 갯수 n
	while(n!=0){
		for(int i=0;i<n;i++){
			cin >> input;
			//히스토그램 각각 사각형들의 높이가 주어진다.
			histogram.push_back(input);
		}
		printf("%lld\n",solve(0,n));
		cin >> n;
		histogram.clear();
	}	
	return 0;
}
