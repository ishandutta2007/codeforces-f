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

void solve()
{
	int n=read(),m=read(),k;
	while(m>3)
	{
		printf("1 ");
		--n;
		--m;
	}
	if(n&1)k=1;
	else if(n&2)k=2;
	else k=n>>1;
	n=n-k>>1;
	printf("%d %d %d\n",k,n,n);
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}