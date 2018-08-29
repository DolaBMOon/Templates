#include<bits/stdc++.h>

using namespace std;

const int N=500000+10;
const int INF=0x3f3f3f3f;

int n,m;

int ch[N][2],fa[N],lz[N],u[N],v[N],sm[N],w[N];

int Which(int x)
{
	return ch[x][1]==x;
}

void Apply(int x)
{
	if(x)
	{
		lz[x]^=1;
		swap(ch[x][0],ch[x][1]);
	}
}

bool isRt(int x)
{
	return ch[fa[x]][0]!=x&&ch[fa[x]][1]!=x;
}

void Update(int x)
{
	sm[x]=w[x]+sm[ch[x][0]]+sm[ch[x][1]];
}

void Rotate(int x)
{
	register int f=fa[x],gf=fa[f],k=Which(x);
	if(!isRt(f))
	{
		ch[gf][Which(f)]=x;
		Update(gf);
	}
	fa[x]=gf;
	fa[ch[f][k]=ch[x][!k]]=f;
	Update(f);
	ch[x][!k]=f;
	fa[f]=x;
	Update(x);
}

void Pushdown(int x)
{
	if(x&&lz[x])
	{
		Apply(ch[x][0]);
		Apply(ch[x][1]);
		lz[x]=0;
	}
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
			Rotate((Which(f)==Which(x))?f:x);
}

void Access(int o)
{
	for(int y=0,x=o;x;y=x,x=fa[x])
	{
		Splay(x);
		ch[x][1]=y;
		Update(x);
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
	MkRt(x);
	fa[x]=y;
}

void Cut(int x,int y)
{
	MkRt(x);
	Access(y);
	ch[y][0]=fa[x]=0;
	Update(y);
}

int main()
{
	return 0;
}
