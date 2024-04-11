//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
const int mod=1e9+7;
//My i/o stream
struct fastio
{
	char s[100000];
	int it, len;
	fastio() {it=len=0;}
	inline char get()
	{
		if (it<len) return s[it++]; it=0;
		len=fread(s, 1, 100000, stdin);
		if (len==0) return EOF; else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while (c==' '||c=='\n') c=get();
		if (it>0) it--;
		return c!=EOF;
	}
}_buff;
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putchar(' ')
#define putii(x,y) puti(x),puti(y)
#define putiii(x,y,z) putii(x,y),puti(z)
#define putsi(x) putnum(x),putchar('\n')
#define putsii(x,y) puti(x),putsi(y)
#define putsiii(x,y,z) putii(x,y),putsi(z)
inline ll getnum()
{
	ll r=0; bool ng=0; char c; c=_buff.get();
	while (c!='-'&&(c<'0'||c>'9')) c=_buff.get();
	if (c=='-') ng=1, c=_buff.get();
	while (c>='0'&&c<='9') r=r*10+c-'0', c=_buff.get();
	return ng?-r:r;
}
template <class T> inline void putnum(T x)
{
	if (x<0) putchar('-'), x=-x;
	register short a[20]={}, sz=0;
	while (x) a[sz++]=x%10, x/=10;
	if(sz==0) putchar('0');
	for (int i=sz-1; i>=0; i--) putchar('0'+a[i]);
}
inline char getreal() {char c=_buff.get(); while (c<=32) c=_buff.get(); return c;}
ll qpow(ll x, ll k) {return k==0? 1: 1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
const int maxn = 100111;
ll n, a[maxn];
ll b[maxn], c[maxn];
ll getsqrt(ll x)
{
	ll y = sqrt(x);
	while (y*y<x) y++;
	while (y*y>x) y--;
	return y;
}
ll check(ll mx, ll d, ll s)
{
	if (s%2!=d%2) return 1e18;
	ll b = (s+d)/2;
	ll a = (s-d)/2;
	if (a<=mx) return 1e18;
	else return a;
}
int main()
{
	geti(n);
	for (int i=1; i<=n/2; i++)
	{
		geti(a[i]);
	}
	ll mx = 0;
	for (int i=1; i<=n/2; i++)
	{
		ll ans = 1e18;
		for (int j=1; j*j<=a[i]; j++)
		{
			if (a[i]%j==0)
			{
				ans = min(ans, check(mx, j, a[i]/j));
				ans = min(ans, check(mx, a[i]/j, j));
			}
		}
		if (ans>1e17)
		{
			puts("No");
			return 0;
		}
		mx = getsqrt(ans*ans+a[i]);
		c[i*2-1] = ans*ans;
		c[i*2] = ans*ans+a[i];
	}
	puts("Yes");
	for (int i=1; i<=n; i++)
	{
		puti(c[i]-c[i-1]);
	}
	return 0;
}