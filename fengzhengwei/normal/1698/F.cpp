#include<bits/stdc++.h>
#define ll long long
#define LL __int128
#define dd double
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
namespace ppprrr{const int xx=2,mod=2;ll ksm(ll a,ll b){ll ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod,b>>=1;}return ans;}

ll jiec[xx],ni[xx];
ll C(ll n,ll m){return jiec[n]*ni[m]%mod*ni[n-m]%mod;}
void pre()
{
	jiec[0]=1;
	for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
	ni[xx-1]=ksm(jiec[xx-1],mod-2);
	for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
}
	
int prim[xx],mn[xx],Cnt;
void pre(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!mn[i])mn[i]=i,prim[++Cnt]=i;
		for(int j=1;j<=Cnt;j++)
		{
			if(prim[j]*i>n)break;
			mn[i*prim[j]]=prim[j];
			if(i%prim[j]==0)break;
		}
	}
}


int lb(int x){return x&-x;}
ll sum[xx];
void Add(int x,int y){for(;x<xx;x+=lb(x))sum[x]+=y;}
ll ask(int x){ll ans=0;for(;x;x-=lb(x))ans+=sum[x];return ans;}

struct nod{int next,to;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y){cnt++,e[cnt]={h[x],y},h[x]=cnt;}


}
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
//co 
const int xx=1e6+5,mod=998244353;
//mod1e9+7998 
void ad(int &a,int b){(a+=b)>=mod?a-=mod:0;}
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
struct pr{int x,y;};
int n,m,k,q,a[xx],b[xx];
char s[xx];
map<pair<int,int>,int>mp;
vector<pr>ans;
void on(int l,int r)
{
	assert(a[l]==a[r]);
	reverse(a+l,a+r+1);
	ans.push_back({l,r});
}
int main(){
	int T=read();
	while(T--)
	{
		ans.clear(),mp.clear();
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)b[i]=read();
		for(int i=1;i<n;i++)
		{
			int l=a[i],r=a[i+1];
			if(l>r)swap(l,r);
			mp[make_pair(l,r)]++;
		}
		for(int i=1;i<n;i++)
		{
			int l=b[i],r=b[i+1];
			if(l>r)swap(l,r);
			mp[make_pair(l,r)]--;
		}
		int cr=1;
		for(auto it:mp)if(it.second!=0)cr=0;
		if(a[1]!=b[1])cr=0;
		if(a[n]!=b[n])cr=0;
		if(!cr)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		if(n==1)
		{
			cout<<0<<"\n";
			continue;
		}
		//n^3 
		a[n+1]=-1;
		for(int i=1;i<n;i++)
		{
			if(a[i+1]!=b[i+1])
			{
				int id=-1;
				for(int j=i+1;j<=n;j++)
				{
					if(a[j]==b[i+1]&&a[j+1]==a[i])
					{
						id=j;
						break;
					}
				}
				if(id!=-1)
				{
					on(i,id+1);
					continue;
				}
				for(int j=i+1;j<=n;j++)
				{
					if(a[j]==b[i+1]&&a[j-1]==a[i])
					{
						id=j;
						break;
					}
				}
				int op=0;
				for(int k=id;k<=n;k++)
				{
					for(int w=i;w<id;w++)
					{
						if(a[w]==a[k])
						{
							on(w,k);
							op=1;
							break;
						}
					}
					if(op)break;
				}
				if(!op)assert(0);
				
				id=-1;
				for(int j=i+1;j<=n;j++)
				{
					if(a[j]==b[i+1]&&a[j+1]==a[i])
					{
						id=j;
						break;
					}
				}
				if(id!=-1)
				{
					on(i,id+1);
					continue;
				}
				assert(0);
			}
		}
		cout<<ans.size()<<"\n";
		for(auto it:ans)cout<<it.x<<" "<<it.y<<"\n";
		
	}
	pc('1',1);
	return 0;
}