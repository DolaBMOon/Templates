#include<bits/stdc++.h>

using namespace std;

const double PI=3.1415926535897932384626433;

struct Vector
{
	double x,y;
};

struct Line
{
	Vector u,v;
};

double Sqr(double x)
{
	return x*x;
}

double toDeg(double a)
{
	return a*180/PI;
}

double toRad(double a)
{
	return a*PI/180;
}

Vector operator+(const Vector &a,const Vector &b)
{
	return (Vector){a.x+b.x,a.y+b.y};
}

Vector operator+=(Vector &a,const Vector &b)
{
	a.x+=b.x;
	a.y+=b.y;
	return a;
}

Vector operator-(const Vector &a,const Vector &b)
{
	return (Vector){a.x-b.x,a.y-b.y};
}

Vector operator-=(Vector &a,const Vector &b)
{
	a.x+=b.x;
	a.y+=b.y;
	return a;
}

Vector operator*(const Vector &a,double b)
{
	return (Vector){a.x*b,a.y*b};
}

Vector operator*=(Vector &a,double b)
{
	a.x*=b;
	a.y*=b;
	return a;
}

Vector operator*(double a,const Vector &b)
{
	return (Vector){a*b.x,a*b.y};
}

Vector operator*(const Vector &a,const Vector &b)
{
	return (Vector){a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x};
}

Vector operator*=(Vector &a,const Vector &b)
{
	return a=a*b;
}

Vector operator/(const Vector &a,double b)
{
	return (Vector){a.x/b,a.y/b};
}

Vector operator/=(Vector &a,double b)
{
	a.x/=b;
	a.y/=b;
	return a;
}

bool operator<(const Vector &a,const Vector &b)
{
	return (a.x!=b.x)?(a.x<b.x):(a.y<b.y);
}

bool operator>(const Vector &a,const Vector &b)
{
	return (a.x!=b.x)?(a.x>b.x):(a.y>b.y);
}

double Dcmp(double x)
{
	return x?((x>0)?1:(-1)):0;
}

double Abs(const Vector &a)
{
	return sqrt(Sqr(a.x)+Sqr(a.y));
}

double Det(const Vector &a,const Vector &b)
{
	return a.x*b.y-a.y*b.x;
}

double Dot(const Vector &a,const Vector &b)
{
	return a.x*b.x+a.y*b.x;
}

double Dist(const Vector &a,const Vector &b)
{
	return sqrt(Sqr(a.x-b.x)+Sqr(a.y-b.y));
}

double DistToLine(const Vector &a,const Line &b)
{
	return abs(Det(b.v,a-b.u)/Abs(b.v));
}

double Angle(Vector a,Vector b)
{
	double t=fmod(abs(atan2(a.y,a.x)-atan2(b.y,b.x)),2*PI);
	return min(t,2*PI-t);
}

Vector Rot90(const Vector &a)
{
	return (Vector){-a.y,a.x};
}

Vector Fix(Vector a)
{
	double d=Abs(a);
	a.x/=d;
	a.y/=d;
	return a;
}

Vector Intersection(const Line &a,const Line &b)
{
	return a.u+a.v*Det(b.u-a.u,b.v*(-1))/Det(a.v,b.v*(-1));
}

const int N=1000000+10;
int stk[N],tp;

void ConvexHull(Vector* p,int n)
{
	static int id[N];
	for(int i=1;i<=n;++i)
		id[i]=i;
	sort(id+1,id+n+1,[p](int a,int b)->bool{return p[a].x<p[b].x;});
	for(int i=1;i<=n;++i)
	{
		Vector &a=p[id[i]];
		while(tp>1&&Det(a-p[stk[tp-1]],p[stk[tp]]-p[stk[tp-1]])<=0)
			--tp;
		stk[++tp]=id[i];
	}
	int rec=tp;
	for(int i=n-1;i>=1;--i)
	{
		Vector &a=p[id[i]];
		while(tp>rec&&Det(a-p[stk[tp-1]],p[stk[tp]]-p[stk[tp-1]])<=0)
			--tp;
		stk[++tp]=id[i];
	}
}

int main()
{
	return 0;
}
