//2019.8.27 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f
#define unl __int128
#define eps 5.6e-8
#define RG register
#define db double
#define pc(x) __builtin_popcount(x)
//#define pc(x) __builtin_popcountll(x)
typedef pair<int,int> Pair;
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1.0)
#define pb push_back
#define ull unsigned LL
#define gc getchar
//inline char gc() {
//    static char buf[100000],*p1,*p2;
//    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
//}
//inline int read() {
//    res s=0,ch=gc();
//    while(ch<'0'||ch>'9')ch=gc();
//    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
//    return s;
//}
inline int read() {
    res s=0,ch=gc(),w=1;
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=gc();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
    return s*w;
}
//inline LL Read() {
//    RG LL s=0;
//    res ch=gc();
//    while(ch<'0'||ch>'9')ch=gc();
//    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
//    return s;
//}
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
inline void swap(res &x,res &y) {
    x^=y^=x^=y;
}
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//clock_t start=clock();
//inline void ck(){
//    if(1.0*(clock()-start)/CLOCKS_PER_SEC>0.1)exit(0);
//}
const int N=1e6+10;
const int M=(1<<21)+10;
namespace MAIN{
    int n;
    int a[N];
    Pair dp[M];
    inline Pair operator + (const RG Pair &x,const res &y){
        if(!y)return x;
        int tmp[3]={x.fi,x.se,y};
        sort(tmp,tmp+3);
        return mp(tmp[1],tmp[2]);
    }
    inline Pair operator + (RG Pair x,const RG Pair &y){
        x=x+y.fi+y.se;
        return x;
    }
    int ans;
    inline bool ck(const RG Pair &x,const res &I){
        return x.se&&x.fi>I;
    }
    int lg,end;
    inline void MAIN(){
        n=read();
        for(res i=1;i<=n;i++)a[i]=read(),dp[a[i]]=dp[a[i]]+i,lg=max(int(log2(a[i])),lg);
        end=(1<<(lg+1))-1;
        for(res i=0;i<=lg;i++)
            for(res S=0;S<=end;S++)
                if(S&(1<<i))dp[S^(1<<i)]=dp[S^(1<<i)]+dp[S];
        for(res i=1;i<=n;i++){
            res cnt=end-a[i],nS=0;
            for(res j=lg;~j;j--)if(cnt&(1<<j)&&ck(dp[nS|(1<<j)],i))nS|=1<<j;
            if(ck(dp[nS],i))ans=max(ans,nS|a[i]);
        }
        printf("%d\n",ans);
    }
}
int main(){
//    srand(19260817);
//    freopen("signin.in","r",stdin);
//    freopen("signin.out","w",stdout);
    MAIN::MAIN();
    return 0;
}