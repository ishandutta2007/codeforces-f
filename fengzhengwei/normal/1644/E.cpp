#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
namespace zhs
{
	const int xx=5e5+5,mod=998244353;
	ll jiec[xx],ni[xx];
	ll ksm(ll a,ll b)
	{
		ll ans=1;
		while(b)
		{
			if(b&1)ans*=a,ans%=mod;
			a*=a,a%=mod,b>>=1;
		}
		return ans;
	}
	ll C(ll n,ll m){return jiec[n]*ni[m]%mod*ni[n-m]%mod;}
	void pre()
	{
		jiec[0]=1;
		for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
		ni[xx-1]=ksm(jiec[xx-1],mod-2);
		for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
	}
}
namespace pr
{
	const int xx=5e5+5,mod=998244353;
	int prim[xx],mn[xx],cnt;
	void pre(int n)
	{
		for(int i=2;i<=n;i++)
		{
			if(!mn[i])mn[i]=i,prim[++cnt]=i;
			for(int j=1;j<=cnt;j++)
			{
				if(prim[j]*i>n)break;
				mn[i*prim[j]]=prim[j];
				if(i%prim[j]==0)break;
			}
		}
	}
}
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
// 
const int xx=5e5+5,mod=998244353;
ll ksm(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod,b>>=1;
	}
	return ans;
}
int n,m,k,q,a[xx];
char s[xx];
int t[505];
int main(){
	int T=read();
	while(T--)
	{
		n=read();
		scanf("%s",s+1);
		t['R']=t['D']=0;
		int m=strlen(s+1);
		for(int i=1;i<=m;i++)t[s[i]]=1;
		if(!t['R']||!t['D'])
		{
			cout<<n<<"\n";
			continue;
		}
		if(s[1]=='D')
		{
			for(int i=1;i<=m;i++)
			{
				if(s[i]=='D')s[i]='R';
				else s[i]='D';
			}
		}
		int remr=n-1,remd=n-1;
		for(int i=1;i<=m;i++)
		{
			if(s[i]=='R')remr--;
			if(s[i]=='D')remd--;
		}
		int fir=0;
		for(int i=1;i<=m;i++)
		{
			if(s[i]=='D')
			{
				fir=i;
				break;
			}
		}
		ll ans=1ll*n*n;//m 
		int X=1,Y=fir+remr;
		for(int i=fir;i<=m;i++)
		{
			if(s[i]=='D')X++;
			else Y++,ans-=(X-1);
		}
//		cout<<ans<<"!!\n";
		X=1+remd,Y=fir;
		for(int i=fir;i<=m;i++)
		{
			if(s[i]=='D')X++,ans-=(Y-fir);
			else Y++;
		}
		ans-=1ll*(n-1)*(fir-1);
		cout<<ans<<"\n";
	}
	pc('1',1);
	return 0;
}