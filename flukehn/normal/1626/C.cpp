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
inline int reduce(int x){return x+(x>>31&mo);}
inline int& inc(int &x,int y){return x=reduce(x+y-mo);}
inline int& dec(int &x,int y){return x=reduce(x-y);}
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
const int N=111;
int k[N],h[N];
ll f[N];
int n;
ll solve(){
  cin>>n;
  for(int i=1;i<=n;++i)cin>>k[i];
  for(int i=1;i<=n;++i)cin>>h[i];
  f[0]=0;
  for(int i=1;i<=n;++i){
    int mn=2e9;
    ll now=~0uLL>>2;
    for(int j=i;j>=1;--j){
      upmn(mn, k[j]-h[j]);
      if(mn<k[j-1]) continue;
      auto cal=[](int m){
        return 1LL*m*(m+1)/2;
      };
      upmn(now, f[j-1] + cal(k[i]-mn));
    }
    dbg(i,now);
    f[i]=now;
  }
  return f[n];
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int t;
  cin>>t;
  while(t--)
    cout<<solve()<<"\n";
}