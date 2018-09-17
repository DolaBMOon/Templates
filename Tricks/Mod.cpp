#include<bits/stdc++.h>

using namespace std;

const int MOD=998244353;

int Mul(signed a,signed b)
{
	static signed MO=MOD;
	unsigned long long x=(long long)a*b;
	unsigned xh=(unsigned)(x>>32),xl=(unsigned)x,d,m;
	asm
		(
		 "divl %4;\n\t"
		 :"=a"(d),"=d"(m)
		 :"d"(xh),"a"(xl),"r"(MO)
		);
	return m;
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

int main()
{
	return 0;
}
