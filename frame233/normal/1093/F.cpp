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

const int N=100005,mod=998244353;
int f[N][105],sum[N][105];
int a[N];
Finline void add(int &a,const int &b){(a+=b)>=mod&&(a-=mod);}
Finline void sub(int &a,const int &b){(a-=b)<0&&(a+=mod);}
int main()
{
	int n,k,len;
	read(n,k,len);
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
		for(int j=1;j<=k;++j) sum[i][j]=sum[i-1][j];
		if(~a[i]) ++sum[i][a[i]];
		else
		{
			for(int j=1;j<=k;++j)
			{
				++sum[i][j];
			}
		}
	}
	f[0][0]=1;
	for(int i=1;i<=n;++i)
	{
		if(~a[i])
		{
			f[i][a[i]]=f[i-1][0];
			if(i>=len&&sum[i][a[i]]-sum[i-len][a[i]]==len)
			{
				sub(f[i][a[i]],f[i-len][0]);
				add(f[i][a[i]],f[i-len][a[i]]);
			}
			f[i][0]=f[i][a[i]];
		}
		else
		{
			for(int j=1;j<=k;++j)
			{
				f[i][j]=f[i-1][0];
				if(i>=len&&sum[i][j]-sum[i-len][j]==len)
				{
					sub(f[i][j],f[i-len][0]);
					add(f[i][j],f[i-len][j]);
				}
				add(f[i][0],f[i][j]);
			}
		}
	}
	printf("%d\n",f[n][0]);
    return 0;
}