#include<bits/stdc++.h>
using namespace std;
char c[510][510];
int n,m,i,j,has,l,r,u,d;
bool b,b1,b2,bon;
int main()
{
	cin>>n>>m;
	bon=1;
	b=0;b1=0;b2=0;
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	cin>>c[i][j];	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(b==0)
			{
				if(c[i][j]=='X')
				{
					if(b1==0)
					{
						l=j;
						b1=1;	
					}	
				}
				r=m;
				if(c[i][j]=='.'&&b1==1)
				{
					r=j-1;
					b=1;
					break;
				}
				
			}
			else
				break;
		}
		if(b1==1)
			b=1;
	}
	b=0;b1=0;b2=0;
	for(j=1;j<=m;j++)
	{
		for(i=1;i<=n;i++)
		{
			if(b==0)
			{
				if(c[i][j]=='X')
				{
					if(b1==0)
					{
						u=i;
						b1=1;	
					}	
				}
				d=n;
				if(c[i][j]=='.'&&b1==1)
				{
					d=i-1;
					b=1;
					break;
				}
			}
			else
				break;
		}
		if(b1==1)
			b=1;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(i>=u&&i<=d&&j>=l&&j<=r)
			{
				if(c[i][j]=='.')
				{
					//cout<<i<<j<<endl;
					bon=0;	
					break;	
				}
			}
			else
			{
				if(c[i][j]=='X')
				{
					//cout<<i<<j<<endl;
					bon=0;
					break;
				}
			}
		}
	}
	if(bon) cout<<"YES\n";
	else cout<<"NO\n";
//	cout<<u<<r<<d<<l<<endl;
}