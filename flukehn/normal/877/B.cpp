#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define debug(x) cerr<<#x" = "<<x<<endl
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef pair<int,int> pii;
typedef long long ll;
const int inf=~0u>>1,MOD=1e9+7;/*
char *TT,*mo,but[(1<<15)+2];
#define getchar() ((TT==mo&&(mo=((TT=but)+fread(but,1,1<<15,stdin)),TT==mo))?-1:*TT++)//*/
inline int rd() {
	int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
	while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const int N=5011;
char s[N];
int f[N],g[N];
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	rep(i,1,n)if(s[i]=='a')f[i]++;else g[i]++;
	rep(i,1,n+1)f[i]+=f[i-1],g[i]+=g[i-1];
	int ans=0;
	rep(i,1,n){
		rep(j,i-1,n){
			ans=max(ans,f[i-1]+g[j]-g[i-1]+f[n]-f[j]);
		}
	}
	cout<<ans<<endl;
}