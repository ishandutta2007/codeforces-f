#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef vector<int> vct;
typedef pair<int,int> pii;
const int N=5E5+10;
const int inf=1<<30;
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
int a[N],col[N];
vct to[N];
bool b;
ll ans;
void dfs(int x)
{
    col[x]?ans+=a[x]:ans-=a[x];
    for(int t:to[x])
    {
        if(~col[t])
        {
            if(col[t]==col[x])b=1;
            continue;
        }
        col[t]=!col[x];
        dfs(t);
    }
}
bool solve()
{
    int n=read(),m=read();
    for(int i=1;i<=n;++i)a[i]=read();
    b=0;
    for(int i=1;i<=n;++i)
    {
        a[i]-=read();
        b^=a[i]&1;
        col[i]=-1;
        to[i].clear();
    }
    while(m--)
    {
        int u=read(),v=read();
        to[u].pb(v);
        to[v].pb(u);
    }
    if(b)return 0;
    ans=col[1]=0;
    dfs(1);
    return b||!ans;
}
int main()
{
    for(int x=read();x--;)
    {
        puts(solve()?"YES":"NO");
    }
}