#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define Poly vector<int>

const int N=1e6+10;
const int MOD=998244353;
const int g=3;

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

ostream& operator<<(ostream &os,const Poly &p)
{
	os<<"{";
	for(int i=0;i<(int)p.size()-1;++i)
		os<<p[i]<<",";
	os<<p.back()<<"}";
	return os;
}

void FFT(Poly &A,bool fl)
{
	int L=A.size();
	if(fl)
	{
		int t=Qpow(L);
		for(int& v:A)
			v=Mul(v,t);
		reverse(A.begin()+1,A.end());
	}
	for(int i=1,j=L>>1,k;i<L;++i,j^=k)
	{
		if(i<j)
			swap(A[i],A[j]);
		k=L>>1;
		while(j&k)
		{
			j^=k;
			k>>=1;
		}
	}

	static int w[N]={1};

	for(int i=1;i<L;i<<=1)
	{
		int t=Qpow(g,(MOD-1)/(i<<1));
		for(int j=1;j<i;++j)
			w[j]=Mul(w[j-1],t);
		for(int j=0;j<L;j+=(i<<1))
		{
			for(int k=0;k<i;++k)
			{
				t=Mul(A[i+j+k],w[k]);
				A[i+j+k]=D(A[j+k],t);
				SU(A[j+k],t);
			}
		}
	}
}

Poly Inv(Poly A)
{
	int L=A.size();
	if(L==1)
		return Poly(1,Qpow(A[0]));
	Poly t=A;
	t.resize((L+1)>>1);
	Poly B=Inv(t);
	int p=1;
	for(;p<(L<<1);p<<=1);
	t=A;
	t.resize(p);
	FFT(t,false);
	B.resize(p);
	FFT(B,false);
	for(int i=0;i<p;++i)
		B[i]=Mul(D(2,Mul(t[i],B[i])),B[i]);
	FFT(B,true);
	B.resize(L);
	return B;
}

Poly operator*(Poly A,Poly B)
{
	int need=A.size()+B.size()-1,L;
	for(L=1;L<need;L<<=1);
	A.resize(L);
	FFT(A,false);
	B.resize(L);
	FFT(B,false);
	for(int i=0;i<L;++i)
		A[i]=Mul(A[i],B[i]);
	FFT(A,true);
	A.resize(need);
	return A;
}

Poly operator/(Poly A,Poly B)
{
	int n=A.size(),m=B.size(),p=1,t=n-m+1;
	for(;p<(t<<1);p<<=1);
	reverse(A.begin(),A.end());
	A.resize(t);
	reverse(B.begin(),B.end());
	B.resize(t);
	A=A*Inv(B);
	A.resize(t);
	reverse(A.begin(),A.end());
	return A;
}

Poly operator-(Poly A,Poly B)
{
	for(int i=B.size()-1;i>=0;--i)
		SD(A[i],B[i]);
	return A;
}

Poly operator%(Poly A,Poly B)
{
	A=A-A/B*B;
	A.resize(B.size()-1);
	return A;
}

int main()
{
	return 0;
}
