#include<bits/stdc++.h>
#define ll long long 
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
const int xx=20;
char s[xx];
int gnum()
{
	fflush(stdout);
	int w=read();
	for(int i=1;i<=w;i++)
	scanf("%s",s);
	return w;
}
int main(){
	int lun=0;
	while(1)
	{
		++lun;
		cout<<"next "<<0<<" "<<1<<"\n";
		gnum();
		cout<<"next "<<1<<"\n";
		if(gnum()==2)
		{
		cout<<"next ";
		for(int i=0;i<=9;i++)cout<<i<<" ";
		puts("");
			while(gnum()!=1)
			{
				cout<<"next ";
				for(int i=0;i<=9;i++)cout<<i<<" ";
				puts("");
			}
			cout<<"done\n";
			exit(0);
//			break;
		}
	}
	pc('1',1);
	return 0;
}