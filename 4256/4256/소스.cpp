/*
2016.10.4
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#4256
트리
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> preorder, inorder;

void post(int l, int r, int L, int R) {
	if (l >= r) return;
	const int N = r - l;
	const int root = preorder[l];
	const int left = find(inorder.begin() + L, inorder.begin() + R, root) - (inorder.begin() + L);

	post(l + 1, l + left + 1, L, L + left);
	post(l + 1 + left, r, L + left + 1, R);

	printf("%d ", root);
}

int main() {
	int t, n, num;	
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		preorder.clear();
		inorder.clear();
		for (int i = 0; i < n; i++) {
			scanf("%d", &num);
			preorder.push_back(num);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &num);
			inorder.push_back(num);
		}
		post(0, n, 0, n);
		printf("\n");
	}
	return 0;
}