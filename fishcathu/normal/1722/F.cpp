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
constexpr int N=100;
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

constexpr int q[9][2]={0,0,-1,-1,-1,0,-1,1,0,-1,0,1,1,-1,1,0,1,1};
bool a[N][N],b[N];
void solve()
{
    int n=read(),m=read();
    memset(a,0,sizeof a);
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)a[i][j]=read<char>()^'.';
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)if(a[i][j])
    {
        int t=0;
        for(int k=1;k<=8;++k)if(a[i+q[k][0]][j+q[k][1]])(t*=10)+=k;
        if(t>=N||!b[t])return cout<<"NO\n",void();
    }
    cout<<"YES\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    b[12]=b[23]=b[14]=b[46]=b[35]=b[58]=b[67]=b[78]=b[24]=b[25]=b[47]=b[57]=1;
    for(int T=read();T--;solve());
}