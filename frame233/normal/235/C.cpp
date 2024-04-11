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

const int N=2000005;
struct SAM{
	struct Node{
		int fa,len;
		int ch[26];
	}f[N];
	int node_cnt,last;
	Finline SAM():node_cnt(1),last(1){}
	int dp[N];
	void insert(int c)
	{
		int cur=++node_cnt;
		f[cur].len=f[last].len+1;
		dp[cur]=1;
		int p=last;
		while(p&&!f[p].ch[c])
		{
			f[p].ch[c]=cur;
			p=f[p].fa;
		}
		if(!p)
		{
			f[cur].fa=1;
		}
		else
		{
			int q=f[p].ch[c];
			if(f[q].len==f[p].len+1)
			{
				f[cur].fa=q;
			}
			else
			{
				int clone=++node_cnt;
				memcpy(f[clone].ch,f[q].ch,104);
				f[clone].fa=f[q].fa;
				f[clone].len=f[p].len+1;
				f[cur].fa=f[q].fa=clone;
				while(p&&f[p].ch[c]==q)
				{
					f[p].ch[c]=clone;
					p=f[p].fa;
				}
			}
		}
		last=cur;
	}
	void Dp()
	{
		int maxx=0;
		for(int i=1;i<=node_cnt;++i) chmax(maxx,f[i].len);
		static int tax[N],A[N];
		memset(tax,0,4*(maxx+3));
		for(int i=1;i<=node_cnt;++i) ++tax[f[i].len];
		for(int i=1;i<=maxx;++i) tax[i]+=tax[i-1];
		for(int i=1;i<=node_cnt;++i) A[tax[f[i].len]--]=i;
		for(int i=node_cnt;i>1;--i) dp[f[A[i]].fa]+=dp[A[i]];
	}
	bool used[N];
	int t[N],pos;
	ll solve(char *s,int n)
	{
		int len=n<<1;
		--len;
		int v=1,l=0,tmp;
		ll ans=0;
		for(int i=1;i<=len;++i)
		{
			tmp=s[i]-97;
			while(v>1&&!f[v].ch[tmp])
			{
				v=f[v].fa;
				l=f[v].len;
			}
			if(f[v].ch[tmp])
			{
				v=f[v].ch[tmp];
				++l;
			}
			if(l<n)
			{
				continue;
			}
			while(f[v].fa&&f[f[v].fa].len>=n)
			{
				v=f[v].fa;
				l=f[v].len;
			}
			if(!used[v])
			{
				ans+=dp[v];
				used[v]=1;
				t[++pos]=v;
			}
		}
		while(pos) used[t[pos--]]=0;
		return ans;
	}
}sam;
char s[N];
int main()
{
	int len=read_str(s+1);
	for(int i=1;i<=len;++i)
	{
		sam.insert(s[i]-97);
	}
	sam.Dp();
	int _;
	read(_);
	while(_--)
	{
		int n=read_str(s+1);
		for(int i=1;i<n;++i)
		{
			s[i+n]=s[i];
		}
		printf("%lld\n",sam.solve(s,n));
	}
    return 0;
}