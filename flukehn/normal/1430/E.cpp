#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(int i=(b),i##_end=(a);i>=i##_end;--i)
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define foe(i,a) for(__typeof(a.begin())i=a.begin();i!=a.end();++i)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef double ld;
typedef long long L;
typedef long double lf;
typedef unsigned int uint;
typedef unsigned long long uL;
typedef vector<int> VI;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f,mo=1e9+7;
template<typename A,typename B>inline bool upmx(A&x,const B&y){return x<y?x=y,1:0;}
template<typename A,typename B>inline bool upmn(A&x,const B&y){return x>y?x=y,1:0;}
template<typename T>inline T gcd(T x,T y){for(;y;swap(x,y))x%=y;return x;}
inline int Pow(int a,int b,int p=mo){int r=1;for(;b;b>>=1,a=1ll*a*a%p)if(b&1)r=1ll*r*a%p;return r;}
#ifdef flukehn
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
const int N=2e5+11;
int a[N];
int n;
char s[N],t[N];
VI e[26],f[26];
int c[N];
void add(int x){
	for(;x<=n;x+=x&-x)
		c[x]++;
}
int qry(int x){
	int r=0;
	for(;x;x-=x&-x)
		r+=c[x];
	return r;
}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
	//ios::sync_with_stdio(0);
#endif
	cin>>n>>s+1;
	rep(i,1,n){
		int x=s[i]-'a';
		e[x].pb(i);
		f[x].pb(n-i+1);
	}
	L ans=0;
	For(i,0,26){
		reverse(all(f[i]));
		For(j,0,SZ(e[i])){
			//a[e[i][j]]=f[i][j];
			a[f[i][j]]=e[i][j];
		}
	}
	//rep(i,1,n)cerr<<a[i]<<" \n"[i==n];
	per(i,1,n){
		ans+=qry(a[i]);
		add(a[i]);
	}
	cout<<ans<<endl;
}