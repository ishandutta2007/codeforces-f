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
constexpr int N=10;
constexpr int inf=1E9;
constexpr int p=998244353;
int qpow(int x,int n=p-2){int y=1;for(;n;n>>=1,x=1LL*x*x%p)if(n&1)y=1LL*y*x%p;return y;}
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename U,typename V>U min(U x,V y){return x<y?x:y;}
template<typename U,typename V>U max(U x,V y){return x>y?x:y;}
template<typename U,typename...V>U min(U x,V...y){return min(x,min(y...));}
template<typename U,typename...V>U max(U x,V...y){return max(x,max(y...));}
template<typename U,typename V>bool cmin(U &x,V y){return x>y?x=y,true:false;}
template<typename U,typename V>bool cmax(U &x,V y){return x<y?x=y,true:false;}

int a[N],b[N],f[N],g[N],n,m;
bool check()
{
    for(int i=1;i<=n;++i)if(f[i]>1||g[i]>1)return 0;
    return 1;
}
bool solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)f[i]=g[i]=0;
    for(int i=1;i<=m;++i)++f[a[i]=read()],++g[b[i]=read()];
    for(int i=1;i<=m;++i)
    {
        --f[a[i]];
        --g[b[i]];
        for(int j=1;j<=n;++j)
        {
            if(j^a[i])
            {
                ++f[j];
                ++g[b[i]];
                if(check())return 1;
                --f[j];
                --g[b[i]];
            }
            if(j^b[i])
            {
                ++f[a[i]];
                ++g[j];
                if(check())return 1;
                --f[a[i]];
                --g[j];
            }
        }
        ++f[a[i]];
        ++g[b[i]];
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    for(int T=read();T--;cout<<(solve()?"YES":"NO")<<'\n');
}