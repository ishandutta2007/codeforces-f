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
const int MAXN = 2e5+10;
int T,n,a[MAXN];
int main(){
	//freopen("in.txt","r",stdin);
	for(read(T);T;T--){
		read(n);
		rep(i,1,n) read(a[i]);
		int flag1=1,flag2=1;
		per(i,n,1) flag1&=(a[i]==i);
		int l=1,r=n;
		while(a[l]==l) l++;while(a[r]==r) r--;
		rep(i,l,r) if(a[i]==i) flag2=0;
		printf("%d\n",flag1?0:(flag2?1:2));
	}
	return 0;
}