#include<bits/stdc++.h>

using namespace std;

const int N=1e6+10;

int n,m,rt[N],val[N],fix[N],sz[N],ch[N][2],ty[N],cnt;

void Pullup(int o)
{
	sz[o]=sz[ch[o][0]]+sz[ch[o][1]]+1;
}

void SplitByVal(int o,int k,int &x,int &y)
{
	if(o)
	{
		if(k<val[o])
		{
			SplitByVal(ch[o][0],k,x,ch[o][0]);
			Pullup(y=o);
		}
		else
		{
			SplitByVal(ch[o][1],k,ch[o][1],y);
			Pullup(x=o);
		}
	}
	else
		x=y=0;
}

void SplitByRk(int o,int k,int &x,int &y)
{
	if(o)
	{
		int t=sz[ch[o][0]]+1;
		if(k<t)
		{
			SplitByRk(ch[o][0],k,x,ch[o][0]);
			Pullup(y=o);
		}
		else
		{
			SplitByRk(ch[o][1],k-t,ch[o][1],y);
			Pullup(x=o);
		}
	}
	else
		x=y=0;
}

int Mergex(int x,int y)
{
	if(x&&y)
	{
		if(fix[x]>fix[y])
			swap(x,y);
		int a,b;
		SplitByVal(y,val[x],a,b);
		ch[x][0]=Mergex(ch[x][0],a);
		ch[x][1]=Mergex(ch[x][1],b);
		Pullup(x);
		return x;
	}
	else
		return x^y;
}

inline int Merge(int x,int y)
{
	if(x&&y)
	{
		if(fix[x]<fix[y])
		{
			ch[x][1]=Merge(ch[x][1],y);
			Pullup(x);
			return x;
		}
		else
		{
			ch[y][0]=Merge(x,ch[y][0]);
			Pullup(y);
			return y;
		}
	}
	else
		return x^y;
}

int Rand()
{
	static int sd=520;
	sd^=sd<<2;
	sd^=sd>>3;
	sd^=sd<<3;
	return sd;
}

int main()
{
	return 0;
}
