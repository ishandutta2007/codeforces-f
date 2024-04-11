// luogu-judger-enable-o2
// Author -- Frame
 
#pragma GCC optimize(2)
 
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
 
#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
 
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
 
const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-8;
 
uint seed=19260817;
const uint _RAND_MAX_=4294967295u;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}
 
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp& x)
{
    register char ch(getchar());
    bool f(false);
    while(ch<48||ch>57) f|=ch==45,ch=getchar();
    x=ch&15,ch=getchar();
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
    if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args)
{
    read(t);read(args...);
}
Finline int read_str(char *s)
{
    register char ch(getchar());
    while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
    register char *tar=s;
    *tar=ch,ch=getchar();
    while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
    return tar-s+1;
}
 
const int N=200005;
char s[N],t[N];
int n,m;
int f[N],g[N];
int match(int st)
{
	int pos=0;
	for(int i=st;i<=n;++i)
	{
		if(s[i]==t[pos+1]) ++pos;
		if(pos==m) return i;
	}
	return -1;
}
int main()
{
	n=read_str(s+1);
	m=read_str(t+1);
	int ans=n-match(1);
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(~match(mid)) l=mid;
		else r=mid-1;
	}
	chmax(ans,l-1);
	int pos=0;
	for(int i=1;i<=n;++i)
	{
		if(s[i]==t[pos+1])
		{
			++pos;
			f[pos]=i;
		}
		if(pos==m) break;
	}
	pos=m+1;
	for(int i=n;i>=1;--i)
	{
		if(s[i]==t[pos-1])
		{
			--pos;
			g[pos]=i;
		}
		if(pos==1) break;
	}
	for(int i=0;i<m;++i)
	{
		chmax(ans,g[i+1]-f[i]-1);
	}
	printf("%d\n",ans);
    return 0;
}