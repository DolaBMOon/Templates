#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>

using namespace std;

#define Line Seg
#define Angle Seg
#define double long double

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

Vector operator+(const Vector& a,const Vector& b)
{
	return (Vector){a.x+b.x,a.y+b.y};
}

Vector operator-(const Vector& a,const Vector& b)
{
	return (Vector){a.x-b.x,a.y-b.y};
}

Vector operator*(const Vector& a,double b)
{
	return (Vector){a.x*b,a.y*b};
}

Vector operator*(double a,const Vector& b)
{
	return (Vector){a*b.x,a*b.y};
}

Vector operator*(const Vector& a,const Vector& b)
{
	return (Vector){a.x*a.x-b.y*b.y,a.x*b.y+a.y*b.x};
}

Vector operator/(const Vector& a,double b)
{
	return (Vector){a.x/b,a.y/b};
}

double Dcmp(double x)
{
	return x?((x>0)?1:(-1)):0;
}

double Abs(const Vector& a)
{
	return sqrt(Sqr(a.x)+Sqr(a.y));
}

double Det(const Vector& a,const Vector& b)
{
	return a.x*b.y-a.y*b.x;
}

double Dot(const Vector& a,const Vector& b)
{
	return a.x*b.x+a.y*b.x;
}

double Dist(const Vector& a,const Vector& b)
{
	return sqrt(Sqr(a.x-b.x)+Sqr(a.y-b.y));
}

double dist(const Vector& a,const Line& b)
{
	return abs(Det(b.v,a-b.u)/Abs(b.v));
}

Vector Rot90(const Vector& a)
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

Vector Intersection(const Line& a,const Line& b)
{
	return a.u+a.v*Det(b.u-a.u,b.v*(-1))/Det(a.v,b.v*(-1));
}

int main()
{
	return 0;
}
