//2019.9.24 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
#include<bits/stdc++.h>
//#include<ext/pb_ds/tree_policy.hpp>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f
#define unl __int128
#define eps 5.6e-8
#define RG register
#define db double
#define pc(x) __builtin_popcount(x)
#define ctz(x) __builtin_ctz(x)
//#define pc(x) __builtin_popcountll(x)
typedef pair<int,int> Pair;
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1.0)
#define pb push_back
#define ull unsigned LL
#define lowbit(x) (x&-x)
#define gc getchar
#define kcz 1000000007
//template <class T>using Tree=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//inline char gc() {
//    static char buf[100000],*p1,*p2;
//    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
//}
inline int read() {
	res s=0,ch=gc();
	while(ch<'0'||ch>'9')ch=gc();
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
	return s;
}
//char sr[1<<21],z[20];
//int C=-1,Z=0;
//inline void Ot(){fwrite(sr,1,C+1,stdout),C=-1;}
//inline void print(res x){
//    if(C>1<<20)Ot();if(x<0)sr[++C]='-',x=-x;
//    while(z[++Z]=x%10+48,x/=10);
//    while(sr[++C]=z[Z],--Z);sr[++C]='\n';
//}
//inline int read() {
//    res s=0,ch=gc(),w=1;
//    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=gc();}
//    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
//    return s*w;
//}
inline LL Read() {
	RG LL s=0;
	res ch=gc();
	while(ch<'0'||ch>'9')ch=gc();
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
	return s;
}
//inline LL Read() {
//    RG LL s=0;
//    res ch=gc(),w=1;
//    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=gc();}
//    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
//    return s*w;
//}
//inline void write(RG unl x){
//    if(x>10)write(x/10);
//    putchar(int(x%10)+'0');
//}
//inline void swap(res &x,res &y) {
//    x^=y^=x^=y;
//}
inline void add(res &x,const res &y){
    x+=y,x>=kcz?x-=kcz:(x<0?x+=kcz:1);
}
inline int Add(const res &x,const res &y){
    return x+y>=kcz?x+y-kcz:(x+y<0?x+y+kcz:x+y);
}
inline int mul(const res &x,const res &y){
    return int(1LL*x*y%kcz);
}
inline int mul(const res &x,const res &y,const res &d){
    return int(1LL*x*y/d%kcz);
}
inline int qpow(res x,res y){
    res ret=1;
    while(y){
        if(y&1)ret=mul(ret,x);
        x=mul(x,x),y>>=1;
    }
    return ret;
}
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//clock_t start=clock();
//inline void ck(){
//    if(1.0*(clock()-start)/CLOCKS_PER_SEC>0.1)exit(0);
//}
const int N=50+10;
const int dx[]={1,1},dy[]={1,-1};
namespace MAIN{
    int n;
    int a[N][N];
    inline int print(res x,res y,res X,res Y){
        printf("? %d %d %d %d\n",x,y,X,Y),puts("");
        fflush(stdout);
        return read();
    }
    bool vis[N][N];
	inline void MAIN(){
	    n=read(),a[1][1]=1,a[n][n]=0;
        a[1][3]=print(1,1,1,3);
        a[2][2]=print(1,1,2,2);
        a[2][3]=print(1,2,2,3)^1;
        a[2][1]=print(2,1,2,3)^1^a[2][3];
        for(res i=1;i<=2;i++)
            for(res j=4;j<=n;j++)
                a[i][j]=print(i,j-2,i,j)^1^a[i][j-2];
        for(res i=3;i<=n;i++)
            for(res j=1;j<=n;j++)
                a[i][j]=print(i-2,j,i,j)^1^a[i-2][j];
//	    for(res i=3;i<=n;i+=2)print(i-2,1,i,1),a[i][1]=read()?a[i-2][1]:a[i-2][1]^1;
//	    for(res i=n-2;i>0;i-=2)print(i,n,i+2,n),a[i][n]=read()?a[i+2][n]:a[i+2][n]^1;
//	    for(res i=2;i<n;i++){
//	        if(i&1){
//	            print(1,i-2,1,i),a[1][i]=read()?a[1][i-2]:a[1][i-2]^1;
//	            for(res j=3;j<=n;j+=2)print(j-2,i,j,i),a[j][i]=read()?a[j-2][i]:a[j-2][i]^1;
//	        }
//	        else {
//	            print(1,i-1,2,i),a[2][i]=read()?a[1][i-1]:a[1][i-1]^1;
//                for(res j=4;j<=n;j+=2)print(j-2,i,j,i),a[j][i]=read()?a[j-2][i]:a[j-2][i]^1;
//	        }
//	    }
        for(res i=1;i<n;i++)
            for(res j=1;j+2<=n;j++){
                res s=a[i][j]^a[i+1][j+2];
                if((a[i][j+1]^a[i][j+2])==s||(a[i][j+1]^a[i+1][j+1])==s||(a[i+1][j]^a[i+1][j+1])==s){
                    res t=print(i,j,i+1,j+2);
                    if(s==t)
                        for(res x=1;x<=n;x++)
                            for(res y=1;y<=n;y++)
                                a[x][y]^=x+y&1;
                    puts("!");
                    for(res x=1;x<=n;++x,puts(""))
                        for(res y=1;y<=n;y++)
                            putchar(a[x][y]+'0');
                    return;
                }
            }
	}
}
int main() {
//    srand(19260817);
//    freopen("path.in","r",stdin);
//    freopen("path.out","w",stdout);
	MAIN::MAIN();
//    Ot();
	return 0;
}