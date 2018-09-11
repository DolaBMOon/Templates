#include<bits/stdc++.h>

using namespace std;

const int N=1e6+10;
const int ALPHA=26;

int s[N],len[N],fa[N],ch[N][ALPHA],last,tot;

void Init()
{
	s[0]=-233;
	last=len[0]=0;
	len[1]=-1;
	fa[0]=tot=1;
	fa[1]=0;
}

void Append(int k)
{
	int p=last,c=s[k];
	for(;c!=s[k-len[p]-1];p=fa[p]);
	if(!ch[p][c])
	{
		last=++tot;
		len[last]=len[p]+2;
		int t=fa[p];
		for(;c!=s[k-len[t]-1];t=fa[t]);
		fa[last]=t=ch[t][c];
		ch[p][c]=last;
	}
	else
		last=ch[p][c];
}

int main()
{
	return 0;
}
