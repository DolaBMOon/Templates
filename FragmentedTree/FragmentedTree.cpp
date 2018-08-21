#include<bits/stdc++.h>

using namespace std;

const int N=233333;

int n,blo,fir[N],nxt[N],to[N],tote;

int cap[N],col[N],cnt,sz[N],stk[N],tp;

void Dfs(int u,int fa)
{
	stk[++tp]=u;
	for(int i=fir[u],v;i;i=nxt[i])if((v=to[i])!=fa)
	{
		Dfs(v,u);
		sz[u]+=sz[v];
		if(sz[u]>=blo)
		{
			cap[++cnt]=u;
			while(stk[tp]!=u)
				col[stk[tp--]]=cnt;
			sz[u]=0;
		}
	}
	++sz[u];
}

int main()
{
	blo=sqrt(n);
	Dfs(1,0);
	if(!cnt)
		++cnt;
	cap[cnt]=1;
	while(tp)
		col[stk[tp--]]=cnt;
	return 0;
}
