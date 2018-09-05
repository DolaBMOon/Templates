#include<bits/stdc++.h>

using namespace std;

#define LL long long

const int N=100000+10;

int n,q,ch[N][2],lz[N],sz[N],fa[N],w[N],sm[N];

bool isRt(int x)
{
	return ch[fa[x]][0]!=x&&ch[fa[x]][1]!=x;
}

int Which(int x)
{
	return ch[fa[x]][1]==x;
}

void Pullup(int x)
{
	sm[x]=sm[ch[x][0]]+sm[ch[x][1]]+w[x]+1;
}

void Apply(int x)
{
	if(x)
	{
		swap(ch[x][0],ch[x][1]);
		lz[x]^=1;
	}
}

void Pushdown(int x)
{
	if(lz[x])
	{
		Apply(ch[x][0]);
		Apply(ch[x][1]);
		lz[x]=0;
	}
}

void Rotate(int x)
{
	int f=fa[x],gf=fa[fa[x]],k=Which(x);
	if(!isRt(f))
		ch[gf][Which(f)]=x;
	fa[x]=gf;
	fa[ch[f][k]=ch[x][!k]]=f;
	Pullup(f);
	fa[f]=x;
	ch[x][!k]=f;
	Pullup(x);
}

void Climb(int x)
{
	if(!isRt(x))
		Climb(fa[x]);
	Pushdown(x);
}

void Splay(int x)
{
	Climb(x);
	for(int f;!isRt(x);Rotate(x))
		if(!isRt(f=fa[x]))
			Rotate((Which(fa[x])^Which(x))?x:f);
}

void Access(int o)
{
	for(int x=o,y=0;x;y=x,x=fa[x])
	{
		Splay(x);
		w[x]+=sm[ch[x][1]];
		w[x]-=sm[ch[x][1]=y];
		Pullup(x);
	}
	Splay(o);
}

void MkRt(int x)
{
	Access(x);
	Apply(x);
}

void Link(int x,int y)
{
	Access(x);
	MkRt(y);
	fa[y]=x;
	w[x]+=sm[y];
	sm[x]+=sm[y];
}

LL Query(int x,int y)
{
	MkRt(x);
	Access(y);
	return (LL)(w[x]+1)*(w[y]+1);
}

int main()
{
	return 0;
}
