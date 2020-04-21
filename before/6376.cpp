#include <iostream>

using namespace std;

int main(){
	double d=1;
	double fact = 1;
	cout << "n e\n- -----------\n";
	for(int i=0;i<10;i++){
		cout << i << " ";		
		if(i==0)
			cout << 1 << endl;
		else if(i==8){
			fact*=i;
			d+=(1/fact);
			printf("%.9f\n",d);
		}
		else{
			fact*=i;
			d+=(1/fact);
			printf("%.10g\n",d);
		}
	}
	return 0;
}