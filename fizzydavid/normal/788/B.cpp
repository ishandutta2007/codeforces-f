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
const ll Lbg=2e18;
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
int n,m,f[1000111],g[1000111],cnt2;
bool v[1000111];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
int main()
{
	getii(n,m);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		getii(x,y);
		f[gf(x)]=gf(y);
		g[x]++;
		g[y]++;
		v[x]=v[y]=1;
		if(x==y)g[x]-=2,cnt2++;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)if(v[i]&&gf(i)==i)cnt++;
	if(cnt==1)
	{
		ll ans=1ll*cnt2*(m-cnt2)+1ll*cnt2*(cnt2-1)/2;
		for(int i=1;i<=n;i++)ans+=1ll*g[i]*(g[i]-1)/2;
		cout<<ans<<endl;
	}
	else puts("0");
	return 0;
}