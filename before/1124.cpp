#include <iostream>
#include <vector>

using namespace std;

int main(){
	int a,b;
	cin.sync_with_stdio(false);
	cin >> a >> b;
	vector<bool> isPrime(100001,true);
	vector<int> primes;
	isPrime[0] = false;
	isPrime[1] = false;
	for(int i=2;i<=100000;i++)
		if(isPrime[i]){
			primes.push_back(i);
			for(int j=2;j*i<=100000;j++)
				isPrime[i*j]=false;
		}

	int ret = 0;
	for(int i=a;i<=b;i++){
		int temp = i, count=0, idx=0;
		if(!isPrime[temp]){
			while(temp!=-1 && primes[idx]<=temp){
				if(temp%primes[idx]==0){
					temp/=primes[idx];
					count++;
				}				
				else
					idx++;				
			}
			if(isPrime[count])
				ret++;
		}		
	}
	cout << ret;
	return 0;
}