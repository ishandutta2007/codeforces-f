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
template<typename U,typename V>auto min(U x,V y){return x<y?x:y;}
template<typename U,typename V>auto max(U x,V y){return x>y?x:y;}
template<typename U,typename...V>auto min(U x,V...y){return min(x,min(y...));}
template<typename U,typename...V>auto max(U x,V...y){return max(x,max(y...));}
template<typename U,typename V>bool cmin(U &x,V y){return x>y?x=y,true:false;}
template<typename U,typename V>bool cmax(U &x,V y){return x<y?x=y,true:false;}

int a[N],b[N];
bool l[N],r[N];
void solve()
{
    int n=read(),m=read(),k=read(),s=read();
    for(int i=1;i<=s;++i)cin>>a[i]>>b[i];
    int ans=1;
    for(int i=s;i>=1&&n&&m;--i)
    {
        if(!l[a[i]]||!r[b[i]])ans=1LL*ans*k%p;
        if(!l[a[i]])n-=l[a[i]]=1;
        if(!r[b[i]])m-=r[b[i]]=1;
    }
    cout<<ans<<'\n';
    for(int i=1;i<=s;++i)l[a[i]]=r[b[i]]=0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(6);
    for(int T=read();T--;solve());
}