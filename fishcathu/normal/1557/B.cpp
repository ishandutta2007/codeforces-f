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
const int N=1E5+10;
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
int a[N],b[N];
void solve()
{
    int n=read(),m=read();
    for(int i=1;i<=n;++i)a[i]=read(),b[i]=i;
    sort(b+1,b+1+n,[](int l,int r){return a[l]<a[r];});
    for(int i=2;i<=n;++i)
    {
        if(b[i]==b[i-1]+1)
        {
            ++m;
        }
    }
    puts(m>=n?"Yes":"No");
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}