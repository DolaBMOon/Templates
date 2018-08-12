#include<bits/stdc++.h>

const int _B=4e5;

namespace A
{
//I don't know EOF
	char Nc()
	{
		static char buf[_B],*p=buf,*q=buf;
		return ((p==q)&&(q=buf+fread(buf,1,_B,stdin))==(p=buf))?0:*(p++);
	}

	int Read()
	{
		char ch;
		while(!isdigit(ch=Nc()));
		int sum=ch-48;
		while(isdigit(ch=Nc()))
			sum=sum*10+ch-48;
		return sum;
	}

}

namespace B
{
//I know EOF
	bool BADEND;

	char Nc()
	{
		static char buf[_B],*p=buf,*q=buf;
		return (BADEND|=((p==q)&&(q=buf+fread(buf,1,_B,stdin))==(p=buf)))?0:(*(p++));
	}

	int Read(int &x)
	{
		char ch;
		while(!isdigit(ch=Nc())&&!BADEND);
		if(BADEND)
			return -1;
		x=ch-48;
		while(isdigit(ch=Nc()))
			x=x*10+ch-48;
		return 0;
	}

}

int main()
{
	return 0;
}
