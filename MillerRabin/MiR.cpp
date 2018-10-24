#include<bits/stdc++.h>

using namespace std;

#define LL long long

LL Mul(LL x,LL y,LL mo)
{
	LL tmp=(x*y-(LL)((long double)x/mo*y+1.0e-8)*mo);
	return (tmp<0)?(tmp+mo):tmp;
}

void SMul(LL &x,LL y,LL mo)
{
	if((x=(x*y-(LL)((long double)x/mo*y+1.0e-8)*mo))<0)
		x+=mo;
}

bool MiR(LL x)
{
	LL o,y=x-1;
	do
		o=rand()%x;
	while(!o);
	for(;!(y&1);y>>=1);
	LL r=1,z=y;
	for(;y;y>>=1,SMul(o,o,x))if(y&1)
		SMul(r,o,x);
	if(r==1)
		return true;
	LL r2=Mul(r,r,x);
	for(z<<=1;r2!=1&&z<x-1;r=r2,r2=Mul(r2,r2,x),z<<=1);
	return r2==1&&r==x-1;
}

bool isP(LL x)
{
	return x<=7?x==2||x==3||x==5||x==7:x%2!=0&&x%3!=0&&x%5!=0&&x%7!=0&&MiR(x)&&MiR(x)&&MiR(x)&&MiR(x);
}

int main()
{
	return 0;
}
