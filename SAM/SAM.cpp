#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define clone __clone__

const int N=1000000+10;

int ch[N][26],fa[N],dep[N],last=1,sz=1;

void Append(int c)
{
	//Generalized
	//if((nw=nxt[p=last][c])&&len[p]+1==len[nw])
	//{
	//	last=cur;
	//	return;
	//}
	int p=last,nw=last=++sz;
	dep[nw]=dep[p]+1;
	for(;p&&!ch[p][c];p=fa[p])
		ch[p][c]=nw;
	if(!p)
	{
		fa[nw]=1;
		return;
	}

	int q=ch[p][c];
	if(dep[p]+1==dep[q])
	{
		fa[nw]=q;
		return;
	}
	int clone=++sz;
	dep[clone]=dep[p]+1;
	memcpy(ch[clone],ch[q],104);
	fa[clone]=fa[q];
	fa[nw]=fa[q]=clone;
	for(;p&&ch[p][c]==q;p=fa[p])
		ch[p][c]=clone;
}

int main()
{
	return 0;
}
