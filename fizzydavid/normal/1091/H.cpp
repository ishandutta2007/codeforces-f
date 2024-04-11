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
const int maxn = 200111;
const int maxsg = 555;
bitset<maxn> msk[maxsg];
bitset<maxn> f;
int sg[maxn], mnp[maxn];
int n;
int ban;
void prework()
{
	for (int i=0; i<maxn; i++)
	{
		if (i==0) sg[i] = 0;
		else
		{
			while (msk[sg[i]][i])
			{
				sg[i]++;
				assert(sg[i]<maxsg);
			}
		}
		msk[sg[i]] |= f<<i;
	}
}
int main()
{
	for (int i=2; i<maxn; i++)
	{
		for (int j=i; j<maxn; j+=i)
		{
			if (!mnp[j]) mnp[j] = i;
		}
	}
	for (int i=2; i<maxn; i++) f[i] = mnp[i]==i||mnp[i/mnp[i]]==i/mnp[i];
	getii(n, ban);
	f[ban] = 0;
	prework();
	ll ans = 0;
	for (int i=1; i<=n; i++)
	{
		int x, y, z;
		getiii(x, y, z);
		int a = y-x-1;
		int b = z-y-1;
		if (a<b) swap(a, b);
		ans ^= sg[a]^sg[b];
	}
	if (ans==0)
	{
		puts("Bob");
		puts("Alice");
	}
	else
	{
		puts("Alice");
		puts("Bob");
	}
	return 0;
}