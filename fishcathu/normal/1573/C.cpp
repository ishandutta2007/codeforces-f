#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2E5+10;
const int inf=1<<30;
auto max(auto l,auto r){return l>r?l:r;}
auto min(auto l,auto r){return l<r?l:r;}
ll read()
{
    ll a=0;
    char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(ll x,char c)
{
    if(x<0)putchar(45),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
int in[N],a[N];
vector<int>q,to[N];
void solve()
{
    int n=read();
    for(int i=1;i<=n;++i)to[i].clear(),a[i]=1;
    for(int i=1;i<=n;++i)
    {
        in[i]=read();
        if(!in[i])q.pb(i);
        for(int j=in[i];j--;)to[read()].pb(i);
    }
    int res=0;
    while(!q.empty())
    {
        int x=q.back();
        q.pop_back();
        --n;
        res=max(res,a[x]);
        for(int t:to[x])
        {
            a[t]=max(a[t],a[x]+(x>t));
            if(!--in[t])q.pb(t);
        }
    }
    if(n)puts("-1");
    else write(res,'\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}