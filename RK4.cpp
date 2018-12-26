#include<iostream>
#include<cmath>

using namespace std;

float f( float x, float y)
{
	return exp(x)*sin(x*x)+y;
}
int main()
{
	float xo, yo, xn, h;
	cout<<"Input initial condns"<<endl;
	cin>>xo>>yo>>xn>>h;
	while(xo<xn)
	{
		float k1 = h* f(xo,yo);
		float k2 = h* f(xo+h/2,yo+k1/2);
		float k3 = h* f(xo+h/2,yo+k2/2);
		float k4 = h* f(xo+h,yo+k3);
		float k = (k1+2*k2+2*k3+k4)/6;
		yo += k;
		xo += h;
		cout<<"At x= "<<xo<<" y = "<<yo<<endl;
	}
	return 0;
}