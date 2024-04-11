/*mjytxdy!*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fir first
#define sec second
#define all(x) x.begin(),x.end()
#define size(x) ((int)x.size())
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define inl inline
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define trv(i,u) for(int i=head[u];i;i=e[i].next)
#define lb(x) ((x)&(-(x)))
#define lson root<<1
#define rson root<<1|1
#define debug(x) cout<<#x":"<<x<<'\n'
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
typedef long long ll;
template<class T>inl bool ylmin(T &a,T b){return a<b?0:(a=b,1);}
template<class T>inl bool ylmax(T &a,T b){return a>b?0:(a=b,1);}
template<class T>inl T abs(T x){return x<0?-x:x;}
inl char read(){
	static const int IO_LEN=1024*1024;
	static char buf[IO_LEN],*ioh,*iot;
	if(ioh==iot){
		iot=(ioh=buf)+fread(buf,1,IO_LEN,stdin);
		if(ioh==iot) return -1;
	}
	return *ioh++;
}
template<class T>inl void read(T &x){
	static int iosig;static char ioc;
	for(iosig=0,ioc=read();!isdigit(ioc);ioc=read()) if(ioc=='-') iosig=1;
	for(x=0;isdigit(ioc);ioc=read())x=(x<<1)+(x<<3)+(ioc^'0');
	if(iosig) x=-x;
}
const int MAXN = 5e5+10;
int n,m,u,v,col[MAXN],vis[MAXN];
vector<int> G[MAXN];
pii a[MAXN];
int main(){
	//freopen("in.txt","r",stdin);
	read(n),read(m);
	rep(i,1,m) read(u),read(v),G[u].pb(v),G[v].pb(u);
	rep(i,1,n) read(a[i].fir),a[i].sec=i;
	sort(a+1,a+n+1);
	rep(i,1,n){
		int u=a[i].sec,cnt=0;
		for(auto v:G[u]) if(col[v] && !vis[col[v]] && col[v]<=a[i].fir) vis[col[v]]=1,cnt++;
		if(cnt!=a[i].fir-1 || vis[a[i].fir]) puts("-1"),exit(0);
		for(auto v:G[u]) vis[col[v]]=0;
		col[u]=a[i].fir;
	}
	rep(i,1,n) printf("%d ",a[i].sec);
	return 0;
}