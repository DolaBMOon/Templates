#include<bits/stdc++.h>

using namespace std;

#define Poly vector<double>
#define Poly2 vector<Vector>

const int N=1e6+10;
const double PI=3.141592653589793;

struct Vector
{
	double x,y;
};

Vector operator*(const Vector& a,const Vector& b)
{
	return (Vector){a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x};
}

Vector operator+(const Vector& a,const Vector& b)
{
	return (Vector){a.x+b.x,a.x+b.y};
}

Vector operator-(const Vector& a,const Vector& b)
{
	return (Vector){a.x-b.x,a.y-b.y};
}

void operator+=(Vector& a,const Vector& b)
{
	a.x+=b.x;
	a.y+=b.y;
}

void FFT(Poly2& A,bool fl)
{
	int L=A.size();
	if(fl)
	{
		for(Vector& v:A)
		{
			v.x/=L;
			v.y/=L;
		}
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
	static Vector w[N]={1};

	for(int i=1;i<L;i<<=1)
	{
		Vector t=(Vector){cos(PI/i),sin(PI/i)};
		for(int j=1;j<i;++j)
			w[j]=w[j-1]*t;
		for(int j=0;j<L;j+=(i<<1))
		{
			for(int k=0;k<i;++k)
			{
				t=A[i+j+k]*w[k];
				A[i+j+k]=A[j+k]-t;
				A[j+k]+=t;
			}
		}
	}
}

Poly operator*(Poly A,Poly B)
{
	int need=A.size()+B.size()-1,L;
	for(L=1;L<need;L<<=1);
	static Poly2 C;
	C.resize(L);
	for(int i=0;i<(int)A.size();++i)
		C[i].x=A[i];
	for(int i=0;i<(int)B.size();++i)
		C[i].y=B[i];
	FFT(C,false);
	for(Vector& v:C)
		v=v*v;
	FFT(C,true);
	static Poly D;
	D.resize(need);
	for(int i=0;i<need;++i)
		D[i]=C[i].y*0.5;
	return D;
}

int main()
{
	return 0;
}
