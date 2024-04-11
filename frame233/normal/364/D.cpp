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
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar++=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *tar++=ch,ch=getchar();
	return *tar=0,tar-s;
}

const int N=1000005;
ll a[N];
int cnt[6725];
int main()
{
	int n;read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	int L=(n+1)>>1;
	ll ans=0;
	for(int _=1;_<=10;++_)
	{
		int x=rnd()%n+1;
		ll t=a[x];
		std::vector<ll> d;
		for(int i=1;1LL*i*i<=t;++i)if(t%i==0)
		{
			d.pb(i);
			if(1LL*i*i!=t)d.pb(t/i);
		}
		std::sort(d.begin(),d.end());
		std::vector<ll> v;
		for(int i=1;i<=n;++i)v.pb(gcd(a[i],a[x]));
		memset(cnt,0,sizeof(cnt));
		std::sort(v.begin(),v.end());
		for(int i=0;i<SZ(v);++i)
		{
			int j=i;
			while(j+1<SZ(v)&&v[j+1]==v[i])++j;
			for(int k=0;k<SZ(d)&&d[k]<=v[i];++k)if(v[i]%d[k]==0)cnt[k]+=j-i+1;
			i=j;
		}
		for(int i=0;i<SZ(d);++i)if(cnt[i]>=L)chmax(ans,d[i]);
	}
	printf("%lld\n",ans);
	return 0;
}