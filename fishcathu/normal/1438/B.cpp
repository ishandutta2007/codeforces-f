#include<bits/stdc++.h>
using namespace std;
const int N=2E5+10;
int read()
{
    int a=0;char b=1,c;
    do if((c=getchar())==45)b=-1;while(!(c&16));
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())&16);
    return a*b;
}
void write(int x)
{
    if(x<0)putchar('-'),x=-x;
    char a[10],s=0;
    do a[s++]=x%10|48;while(x/=10);
    do putchar(a[--s]);while(s);
}
int a[N];
int main()
{
	for(int x=read();x--;)
	{
		int n=read();
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		int i=2;
		for(;i<=n&&a[i]!=a[i-1];++i);
		puts(i>n?"NO":"YES");
	}
}