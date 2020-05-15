#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int N, M, a;
    long long sum;
    cin >> N >> M;
    sum = -N;
    vector<int> friends;
    for (int i = 0; i < M; i++)
    {
        cin >> a;
        sum += (long long)a;
        friends.push_back(a);
    }

    sort(friends.begin(), friends.end());
    long long res = 0;
    for (int i = 0; i < friends.size(); i++)
    {
        int rest = (M - i); // 남은 사람의 수
        // N / rest = 못 준 사탕을 남은 사람의 수로 나누어서 분배
        // 2개를 원하는데 분배된 못 준 사탕의양이 3개 이상이면 원하는 수 만큼만 못 줘야 함
        long long w = min((long long)friends[i], sum / rest);
        sum -= w;
        res += w * w;
    }
    printf("%lld\n", res);
    return 0;
}