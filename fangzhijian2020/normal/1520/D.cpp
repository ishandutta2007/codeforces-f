#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int T,n,a[200005],h[400005],del=200003;long long ans;
int main(){
	T=read()+1;
	while(--T){
		n=read();ans=0;
		for(int i=1;i<=n;++i){
			a[i]=read();
			ans+=h[a[i]-i+del];
			++h[a[i]-i+del];
		}
		for(int i=1;i<=n;++i){
			h[a[i]-i+del]=0;
		}
		cout<<ans<<"\n";
	}
	return 0;
}