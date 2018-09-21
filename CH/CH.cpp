#include<bits/stdc++.h>

using namespace std;

#define LL long long

const int MOD=998244353;
const int NB=100;

int Mul(int a,int b)
{
	unsigned long long x=(long long)a*b;
	unsigned xh=(unsigned)(x>>32),xl=(unsigned)x,d,m;
	asm
		(
		 "divl %4;\n\t"
		 :"=a"(d),"=d"(m)
		 :"d"(xh),"a"(xl),"r"(MOD)
		);
	return m;
}

int Qpow(int x,int y=MOD-2)
{
	int res=1;
	for(;y;y>>=1,x=Mul(x,x))if(y&1)
		res=Mul(res,x);
	return res;
}

int U(int x,int y)
{
	return ((x+=y)>=MOD)?(x-MOD):x;
}

void SU(int &x,int y)
{
	((x+=y)>=MOD)?(x-=MOD):0;
}

int D(int x,int y)
{
	return ((x-=y)<0)?(x+MOD):x;
}

void SD(int &x,int y)
{
	((x-=y)<0)?(x+=MOD):0;
}

namespace CHSolver
{

	int n;
	vector<int> f;

	void Muc(vector<int>& A,const vector<int>& B)
	{
		static vector<int> t;
		t.resize(n+n-1);
		for(int i=0;i<n+n-1;++i)
			t[i]=0;
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				SU(t[i+j],Mul(A[i],B[j]));

		for(int i=n+n-2;i>=n;--i)
			for(int j=1;j<=n;++j)
				SU(t[i-j],Mul(t[i],f[j-1]));

		for(int i=0;i<n;++i)
			A[i]=t[i];
	}

	int Solve(vector<int> v,vector<int> _f,LL m)
	{
		n=(f=_f).size();
		if(m<(int)v.size())
			return v[m];

		m-=n-1;
		static vector<int> g,h;
		g.clear();
		h.clear();
		g.resize(n);
		h.resize(n);
		g[0]=h[1]=1;
		for(;m;m>>=1,Muc(h,h))if(m&1)
			Muc(g,h);

		int t=v.size();
		v.resize(n+n-1);
		for(int i=t;i<n+n-1;++i)
			for(int j=1;j<=n;++j)
				SU(v[i],Mul(v[i-j],f[j-1]));

		int ans=0;
		for(int i=0;i<n;++i)
			SU(ans,Mul(g[i],v[n+i-1]));
		return ans;
	}
}

int main()
{
	return 0;
}
