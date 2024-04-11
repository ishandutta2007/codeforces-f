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

const int N=1000005;
struct edge{
	int v,nxt;
}c[N];
int front[N],cnt;
Finline void add(const int &u,const int &v)
{
	c[++cnt]=(edge){v,front[u]},front[u]=cnt;
}
int dfn[N],low[N],id;
int bel[N],col;
int st[N],top;
void tarjan(int x)
{
	dfn[x]=low[x]=++id;
	st[++top]=x;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(!dfn[c[i].v])
		{
			tarjan(c[i].v);
			chmin(low[x],low[c[i].v]);
		}
		else if(!bel[c[i].v])
		{
			chmin(low[x],dfn[c[i].v]);
		}
	}
	if(dfn[x]==low[x])
	{
		bel[x]=++col;
		while(st[top]!=x)
		{
			bel[st[top]]=col;
			--top;
		}
		--top;
	}
}
void MAIN()
{
	int n,m;
	read(n,m);
	memset(front,0,4*(n+3));
	memset(dfn,0,4*(n+3));
	memset(bel,0,4*(n+3));
	top=0,id=0,cnt=0,col=0;
	int x,y;
	for(int i=1;i<=m;++i)
	{
		read(x,y);
		if(x!=y) add(x,y);
	}
	for(int i=1;i<=n;++i)
	{
		if(!dfn[i])
		{
			tarjan(i);
		}
	}
	if(col==1)
	{
		printf("No\n");
	}
	else
	{
		printf("Yes\n");
		int cnt=0;
		for(int i=1;i<=n;++i)
		{
			if(bel[i]==1)
			{
				++cnt;
			}
		}
		printf("%d %d\n",cnt,n-cnt);
		for(int i=1;i<=n;++i)
		{
			if(bel[i]==1)
			{
				printf("%d ",i);
			}
		}
		printf("\n");
		for(int i=1;i<=n;++i)
		{
			if(bel[i]!=1)
			{
				printf("%d ",i);
			}
		}
		printf("\n");
	}
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
    return 0;
}