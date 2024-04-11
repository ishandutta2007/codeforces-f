// Author -- Frame
 
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
 
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
 
#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
 
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
 
const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7ffffffffffffff;
 
uint seed=19260817;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool ismax(_Tp &a,const _Tp &b){return a>b?1:a=b,0;}
template <typename _Tp>Finline bool ismin(_Tp &a,const _Tp &b){return a<b?1:a=b,0;}
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
	while(ch<65||ch>122||(ch>90&&ch<97)) ch=getchar();
	register char *tar=s;
	*tar=ch,ch=getchar();
	while((ch>=65&&ch<=90)||(ch>=97&&ch<=122)) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}
 
const int N=105;
char s[N],t[N],p[N];
int cnt[26];
void MAIN()
{
	memset(cnt,0,sizeof(cnt));
	int ls=read_str(s+1);
	int lt=read_str(t+1);
	int lp=read_str(p+1);
	int pos=0;
	for(int i=1;i<=ls;++i)
	{
		++cnt[s[i]-97];
	}
	for(int i=1;i<=lt;++i)
	{
		--cnt[t[i]-97];
	}
	for(int i=1;i<=lp;++i)
	{
		++cnt[p[i]-97];
	}
	for(int i=0;i<26;++i)
	{
		if(cnt[i]<0)
		{
			printf("NO\n");
			return;
		}
	}
	for(int i=1;i<=lt;++i)
	{
		if(pos<ls&&s[pos+1]==t[i])
		{
			++pos;
		}
	}
	if(pos!=ls)
	{
		printf("NO\n");
		return;
	}
	printf("YES\n");
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
	return 0;
}