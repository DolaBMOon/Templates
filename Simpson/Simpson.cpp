#include<bits/stdc++.h>

using namespace std;

const double eps=1e-6;

double f(double x)
{
	//It's what to be integrated.
	return 233;
}

double Simpson(double l,double m,double r,double fl,double fm,double fr)
{
	return (r-l)*(fl+4*fm+fr)/6;
}

double Integrate(double l,double m,double r,double fl,double fm,double fr,double nw,int deep)
{
	if(deep>=20)
		return nw;
	double lm=(l+m)*0.5,rm=(m+r)*0.5;
	double flm=f(lm),frm=f(rm);
	double x=Simpson(l,lm,m,fl,flm,fm),y=Simpson(m,rm,r,fm,frm,fr);
	if(abs(x+y-nw)<eps)
		return nw;
	return Integrate(l,lm,m,fl,flm,fm,x,deep+1)+
	Integrate(m,rm,r,fm,frm,fr,y,deep+1);
}

double Calc(double l,double r)
{
	double m=(l+r)*0.5;
	double fl=f(l),fm=f(m),fr=f(r);
	double nw=Simpson(l,m,r,fl,fm,fr);
	return Integrate(l,m,r,fl,fm,fr,nw,0);
}

int main()
{
	return 0;
}
