#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3E5+10;
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
ll sum,mn=1ll<<62,summ;
int mx;
void solve(int n)
{
	ll s=0;
	int mnn=1<<30;
	for(int i=1;i<=n;++i)
	{
		int t=read();
		s+=t;
		mnn=min(mnn,t);
	}
	sum+=s;
	mn=min(mn,s);
	summ+=mnn;
	mx=max(mx,mnn);
}
int a[4];
int main()
{
	for(int i=1;i<=3;++i)a[i]=read();
	for(int i=1;i<=3;++i)solve(a[i]);
	mn=min(mn,summ-mx);
	write(sum-mn*2,'\n');
}