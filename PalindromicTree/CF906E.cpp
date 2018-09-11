#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define DivHim() cout<<">>>>>>>>>>>>>>>"<<endl
#define DivHer() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

template<typename T> bool GetMin(T &a,T b)
{
	return ((a<=b)?false:(a=b,true));
}

template<typename T> bool GetMax(T &a,T b)
{
	return ((a>=b)?false:(a=b,true));
}

/*
	 -<Unlimited Blade Works>-
 */

const int N=1e6+10;
const int ALPHA=26;
const int INF=0x3f3f3f3f;

char t0[N],t1[N];
int s[N],n;

int ch[N][ALPHA],fa[N],sf[N],last,tot,len[N],diff[N],dp[N],rec[N],sdp[N],srec[N];

void Init()
{
	s[0]=-233;
	last=len[0]=0;
	len[1]=-1;
	fa[0]=tot=1;
	fa[1]=0;
}

void Append(int k)
{
	int p=last,c=s[k];
	for(;c!=s[k-len[p]-1];p=fa[p]);
	if(!ch[p][c])
	{
		last=++tot;
		len[last]=len[p]+2;
		int t=fa[p];
		for(;c!=s[k-len[t]-1];t=fa[t]);
		fa[last]=t=ch[t][c];
		ch[p][c]=last;
		if((diff[last]=len[last]-len[t])==diff[t])
			sf[last]=sf[t];
		else
			sf[last]=t;
	}
	else
		last=ch[p][c];
}

int main()
{
	scanf("%s%s",t0+1,t1+1);
	n=strlen(t0+1);
	for(int i=1;i<=n;++i)
	{
		s[i*2-1]=t0[i]-'a';
		s[i*2]=t1[i]-'a';
	}
	n<<=1;
	Init();
	for(int i=1;i<=n;++i)
	{
		Append(i);
		if(!(i&1)&&s[i-1]==s[i])
		{
			dp[i]=dp[i-2];
			rec[i]=i-2;
		}
		else
			dp[i]=INF;
		for(int v=last;len[v]>0;v=sf[v])
		{
			sdp[v]=dp[srec[v]=i-(len[sf[v]]+diff[v])];
			if(diff[v]==diff[fa[v]])
				if(GetMin(sdp[v],sdp[fa[v]]))
					srec[v]=srec[fa[v]];
			if(!(i&1)&&GetMin(dp[i],sdp[v]+1))
				rec[i]=srec[v];
		}
	}
	if(dp[n]<INF)
	{
		printf("%d\n",dp[n]);
		for(int i=n;i;i=rec[i])if(rec[i]/2+1<i/2)
			printf("%d %d\n",rec[i]/2+1,i/2);
	}
	else
		puts("-1");
	return 0;
}
