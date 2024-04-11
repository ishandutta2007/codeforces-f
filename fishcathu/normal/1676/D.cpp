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
const int N=210;
const int inf=1E9;
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename T1,typename T2>auto min(T1 l,T2 r){return l<r?l:r;}
template<typename T1,typename T2>auto max(T1 l,T2 r){return l>r?l:r;}
template<typename T,typename...Args>auto min(T l,Args...args){return min(l,min(args...));}
template<typename T,typename...Args>auto max(T l,Args...args){return max(l,max(args...));}
template<typename T1,typename T2>bool cmin(T1 &l,T2 r){return l>r?l=r,1:0;}
template<typename T1,typename T2>bool cmax(T1 &l,T2 r){return l<r?l=r,1:0;}

const pii nex[4]={1,1,1,-1,-1,1,-1,-1};
int a[N][N];
void solve()
{
    int n=read(),m=read(),ans=0;
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)cin>>a[i][j];
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)
    {
        int res=a[i][j];
        for(auto [l,r]:nex)for(int u=i,v=j;;)
        {
            u+=l;
            v+=r;
            if(u<1||u>n||v<1||v>m)break;
            res+=a[u][v];
        }
        cmax(ans,res);
    }
    cout<<ans<<'\n';
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    for(int T=read();T--;solve());
}