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
const int N=5e5+1,mod=1e9+7;
V check(int&x){x-=mod,x+=x>>31&mod;}
V cmax(int&x,int y){if(x-y>>31)x=y;}
V cmin(int&x,int y){if(y-x>>31)x=y;}
int T,n;
char a[N];
V input(){
	scanf("%d%s",&n,a);
	int c0=0,c1=0,ans=0;
	FOR(i,0,n-1){
		if(a[i]=='>')c0++;
		if(a[i]=='<')c1++;
	}
	if(!c0||!c1)return void(cout<<n<<'\n');
	FOR(i,0,n-1)
		if(a[i]=='-'||a[(i+n-1)%n]=='-')
			ans++;
	cout<<ans<<'\n';
}
V init(){
}
V work(int u=0,int v=0){
	
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