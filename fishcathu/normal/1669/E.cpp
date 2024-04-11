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
const int N=11;
const int inf=1<<30;
template<typename T=int>T read(){T x;cin>>x;return x;}
template<typename T1,typename T2>auto min(T1 l,T2 r){return l<r?l:r;}
template<typename T1,typename T2>auto max(T1 l,T2 r){return l>r?l:r;}
template<typename T,typename...Args>auto min(T l,Args...args){return min(l,min(args...));}
template<typename T,typename...Args>auto max(T l,Args...args){return max(l,max(args...));}
template<typename T1,typename T2>bool cmin(T1 &l,T2 r){return l>r?l=r,1:0;}
template<typename T1,typename T2>bool cmax(T1 &l,T2 r){return l<r?l=r,1:0;}

int a[N][N],b[N],c[N];
void solve()
{
    for(int n=read();n--;)
    {
        int l=read<char>()-97,r=read<char>()-97;
        ++a[l][r];
        ++b[l];
        ++c[r];
    }
    ll ans=0;
    for(int i=0;i<N;++i)for(int j=0;j<N;++j)
    {
        ans+=1LL*a[i][j]*(b[i]+c[j]-a[i][j]*2);
        a[i][j]=0;
    }
    for(int i=0;i<N;++i)b[i]=c[i]=0;
    cout<<ans/2<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    for(int T=read();T--;solve());
}