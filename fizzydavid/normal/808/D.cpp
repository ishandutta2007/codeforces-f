//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
typedef long long ll;
const int Imx=2147483647;
const int mod=1000000007;
const ll Lbig=2e18;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
#define putsi(x) putnum(x),putendl()
#define putsii(x,y) puti(x),putnum(y),putendl()
#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()
inline ll getnum()
{
	register ll r=0;register bool ng=0;register char c;c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')ng=1,c=getchar();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=getchar();
	if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
int n;
ll A[100111],a[100111],pre[100111];
set<ll> st;
void solve()
{
	st.clear();
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[n]/2)
		{
			puts("YES");
			exit(0);
		}
		if(a[i]>a[n]/2)
		{
			if(st.find(a[i]-a[n]/2)!=st.end())
			{
				puts("YES");
				exit(0);
			}
		}
		st.insert(a[i]-a[i-1]);
	}
}
int main()
{
	geti(n);
	for(int i=1;i<=n;i++)geti(A[i]),a[i]=A[i]+a[i-1];
	if(a[n]&1)puts("NO");
	else
	{
		solve();
		for(int i=1;i<=n;i++)a[i]=A[n-i+1]+a[i-1];
		solve();
		puts("NO");
	}
	return 0;
}