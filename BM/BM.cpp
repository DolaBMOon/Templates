#include<bits/stdc++.h>

using namespace std;

#define LL long long

const int MOD=998244353;
const int NB=1000;

int Mul(int a,int b)
{
	return (LL)a*b%MOD;
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

void Extend(vector<int> &v,int x)
{
	if((int)v.size()<x)
		v.resize(x);
}

vector<int> BM(vector<int> v)
{
	static vector<int> f,g,t;
	f.clear();
	g.clear();
	f.reserve(NB);
	g.reserve(NB);
	t.reserve(NB);
	int fp=0,fw=0;

	for(int i=0;i<(int)v.size();++i)
	{
		int x=v[i];
		if((int)f.size()<=i)
			for(int j=0;j<(int)f.size();++j)
				SD(x,Mul(f[j],v[i-j-1]));
		if(x)
		{
			if(f.empty())
				f.resize(i);
			else
			{
				t=f;
				Extend(f,i-fp+g.size());
				int y=Mul(x,Qpow(fw));
				SU(f[i-fp-1],y);
				for(int j=0;j<(int)g.size();++j)
					SD(f[i-fp+j],Mul(y,g[j]));
				g=t;
			}
			fp=i;
			fw=x;
		}
	}
	return f;
}

int main()
{
	return 0;
}
