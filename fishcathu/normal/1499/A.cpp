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
    if(x<0)putchar('-'),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
int f(int l,int r)
{
	if(l>r)swap(l,r);
	return l+(r-l>>1);
}
void solve()
{
	int n=read();
	int a=read(),b=read();
	int c=read(),d=read();
	puts(f(a,b)>=c&&f(n-a,n-b)>=d?"YES":"NO");
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}