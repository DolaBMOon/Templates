#include<bits/stdc++.h>

const int N=5e6;

int n,a[N],b[N];

void Sort()//Sort a[1..n]
{
	memset(cnt,0,sizeof cnt);
	for(int i=n;i;--i)
		++cnt[a[i]&AND];
	for(int i=0;i<=AND;++i)
		cnt[i]+=cnt[i-1];
	for(int i=n;i;--i)
		b[cnt[a[i]&AND]--]=a[i];
	memset(cnt,0,sizeof cnt);
	for(int i=n;i;--i)
		++cnt[(b[i]>>B)&AND];
	for(int i=0;i<=AND;++i)
		cnt[i]+=cnt[i-1];
	for(int i=n;i;--i)
		a[cnt[(b[i]>>B)&AND]--]=b[i];
}

int main()
{
	return 0;
}
