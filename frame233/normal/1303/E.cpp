// Author -- Frame

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
const double eps=1e-10;

uint seed=19260817;
const uint _RAND_MAX_=4294967295u;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp &x)
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

const int N=405;
char s[N],t[N];
bool check(char *s,char *t,int n,int m)
{
	int pos=1;
	for(int i=1;i<=m;++i)
	{
		while(pos<=n&&s[pos]!=t[i]) ++pos;
		if(pos>n) return false;
		++pos;
	}
	return true;
}
int dp[N][N];
bool check(int k,char *s,char *t,int n,int m)
{
	char *T=t+k;
	for(int i=0;i<=n;++i)
	{
		for(int j=0;j<=k;++j)
		{
			dp[i][j]=-inf;
		}
	}
	dp[0][0]=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<=k;++j)
		{
			if(dp[i-1][j]>=0)
			{
				if(dp[i-1][j]<m-k&&s[i]==T[dp[i-1][j]+1]) chmax(dp[i][j],dp[i-1][j]+1);
				chmax(dp[i][j],dp[i-1][j]);
			}
			if(dp[i-1][j-1]>=0)
			{
				if(j&&s[i]==t[j]) chmax(dp[i][j],dp[i-1][j-1]);
			}
		}
	}
	return dp[n][k]==m-k;
}
void MAIN()
{
	int n=read_str(s+1);
	int m=read_str(t+1);
	if(check(s,t,n,m))
	{
		printf("YES\n");
		return;
	}
	for(int pos=1;pos<m;++pos)
	{
		if(check(pos,s,t,n,m))
		{
			printf("YES\n");
			return;
		}
	}
	printf("NO\n");
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
	return 0;
}