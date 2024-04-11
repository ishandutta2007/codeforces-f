//2022.3.20 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
#include<bits/stdc++.h>
//#include<ext/pb_ds/tree_policy.hpp>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
#define res int
#define LL long long
#define Inf 0x3f3f3f3f
#define sup 0x7fffffff
#define inf 0x3f3f3f3f
#define INF 2000000000000000000
#define unl __int128
#define eps 1e-10
#define RG
#define db double
#define pc(x) __builtin_popcount(x)
#define ctz(x) __builtin_ctz(x)
//#define pc(x) __builtin_popcountll(x)
typedef pair<int,int> Pair;
#define poly vector<int>
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1.0)
#define pb push_back
#define ull unsigned LL
#define uint unsigned int
#define lowbit(x) ((x)&-(x))
#define gc getchar
#define ld long db
//template <class T>using Tree=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//inline int gc() {
//    static char buf[100000],*p1,*p2;
//    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
//}
//char sr[1<<21],z[20];
//int C=-1,Z=0;
//inline void Ot(){fwrite(sr,1,C+1,stdout),C=-1;}
//inline void print(RG LL x){
//    if(C>1<<20)Ot();if(x<0)sr[++C]='-',x=-x;
//    while(z[++Z]=x%10+48,x/=10);
//    while(sr[++C]=z[Z],--Z);
//}
//template <typename T> inline void Read(T &x) {
//    res c=gc();
//    bool f=false;
//    for(x=0;!isdigit(c);c=gc())if(c=='-')f=true;
//    for(;isdigit(c);c=gc())x=x*10+c-'0';
//    if(f)x=-x;
//}
inline int read() {
    res s=0,ch=gc(),w=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-')w=-1;
        else if(ch==EOF)break;
        ch=gc();
    }
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
    return s*w;
}
inline LL Read() {
    RG LL s=0;
    res ch=gc(),w=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-')w=-1;
        else if(ch==EOF)break;
        ch=gc();
    }
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
    return s*w;
}
inline void write(RG __int128 x){
    if(x>10)write(x/10);
    putchar(int(x%10)+'0');
}
const int kcz=998244353;
//const int G=3,GI=332748118;
//inline void add(res &x,const res &y){
//    x+=y,x>=kcz?x-=kcz:1;
//}
//inline int Add(const res &x,const res &y){
//    return x+y>=kcz?x+y-kcz:x+y;
//}
//inline int mul(const res &x,const res &y){
//    return int(1ll*x*y%kcz);
//}
#define add(x,y) ((x)+=(y),(x)>=kcz?(x)-=kcz:1)
#define Add(x,y) ((x)+(y)>=kcz?(x)+(y)-kcz:(x)+(y))
#define mul(x,y) (int)((LL)(x)*(y)%kcz)
#define Mul(x,y,d) (int)((ull)(x)*(y)/(d)%kcz)
inline int qpow(res x,res y=kcz-2){
    res ret=1;
    while(y){
        if(y&1)ret=mul(ret,x);
        x=mul(x,x),y>>=1;
    }
    return ret;
}
//inline int qpow(res x,res y,const res &ljc){
//    res ret=1;
//    while(y){
//        if(y&1)ret=(int)(1ll*ret*x%ljc);
//        x=(int)(1ll*x*x%ljc),y>>=1;
//    }
//    return ret;
//}
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//cloclim_t start=cloclim();
//inline void clim(){
//    if(1.0*(cloclim()-start)/CLOCKS_PER_SEC>0.1)exit(0);
//}
//2022.3.20 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
const int N=2e5+10;
int prim[N],tot,vis[N];
namespace MAIN{
    int n;
#define tup tuple<int,int,int>
    vector<tup> G[N];
    int ans[N];
    int cnt[N];
    void dfs(res x,res fax){
        for(auto [tox,u,v]:G[x]){
            if(tox==fax)continue;
            vector<int> ncnt(tot+1);
            for(res i=1;i<=tot;i++)ncnt[i]=cnt[i];
            for(res i=1;i<=tot;i++){
                res t=0;
                while(v%prim[i]==0)v/=prim[i],t++;
                cnt[i]-=t;
            }
            if(v>1)cnt[v]--;
            for(res i=1;i<=tot;i++){
                res t=0;
                while(u%prim[i]==0)u/=prim[i],t++;
                cnt[i]+=t;
            }
            if(u>1)cnt[u]++;
            for(res i=1;i<=tot;i++)ans[prim[i]]=max(ans[prim[i]],cnt[i]);
            if(v>1)ans[v]=max(ans[v],cnt[v]);
            if(u>1)ans[u]=max(ans[u],cnt[u]);
            dfs(tox,x);
            for(res i=1;i<=tot;i++)cnt[i]=ncnt[i];
            if(v>1)cnt[v]++;
            if(u>1)cnt[u]--;
        }
    }
    int Ans;
    int val[N];
    void Dfs(res x,res fax){
        add(Ans,val[x]);
        for(auto [tox,u,v]:G[x]){
            if(tox==fax)continue;
            val[tox]=mul(val[x],mul(qpow(u),v));
            Dfs(tox,x);
        }
    }
    inline void MAIN(const res &Case){
        n=read();
        for(res i=1;i<=n;i++)ans[i]=0,vector<tup>().swap(G[i]);
        for(res i=1;i<n;i++){
            res u=read(),v=read(),x=read(),y=read();
            res g=gcd(x,y);
            x/=g,y/=g;
            G[u].emplace_back(v,x,y),G[v].emplace_back(u,y,x);
        }
        dfs(1,0);
        val[1]=1;
        Ans=0;
        for(res i=1;i<=n;i++)val[1]=mul(val[1],qpow(i,ans[i]));
        Dfs(1,0);
        printf("%d\n",Ans);
    }
}
int main(){
    for(res i=2,sz=int(sqrt(N));i<=sz;i++){
        if(!vis[i])prim[++tot]=i;
        for(res j=1;j<=tot&&i*prim[j]<=sz;j++){
            vis[prim[j]*i]=1;
            if(i%prim[j]==0)break;
        }
    }
//    printf("%d\n",tot);
//    srand(time(0));
//    freopen("1.in","r",stdin);
//    freopen("1.out","w",stdout);
    res Case=read();
    for(res T=1;T<=Case;T++)MAIN::MAIN(T);
//    Ot();
    return 0;
}