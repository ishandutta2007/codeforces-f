#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define REP(u) for(int i=h[u],v;v=e[i].t,i;i=e[i].n)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=2e5+1,mod=998244353;
V check(int&x){x-=mod,x+=x>>31&mod;}
V cmax(int&x,int y){if(x-y>>31)x=y;}
V cmin(int&x,int y){if(y-x>>31)x=y;}
I Pow(ll t,int x,ll s=1){
	for(;x;x>>=1,t=t*t%mod)if(x&1)s=s*t%mod;
	return s;
}
int T,n,m,cnt[N],ans[N];
vector<int>t[N];
V input(){
	FOR(i,1,m)t[i].clear();
	FOR(i,1,n)cnt[i]=0;
	n=getint(),m=getint();
	FOR(i,1,m)ROF(j,getint(),1)t[i].push_back(getint());
}
V init(){
	
}
V work(){
	int lim=m+1>>1,p;
	FOR(i,1,m)if(t[i].size()==1)cnt[t[i].front()]++;
	FOR(i,1,n)if(cnt[i]>lim)return void(cout<<"NO\n");
	cout<<"YES\n";
	FOR(i,1,m)if(t[i].size()>1){
		p=t[i].front();
		if(cnt[p]==lim)p=t[i].back();
		cnt[p]++,cout<<p<<" \n"[i==m];
	}
	else cout<<t[i].front()<<" \n"[i==m];
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen(".out","w",stdout);
	for(scanf("%d",&T);T--;){
		input();
		init();
		work();
	}
	return 0;
}