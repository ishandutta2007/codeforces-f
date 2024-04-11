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
constexpr int N=5E5+10;
constexpr int inf=1E9;
constexpr int p=998244353;
int qpow(int x,int n=p-2){int y=1;for(;n;n>>=1,x=1LL*x*x%p)if(n&1)y=1LL*y*x%p;return y;}
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename U,typename V>auto min(U x,V y){return x<y?x:y;}
template<typename U,typename V>auto max(U x,V y){return x>y?x:y;}
template<typename U,typename...V>auto min(U x,V...y){return min(x,min(y...));}
template<typename U,typename...V>auto max(U x,V...y){return max(x,max(y...));}
template<typename U,typename V>bool cmin(U &x,V y){return x>y?x=y,true:false;}
template<typename U,typename V>bool cmax(U &x,V y){return x<y?x=y,true:false;}

vector<pii>to[N];
int fa[N],las[N],siz[N],f[N<<1];
void dfs(int x)
{
    siz[x]=1;
    for(auto [t,w]:to[x])if(!siz[t])
    {
        fa[t]=las[w];
        las[w]=t;
        dfs(t);
        siz[x]+=siz[t];
        f[fa[t]]-=siz[t];
        f[t]+=siz[t];
        las[w]=fa[las[w]];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    int n=read();
    for(int i=n;--i;)
    {
        int u=read(),v=read(),w=read();
        to[u].pb({v,w});
        to[v].pb({u,w});
    }
    for(int i=1;i<=n;++i)f[las[i]=i+n]=n;
    dfs(1);
    ll ans=0;
    for(int i=2;i<=n;++i)ans+=1LL*f[i]*f[fa[i]];
    cout<<ans<<'\n';
}