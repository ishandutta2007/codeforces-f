#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define fi first
#define se second
#define pb emplace_back
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
using ll=long long;
using pa=pair<int,int>;
template<class A,class B>inline bool upmx(A&x,const B&y){return x<y?x=y,1:0;}
template<class A,class B>inline bool upmn(A&x,const B&y){return x>y?x=y,1:0;}
const int mo=998244353;
constexpr int Pow(int a,int b,int p=mo){int r=1;for(;b;b>>=1,a=1ll*a*a%p)if(b&1)r=1ll*r*a%p;return r;}
constexpr int reduce(int x){return x+(x>>31&mo);}
constexpr int& inc(int &x,int y){return x=reduce(x+y-mo);}
constexpr int& dec(int &x,int y){return x=reduce(x-y);}
#ifdef flukehn
void debug_out(){cerr<<endl;}
template <typename Head,typename... Tail>
void debug_out(Head H,Tail... T){
  cerr<<" "<<H;//to_string(H);
  debug_out(T...);
}
#define dbg(...) cerr<<"L"<<__LINE__<<" ["<<#__VA_ARGS__<<"]:",debug_out(__VA_ARGS__)
#define debug(...) cerr<<__VA_ARGS__//fprintf(stderr, __VA_ARGS__)
#else
#define dbg(...) 0
#define debug(...) 0
#endif
const int N=511;
const int inf=~0u>>2;
int n,k,l;
ll f[N][N];
int d[N],a[N];
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  cin>>n>>l>>k;
  For(i,0,n)cin>>d[i];
  For(i,0,n)cin>>a[i];
  d[n]=l;
  memset(f,0x3f,sizeof f);
  f[0][0]=0;
  for(int i=0;i<n;++i){
    for(int j=0;j<=k;++j){
      for(int x=i+1;x<=n;++x){
        int y=j+x-i-1;
        if(y>k)break;
        f[x][y]=min(f[x][y],f[i][j]+(d[x]-d[i])*a[i]);
      }
    }
  }
  ll ans=~0uLL>>2;
  //For(i,0,n+1) dbg(f[i][k]);
  For(j,0,k+1)ans=min(ans,f[n][j]);
  cout<<ans<<"\n";
}