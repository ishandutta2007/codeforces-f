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
const int MAXN = 510;
int n,a[MAXN][MAXN],id[MAXN],rev[MAXN],dp[2][MAXN][MAXN];
ll ans[MAXN];
int main(){
//	freopen("in.txt","r",stdin);
	memset(dp,0x3f,sizeof dp);
	read(n);
	rep(i,1,n) rep(j,1,n) read(dp[1^(n&1)][i][j]);
	rep(i,1,n) read(id[i]);
	per(i,n,1) {
		rev[id[i]]=1;
		rep(j,1,n) rep(k,1,n) dp[i&1][j][k]=dp[1^(i&1)][j][k];
		rep(j,1,n) rep(k,1,n) ylmin(dp[i&1][j][k],dp[1^(i&1)][j][id[i]]+dp[1^(i&1)][id[i]][k]);
		rep(j,1,n) rep(k,1,n) if(rev[j] && rev[k]) ans[i]+=dp[i&1][j][k];
	}
	rep(i,1,n) printf("%lld ",ans[i]);
	return 0; 
}