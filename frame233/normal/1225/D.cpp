// Author -- Frame
 
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
 
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
 
const int N=100005;
bool pr[N];
int a[N],pos;
void init(int n)
{
	for(int i=2;i<=n;++i)
	{
		if(!pr[i])
		{
			a[++pos]=i;
		}
		for(int j=1;j<=pos&&i*a[j]<=n;++j)
		{
			pr[i*a[j]]=1;
			if(!(i%a[j]))
			{
				break;
			}
		}
	}
}
struct node{
	int x,y;
	void print()
	{
		printf("(%d , %d) , ",x,y);
	}
	Finline bool operator < (const node &o)const
	{
		return x==o.x?y<o.y:x<o.x;
	}
	Finline bool operator == (const node &o)const
	{
		return x==o.x&&y==o.y;
	}
};
struct Node{
	node a,b,c,d,e,f;
	void print()
	{
		a.print();
		b.print();
		c.print();
		d.print();
		e.print();
		f.print();
		printf("\n");
	}
	Finline bool operator < (const Node &o)const
	{
		return a==o.a?b==o.b?c==o.c?d==o.d?e==o.e?f<o.f:e<o.e:d<o.d:c<o.c:b<o.b:a<o.a;
	}
};
std::map<Node,int> mp;
int k;
Node divide(int x)
{
	Node cur={{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};
	int cnt=0;
	int _=x;
	for(int i=1;i<=pos&&a[i]*a[i]<=_;++i)
	{
		if(!(x%a[i]))
		{
			int tmp=0;
			while(!(x%a[i]))
			{
				++tmp;
				x/=a[i];
			}
			tmp%=k;
			if(tmp)
			{
				++cnt;
				if(cnt==1) cur.a={a[i],tmp};
				else if(cnt==2) cur.b={a[i],tmp};
				else if(cnt==3) cur.c={a[i],tmp};
				else if(cnt==4) cur.d={a[i],tmp};
				else if(cnt==5) cur.e={a[i],tmp};
				else if(cnt==6) cur.f={a[i],tmp};
			}
		}
	}
	if(x>1)
	{
		++cnt;
		if(cnt==1) cur.a={x,1};
		else if(cnt==2) cur.b={x,1};
		else if(cnt==3) cur.c={x,1};
		else if(cnt==4) cur.d={x,1};
		else if(cnt==5) cur.e={x,1};
		else if(cnt==6) cur.f={x,1};
	}
	return cur;
}
int main()
{
	init(100000);
	int n;
	read(n,k);
	Node cur,tmp;
	int x;
	ll ans=0;
	for(int i=1;i<=n;++i)
	{
		read(x);
		cur=divide(x);
		tmp={cur.a.x?(node){cur.a.x,k-cur.a.y}:(node){0,0},cur.b.x?(node){cur.b.x,k-cur.b.y}:(node){0,0},cur.c.x?(node){cur.c.x,k-cur.c.y}:(node){0,0},cur.d.x?(node){cur.d.x,k-cur.d.y}:(node){0,0},cur.e.x?(node){cur.e.x,k-cur.e.y}:(node){0,0},cur.f.x?(node){cur.f.x,k-cur.f.y}:(node){0,0}};
		ans+=mp[tmp];
		++mp[cur];
	}
	printf("%lld\n",ans);
    return 0;
}