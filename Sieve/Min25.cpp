#include<bits/stdc++.h>

using namespace std;

#define int long long

const int M=1e6;
const int MOD=1e9+7;

void SU(int &x,int y)
{
	x+=y;
	while(x<0)
		x+=MOD;
	while(x>=MOD)
		x-=MOD;
}

int U(int x,int y)
{
	SU(x,y);
	return x;
}

int Fix(int x)
{
	while(x<0)
		x+=MOD;
	while(x>=MOD)
		x-=MOD;
	return x;
}

int n;
int m,B,id[M],id2[M];
int w[M],s0[M],s1[M];

int p[M],totp,sp[M];
bool vis[M];

void Prework()
{
	for(int i=2;i<=B;++i)
	{
		if(!vis[i])
		{
			p[++totp]=i;
			sp[totp]=U(sp[totp-1],i);
		}
		for(int j=1;j<=totp&&p[j]*i<=B;++j)
		{
			vis[p[j]*i]=true;
			if(i%p[j]==0)
				break;
		}
	}
}

int Sm(int x,int y)
{
	if(x<2||p[y]>x)
		return 0;
	int k=(x<B)?id[x]:id2[n/x];
	int ans=Fix(s1[k]-sp[y-1]-(s0[k]-(y-1))+((y==1)?2:0));
	for(int i=y,j=sqrt(x);i<=totp&&p[i]<=j;++i)
	{
		int t=p[i];
		for(int e=1;t*p[i]<=x;++e,t*=p[i])
			ans+=(int)Sm(x/t,i+1)*(p[i]^e)+(p[i]^(e+1));
		ans=(ans%MOD+MOD)%MOD;
	}
	return ans;
}

signed main()
{
	scanf("%lld",&n);
	B=sqrt(n);
	Prework();
	for(int i=1,j,k;i<=n;i=j+1)
	{
		k=n/i;
		j=n/k;
		w[++m]=n/i;
		s0[m]=U(w[m]%MOD,-1);
		s1[m]=U(((w[m]&1)?(w[m]%MOD*(((w[m]+1)>>1)%MOD)%MOD):(((w[m]>>1)%MOD*((w[m]+1)%MOD))%MOD)),-1);
		if(k<B)
			id[k]=m;
		else
			id2[j]=m;
	}
	for(int i=1;i<=totp;++i)
	{
		int pipi=(int)p[i]*p[i];
		for(int j=1;j<=m&&pipi<=w[j];++j)
		{
			int t=w[j]/p[i];
			int k=((t<B)?id[t]:id2[n/t]);
			SU(s0[j],(i-1)-s0[k]);
			SU(s1[j],(int)p[i]*(sp[i-1]-s1[k])%MOD);
		}
	}
	printf("%lld",U(Sm(n,1),1));
	return 0;
}
