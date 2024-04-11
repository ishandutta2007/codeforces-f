#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define min amin
#define max amax
#define pb push_back
using namespace std;
using ll=long long;
using pii=array<int,2>;
constexpr int N=2E5+10;
constexpr int inf=1<<30;
constexpr int p=998244353;
int qpow(int x,int n=p-2){int y=1;for(;n;n>>=1,x=1LL*x*x%p)if(n&1)y=1LL*y*x%p;return y;}
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename U,typename V>U min(U x,V y){return x<y?x:y;}
template<typename U,typename V>U max(U x,V y){return x>y?x:y;}
template<typename U,typename...V>U min(U x,V...y){return min(x,min(y...));}
template<typename U,typename...V>U max(U x,V...y){return max(x,max(y...));}
template<typename U,typename V>bool cmin(U &x,V y){return x>y?x=y,true:false;}
template<typename U,typename V>bool cmax(U &x,V y){return x<y?x=y,true:false;}

int a[N],b[N],f[N];
void solve()
{
    int n=read();
    for(int i=1;i<=n;++i)cin>>a[i];
    --a[1];
    for(int i=1;i<=n;++i)
    {
        cin>>b[i];
        if(i&1)f[i]=max(f[i-1],a[i]+(n-i+1<<1),b[i]+(n-i<<1)+1);
        else f[i]=max(f[i-1],b[i]+(n-i+1<<1),a[i]+(n-i<<1)+1);
    }
    int mn=inf;
    for(int i=n,u=0,v=0;i>=1;--i)
    {
        cmax(++u,max(b[i]+1,a[i]+(n-i+1<<1)));
        cmax(++v,max(a[i]+1,b[i]+(n-i+1<<1)));
        if(i&1)cmin(mn,max(f[i-1],u));
        else cmin(mn,max(f[i-1],v));
    }
    cout<<mn<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    for(int T=read();T--;solve());
}