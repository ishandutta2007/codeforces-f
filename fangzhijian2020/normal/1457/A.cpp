#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read(){
	int a=0,opt=0;char c=getchar();while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();return opt?-a:a;
}
int T,n,m,r,c;
int main(){
	T=read()+1;
	while(--T){
		n=read();m=read();r=read();c=read();
		printf("%d\n",max(r-1,n-r)+max(c-1,m-c));
	}
	return 0;
}