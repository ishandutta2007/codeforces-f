#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1E5+10;
ll read()
{
    ll a=0;char b=1,c;
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
void solve()
{
	int n=read();
	putchar('9');
	for(int i=8;--n;++i)
	{
		if(i==10)i=0;
		putchar(i|48);
	}
	putchar('\n');
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}