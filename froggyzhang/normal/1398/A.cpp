#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 50050
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,a[N],T;
void Solve(){
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	if(a[1]+a[2]>a[n]){
		printf("-1\n");
	}
	else{
		printf("1 2 %d\n",n);
	}
}
int main(){
	T=read();
	while(T--){
		n=read();
		Solve();
	}
	return 0;
}