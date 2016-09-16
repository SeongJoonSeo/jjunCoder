//1009

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int t;
	cin.sync_with_stdio(false);
	cin >> t;
	for(int i=0;i<t;i++){
		int a,b,period=1;
		cin>>a>>b;
		//제곱한다
		int temp=(a*a)%10;
		//제곱한것의 일의자리수와 원래 일의자리수가 같으면 바로 출력한다.
		if(temp==a%10){
			//1의자리수가 0이면 10번 컴퓨터로 출력하고
			if(a%10==0)
				printf("%d\n",10);
			else//아니면 a%10번 컴퓨터로 출력하는거다.
				printf("%d\n",a%10);
		}
		else{//제곱해서 바로 안나오면 주기를 갖는다. 그 주기를 구하자.
			while(temp!=a%10){
				period++;
				temp*=a;
				temp%=10;
			}//주기를 구했다.
			//b가 주기보다 크면 주기로 나누어 준다.
			//예를들어 7은 주기가 4인데, b가 4이하면 그대로 a^b를 계산해준다.
			//b가 4보다 크면 b를 4로 mod 해 준다. ex) 100%4 = 0
			if(b>period){
				b%=period;
				if(b==0)
					b=period;
			}
			if(((int)pow(a,b))%10==0)
				printf("%d\n",10);
			else
				printf("%d\n",((int)pow(a,b))%10);
		}	
		
	}
	return 0;
}