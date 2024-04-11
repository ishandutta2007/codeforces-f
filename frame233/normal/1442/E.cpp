// Author -- xyr2005

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;
using std::min;
using std::max;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>inline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>inline void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=200005;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],edge_cnt;
inline void addedge(int u,int v)
{
	c[++edge_cnt]=(edge){v,front[u]};
	front[u]=edge_cnt;
}
int a[N],ans,dp[N][2];
void dfs(int x,int fa)
{
	dp[x][0]=dp[x][1]=-inf;
	if(a[x]==1) dp[x][0]=1;
	else if(a[x]==2) dp[x][1]=1;
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(v==fa) continue;
		dfs(v,x);
		chmax(ans,dp[x][0]+dp[v][1]),chmax(ans,dp[x][1]+dp[v][0]);
		chmax(dp[x][0],dp[v][0]),chmax(dp[x][1],dp[v][1]);
		if(a[x]==1) chmax(dp[x][0],dp[v][1]+1);
		if(a[x]==2) chmax(dp[x][1],dp[v][0]+1);
	}
}
void MAIN()
{
	int n;read(n);
	memset(front,0,(n+3)<<2),edge_cnt=ans=0;
	for(int i=1;i<=n;++i) read(a[i]);
	int x,y;
	for(int i=1;i<n;++i) read(x,y),addedge(x,y),addedge(y,x);
	dfs(1,0);
	printf("%d\n",ans/2+1);
}
int main()
{
	int _;read(_);
	while(_--) MAIN();
	return 0;
}