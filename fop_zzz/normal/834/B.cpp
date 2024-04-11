#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <cstring>
#include <ctime>
#include <vector>
#define ll long long
#define N 1020
#define lson x*2
#define rson x*2+1
#define For(i,j,k) for(int i=j;i<=k;i++)
#define Dow(i,j,k) for(int i=k;i>=j;i--)
#define clr(x, c) memset(x, c, sizeof(x))
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){write(x);puts("");};
char s[2000001];
int n,L[2001],R[2001],k,tmp;
int main()
{
	n=read();k=read();
	scanf("\n%s",s+1);
	For(i,'A','Z')	L[i]=1e9;
	For(i,1,n)
	{
		L[s[i]]=min(L[s[i]],i);
		R[s[i]]=max(R[s[i]],i);
	}
	For(i,1,n)
	{
		For(c,'A','Z')
			if(i==L[c])	tmp++;
		if(tmp>k)	{puts("YES");return 0;}
		For(c,'A','Z')	
			if(i==R[c])	tmp--;
	}
	puts("NO");
}