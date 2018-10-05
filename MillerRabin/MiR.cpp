#include<bits/stdc++.h>

using namespace std;

int Mul(int x,int y,int mo)
{
	int tmp=(x*y-(int)((long double)x/mo*y+1.0e-8)*mo);
	return (tmp<0)?(tmp+mo):tmp;
}

void SMul(int &x,int y,int mo)
{
	if((x=(x*y-(int)((long double)x/mo*y+1.0e-8)*mo))<0)
		x+=mo;
}

bool MiR(int x)
{
	int o,y=x-1;
	do
		o=rand()%x;
	while(!o);
	for(;!(y&1);y>>=1);
	int r=1,z=y;
	for(;y;y>>=1,SMul(o,o,x))if(y&1)
		SMul(r,o,x);
	if(r==1)
		return true;
	int r2=Mul(r,r,x);
	for(z<<=1;r2!=1&&z<x-1;r=r2,r2=Mul(r2,r2,x),z<<=1);
	return r2==1&&r==x-1;
}

bool isP(int x)
{
	return x<=7?x==2||x==3||x==5||x==7:x%2!=0&&x%3!=0&&x%5!=0&&x%7!=0&&MiR(x)&&MiR(x)&&MiR(x)&&MiR(x);
}

int main()
{
	return 0;
}
