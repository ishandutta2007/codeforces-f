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
const int N=5e2+2,mod=998244353,dx[]={1,-1,0,0},dy[]={0,0,1,-1};
V check(int&x){x-=mod,x+=x>>31&mod;}
V cmax(int&x,int y){if(x-y>>31)x=y;}
V cmin(int&x,int y){if(y-x>>31)x=y;}
I Pow(ll t,int x,ll s=1){
	for(;x;x>>=1,t=t*t%mod)if(x&1)s=s*t%mod;
	return s;
}
int T,n,a[N],t[N][N],cnt[N],pos[N];
V dfs(int x,int y,int w){
	if(!cnt[w])return;
	if(x<1||y<1||x>n||y>pos[w]||t[x][y]||y>x)return;
	cnt[w]--,t[x][y]=w,dfs(x,y+1,w),dfs(x-1,y,w),dfs(x,y-1,w),dfs(x+1,y,w);
}
V input(){
	n=getint();
	FOR(i,1,n)a[i]=getint(),cnt[i]=i,pos[a[i]]=i;
	FOR(i,1,n)for(int x=i,y=i,res=a[i];res--;y>1&&!t[x][y-1]?y--:x++)t[x][y]=a[i];
	FOR(i,1,n)FOR(j,1,i)cout<<t[i][j]<<" \n"[j==i];
}
V init(){
	
}
V work(){
	
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen(".out","w",stdout);
//	for(scanf("%d",&T);T--;){
		input();
		init();
		work();
////	}
	return 0;
}