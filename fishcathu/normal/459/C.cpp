#include<bits/extc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1010;
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
int a[N][N];
int main()
{
    int n=read(),m=read(),k=read();
    for(int j=0;j<n;++j)
    {
        int x=j;
        for(int i=0;i<k;++i)a[i][j]=x%m+1,x/=m;
        if(x){puts("-1");return 0;}
    }
    for(int i=0;i<k;++i)
    {
        for(int j=0;j<n;++j)write(a[i][j],' ');
        putchar('\n');
    }
}