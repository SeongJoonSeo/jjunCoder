/*
2016.9.21
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#1107
리모컨
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int main() {
	int n, m, num;
	cin.sync_with_stdio(false);
	cin >> n >> m;
	vector<bool> v(10, true);
	vector<int> buttons;
	for (int i = 0; i < m; i++) {
		//망가진 번호를 입력받는다.
		cin >> num;
		v[num] = false;
	}
	for (int i = 0; i < 10; i++)
		if (v[i])
			buttons.push_back(i);
	
	if (n == 100) {
		//100번이면 번 누르고 가능
		cout << 0; return 0;
	}
	else if (n == 99 || n == 101) {
		//+또는-만 누르면 되니까
		cout << 1; return 0;
	}

	//번호 하나도 안 누르고 +,-를 했을때 최소인 경우.
	//번호가 고장나있든말든 +,-해서 가면 됨.
	int diff = abs(100 - n);//채널 차이.
	string temp = to_string(n);
	int numSize = temp.size();//이동하려고 하는 채널의 자릿수(번호 눌러야되는 수)
	if (numSize >= diff) {//채널 차이만큼 +,- 눌러서 이동하면 됨.
		cout << diff; return 0;
	}
	//번호만 눌렀을때 최소인 경우.
	bool allSafe = true;
	for (int i = 0; i < numSize; i++)
		if (!v[temp[i] - 48])
			allSafe = false;
	if (allSafe) {
		cout << numSize; return 0;
	}
	//둘을 섞어야 최소인 경우.
	int idx = 0;
	bool up = true; //채널을 위로 올라가야 할지, 내려가야할지.
	bool first = true;//맨 윗자리일때만 up을 바꾸어야 한다.
	while (idx != temp.size()) {
		int x = temp[idx] - 48;		
		if (!v[x]) {
			//temp 의 idx번째 자리가 x고, 그 버튼이 고장났을때.
			int cnt = 0, left = x - 1, right = x + 1, cnt2 = 0;
			//x의 가장 가까운 수 중 고장나지 않은 버튼을 찾는다.
			while (left >= 0 && !v[left]) {
				cnt++; left--;
			}
			while (right != 10 && !v[right]) {
				cnt2++; right++;
			}

			//모두 고장났거나 0만남았을경우
			if (left <= 0 && right == 10) {
				//+,-로 가야 함
				cout << diff; return 0;
			}
			else {				
				if (right == 10 && left != -1) {
					//위쪽 번호대만 고장났을때
					temp[idx] = left + 48;					
				}
				else if (left == -1 && right != 10) {
					//아래쪽 번호대만 고장났을때
					temp[idx] = right + 48;
					if (first)
						up = false;
				}
				else {
					//둘다 있을때
					//temp 의 idx번째 자리의 수를 고장나지 않은 버튼으로 바꾼다.
					if (first) {//처음 들어온거면
						//cnt가 더 크면 채널을 크게 잡아서 내려가는게 더 낫다.
						if (cnt > cnt2) {
							up = false;
							temp[idx] = right + 48;
						}
						else {
							temp[idx] = left + 48;
						}						
					}
					else {
						if (up) {//채널을 올라가야한다.
							//채널을 높게잡자.
							temp[idx] = right + 48;
						}
						else {//채널을 내려가야한다.
							//채널을 낮게잡자.
							temp[idx] = left + 48;
						}
					}
					
				}	

				
			}
		}
		idx++;
		first = false;
	}
	//가장 최소로 움직일 수 있는 채널로 옮겼다.
	//버튼 누른 수 + 옮긴 채널과 현재 채널의 차이를 출력하자.
	cout << numSize + abs(atoi(temp.c_str()) - n);
	return 0;
}