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
const int N=3e5+2,INF=0x3f3f3f3f;
ll sum;
int T,n,tot,a[N];
V input(){
	n=getint(),sum=0;
	FOR(i,1,n)a[i]=getint(),sum+=a[i];
}
V init(){
	
}
V work(int d=0){
	if(sum%n!=0)return void(cout<<"-1\n");
	cout<<3*(n-1)<<'\n';
	FOR(i,2,n){
		cout<<1<<' '<<i<<' '<<(i-a[i]%i)%i<<'\n';
		cout<<i<<' '<<1<<' '<<(a[i]+i-1)/i<<'\n';
	}
	FOR(i,2,n)cout<<1<<' '<<i<<' '<<sum/n<<'\n';
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