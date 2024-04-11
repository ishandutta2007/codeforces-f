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
const int N=2E5+10;
const int inf=1<<30;
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename T1,typename T2>auto min(T1 l,T2 r){return l<r?l:r;}
template<typename T1,typename T2>auto max(T1 l,T2 r){return l>r?l:r;}
template<typename T,typename...Args>auto min(T l,Args...args){return min(l,min(args...));}
template<typename T,typename...Args>auto max(T l,Args...args){return max(l,max(args...));}
template<typename T1,typename T2>bool cmin(T1 &l,T2 r){return l>r?l=r,1:0;}
template<typename T1,typename T2>bool cmax(T1 &l,T2 r){return l<r?l=r,1:0;}

vector<int>to[N];
int a[N],fa[N];
bool vis[N];
void dfs(int x)
{
    for(int t:to[x])if(t^fa[x])
    {
        fa[t]=x;
        dfs(t);
    }
}
int calc(int x)
{
    if(vis[x])return 0;
    vis[x]=1;
    return calc(fa[x])+1;
}
void solve()
{
    int n=read(),m=read(),y=read(),z=read();
    for(int i=1;i<=n;++i)to[i].clear(),vis[i]=0;
    for(int i=1;i<=m;++i)cin>>a[i];
    for(int i=n;--i;)
    {
        int u=read(),v=read();
        to[u].pb(v);
        to[v].pb(u);
    }
    fa[y]=0;
    dfs(y);
    vis[y]=1;
    int ans=calc(z);
    for(int i=1;i<=m;++i)ans+=calc(a[i])<<1;
    cout<<ans<<'\n';
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    for(int T=read();T--;solve());
}