#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define ctz __builtin_ctzll

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
	LL y=x-1,o=rand()%y+1;
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

bool isPri(LL x)
{
	return (x<=7)?
		(x==2||x==3||x==5||x==7):
		(x%2!=0&&x%3!=0&&x%5!=0&&x%7!=0&&MiR(x)&&MiR(x)&&MiR(x)&&MiR(x));
}

LL n;

LL Gcd(LL a,LL b)
{
	if(!a)return b;
	if(!b)return a;
	int t=ctz(a|b);
	a>>=ctz(a);
	do
	{
		b>>=ctz(b);
		if(a>b)
			swap(a,b);
		b-=a;
	}while(b);
	return a<<t;
}

void Run(LL &x,LL n,LL a)
{
	SMul(x,x,n);
	if((x+=a)>=n)
		x-=n;
}

vector<LL> res;

void Song(LL n)
{
	if(isPri(n))
	{
		res.emplace_back(n);
		return;
	}
	int d=0;
	if(n%2==0)
		d=2;
	else if(n%3==0)
		d=3;
	for(LL t,x,y;!d;)
	{
		x=y=t=rand()%(n-1)+1;
		Run(y,n,t);
		do
		{
			d=Gcd(n,abs(x-y));
			if(d>1&&d<n)
				break;
			else
				d=0;
			Run(x,n,t);
			Run(y,n,t);
			Run(y,n,t);
		}
		while(x!=y);
	}
	Song(d);
	Song(n/d);
}

int main()
{
	return 0;
}
