#include <iostream>


using namespace std;

class Circle{
public:
	double cx,cy,r;
	Circle(double x,double y,double radius)
	:cx(x),cy(y),r(radius){}
};

bool isIncluded(double x, double y, Circle c){
	double a = (c.cx-x)*(c.cx-x);
	double b = (c.cy-y)*(c.cy-y);
	return a+b<c.r*c.r;
}

int main(){
	int t;
	cin.sync_with_stdio(false);
	cin >> t;
	double x1,y1,x2,y2,cx,cy,r;	
	//x1,y1 : 출발점
	//x2,y2 : 도착점
	for(int i=0;i<t;i++){
		int n,a=0,b=0,c=0;
		cin>>x1>>y1>>x2>>y2;
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>cx>>cy>>r;
			if(isIncluded(x1,y1,Circle(cx,cy,r)))
				a++;
			if(isIncluded(x2,y2,Circle(cx,cy,r)))
				b++;
			if(isIncluded(x1,y1,Circle(cx,cy,r))&&isIncluded(x2,y2,Circle(cx,cy,r)))
				c++;
		}
		printf("%d\n",a+b-c*2);
	}
	return 0;
}



