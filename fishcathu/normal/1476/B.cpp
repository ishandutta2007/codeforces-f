#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
ll a[N];
void solve()
{
	int n=read(),m=read();
	ll mx=0,now=read();
	while(--n)
	{
		ll t=read();
		ll z=t*100/m;
		if(t*100%m)++z;
		mx=max(mx,z-now);
		now+=t;
	}
	write(mx,'\n');
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}