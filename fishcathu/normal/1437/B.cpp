#include<cstdio>
const int N=5E4+1;
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

int main()
{
	for(int x=read();x--;)
	{
		int n=read(),ans=0;
		char c;
		while(!((c=getchar())&16));
		for(int i=n,k=0;--i;)
		{
			if(getchar()!=c)ans+=k,k=1;
			else k=0;
		}
		printf("%d\n",ans);
	} 
}