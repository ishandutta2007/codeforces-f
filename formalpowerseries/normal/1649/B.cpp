/*

DONT NEVER AROUND . //
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char buf[1<<21],*p1=buf,*p2=buf;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
LL read()
{
	LL x=0;
	char c=getchar();
	while(c<'0' || c>'9')	c=getchar();
	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x;
}
void write(LL x)
{
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
LL a[100005],n;
void Solve()
{
	n=read();
	for(LL i=1;i<=n;++i)	a[i]=read();
	for(LL i=1;i<=n;++i)	if(a[i])	goto fail;
	puts("0");
	return ;
	fail:;
	LL sum=0,maxn=0;
	for(LL i=1;i<=n;++i)	sum+=a[i],maxn=max(maxn,a[i]);
	if(maxn*2<=sum)	puts("1");
	else	write(maxn-(sum-maxn)),puts("");
}
int main(){
	LL T=read();
	while(T-->0)	Solve();
	return 0;
}