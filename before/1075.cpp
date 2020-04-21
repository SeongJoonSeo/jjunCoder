#include <iostream>

using namespace std;

int main(){
	long long n,f;
	cin.sync_with_stdio(false);
	cin >> n >> f;
	long long temp = n - n%100;
	for(int i=0;i<100;i++){
		if((temp+i)%f==0){
			if((temp+i)%100<10)
				cout << 0;
			cout << (temp+i)%100;
			return 0;
		}
	}
	return 0;
}