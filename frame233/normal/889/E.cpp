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
std::map<ll,ll> dp;
ll a[N];
int main()
{
	int n;read(n);
	for(int i=1;i<=n;++i) read(a[i]);
	dp[a[1]-1]=0;
	for(int i=1;i<n;++i)
	{
		while(!dp.empty())
		{
			auto it=--dp.end();
			if(it->first<a[i+1]) break;
			ll j=it->first;
			chmax(dp[j%a[i+1]],it->second+1LL*i*(j-j%a[i+1]));
			chmax(dp[a[i+1]-1],it->second+1LL*i*a[i+1]*((j-(a[i+1]-1))/a[i+1]));
			dp.erase(it);
		}
	}
	ll ans=0;
	for(auto it:dp) chmax(ans,1LL*it.first*n+it.second);
	printf("%lld\n",ans);
	return 0;
}