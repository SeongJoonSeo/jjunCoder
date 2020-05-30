// BOJ 2042번: 구간 합 구하기
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

vector<ll> vec, tree;
// n 100만, m 1만, k 1만 -> 100억 이상의 연산 : 세그먼트 트리 사용해야함
int n, m, k;

ll construct(int node, int start, int end) {
    if (start == end)
        return tree[node] = vec[start];
    else
        return tree[node] = construct(node * 2, start, (start + end) / 2) + construct(node * 2 + 1, (start + end) / 2 + 1, end);
}

ll sum(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    return sum(node * 2, start, (start + end) / 2, left, right) + sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(int node, int start, int end, int index, ll diff) {
    if (index < start || index > end) return;
    tree[node] += diff;
    if (start != end) {
        update(node * 2, start, (start + end) / 2, index, diff);
        update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
    }
}

void solution() {
    scanf("%d %d %d", &n, &m, &k);
    vec.assign(n, 0);
    int height = (int)ceil(log2(n));
    int tree_size = (1 << (height + 1));
    tree.assign(tree_size, 0);

    for (int i = 0; i < n; i++)
        scanf("%lld", &vec[i]);

    construct(1, 0, n - 1);
    int a;
    for (int i = 0; i < k + m; i++) {
        scanf("%d", &a);
        if (a == 1) {
            int b;
            ll c;
            scanf("%d %lld", &b, &c);
            b--;  // node index
            ll diff = c - vec[b];
            vec[b] = c;
            update(1, 0, n - 1, b, diff);
        } else {
            int b, c;
            scanf("%d %d", &b, &c);
            printf("%lld\n", sum(1, 0, n - 1, b - 1, c - 1));
        }
    }
}

int main() {
    solution();
    return 0;
}