/*
2016.9.28
BaekJoon Online Judge
Problem Solving

Seong Joon Seo (ID: jjunCoder)

Problem
#13199
치킨 먹고 싶다
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin.sync_with_stdio(false);
	cin >> t;
	while (t--) {
		int p, m, f, c;
		cin >> p >> m >> f >> c;
		int coupon, num, ret = 0, k;
		//a는 꽁짜에 쿠폰 안주고 b는 준다.
		if (p > m)//가진 돈이 치킨값보다 적으면 둘다 0마리 먹을 수 있다.
			printf("%d\n", 0);
		else {
			num = m / p; //가진 돈으로 치킨을 사먹을 수 있는 마리 수.
			coupon = num*c;//그 마리수 * 주는 쿠폰 수를 다 모으면 총 쿠폰수.
			if (coupon >= f) {//가진 쿠폰수가 공짜로 시키는데 필요한 수보다 같거나 많으면
				k = coupon / f;//k마리 만큼 더 사먹을 수 있다. 상언이랑 두영이 둘다.
				coupon -= k*f;//쿠폰이 깎이고
				coupon += k*c;//상언이는 그만큼 더 받는다.
				while (coupon >= f) {//근데 상언이는 k만큼 더 먹으면 쿠폰을 k개 더 받는다. 그게 f보다 크면 또 먹는다.
					k = coupon / f;
					ret += k;//그럼 두영이보다 ret마리 만큼 더 먹는거다.
					coupon -= k*f;//쿠폰이 깎이고
					coupon += k*c;//상언이는 그만큼 더 받는다.					
				}
			}
			printf("%d\n", ret);
		}
	}
	return 0;
}