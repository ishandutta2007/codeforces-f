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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    set<ll>q;
    map<ll,ll>f;
    map<ll,set<ll>>to,g;
    q.insert(0);
    for(int n=read();n--;)
    {
        char k=read<char>();
        ll x=read<ll>();
        if(k=='+')
        {
            for(ll y:to[x])g[y].erase(x);
            q.insert(x);
        }
        else if(k=='-')
        {
            for(ll y:to[x])g[y].insert(x);
            q.erase(x);
        }
        else
        {
            while(q.count(f[x]))to[f[x]].insert(x),f[x]+=x;
            if(g[x].empty())cout<<f[x]<<'\n';
            else cout<<min(f[x],*g[x].begin())<<'\n';
        }
    }
}