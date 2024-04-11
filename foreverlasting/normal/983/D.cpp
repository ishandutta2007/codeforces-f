//2019.9.4 by ljz
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
//#define pc(x) __builtin_popcountll(x)
typedef pair<int,int> Pair;
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1.0)
#define pb push_back
#define ull unsigned LL
#define gc getchar
//template <class T>using Tree=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
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
inline void swap(res &x,res &y) {
    x^=y^=x^=y;
}
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//clock_t start=clock();
//inline void ck(){
//    if(1.0*(clock()-start)/CLOCKS_PER_SEC>0.1)exit(0);
//}
const int N=2e5+10;
namespace MAIN{
    int n;
    int bB[N],Bb[N],bBx,Bbx;
    vector<int> G[N];
    struct P{
        int x,y,X,Y;
        inline void init(){
            x=read(),y=read(),X=read(),Y=read();
            bB[++bBx]=x,bB[++bBx]=X;
            Bb[++Bbx]=y,Bb[++Bbx]=Y;
        }
        inline void ini(const res &I){
            x=int(lower_bound(bB+1,bB+bBx+1,x)-bB),X=int(lower_bound(bB+1,bB+bBx+1,X)-bB);
            y=int(lower_bound(Bb+1,Bb+Bbx+1,y)-Bb),Y=int(lower_bound(Bb+1,Bb+Bbx+1,Y)-Bb-1);
            G[x].pb(I),G[X].pb(-I);
        }
    }a[N];
    bool fl[N];
    struct TR{
        set<int> S;
        int mn,mx,len;
    }tr[N<<2];
    inline void pushup(const res &rt){
        res ls=rt<<1,rs=rt<<1|1;
        if(tr[rt].len==1)tr[rt].mn=tr[rt].mx=0;
        else tr[rt].mn=min(tr[ls].mn,tr[rs].mn),tr[rt].mx=max(tr[ls].mx,tr[rs].mx);
        if(tr[rt].S.size())fl[*tr[rt].S.rbegin()]?tr[rt].mn=max(tr[rt].mn,*tr[rt].S.rbegin()):tr[rt].mx=max(tr[rt].mx,*tr[rt].S.rbegin());
        if(tr[rt].mx<tr[rt].mn)tr[rt].mx=0;
    }
    void build(res rt,res l,res r){
        tr[rt].len=r-l+1;
        if(l==r)return;
        res mid=(l+r)>>1;
        build(rt<<1,l,mid),build(rt<<1|1,mid+1,r);
    }
    void modify(res rt,res l,res r,const res &L,const res &R,const res &col){
        if(L<=l&&r<=R){
            if(col>0)tr[rt].S.insert(col);
            else tr[rt].S.erase(-col);
            pushup(rt);
            return;
        }
        res mid=(l+r)>>1;
        if(L<=mid)modify(rt<<1,l,mid,L,R,col);
        if(R>mid)modify(rt<<1|1,mid+1,r,L,R,col);
        pushup(rt);
    }
    int ans=1;
    inline void MAIN(){
        n=read();
        for(res i=1;i<=n;i++)a[i].init();
        sort(bB+1,bB+bBx+1),sort(Bb+1,Bb+Bbx+1),bBx=int(unique(bB+1,bB+bBx+1)-bB-1),Bbx=int(unique(Bb+1,Bb+Bbx+1)-Bb-1);
        for(res i=1;i<=n;i++)a[i].ini(i);
        build(1,1,Bbx);
        for(res i=1;i<=bBx;i++){
            for(auto x:G[i])modify(1,1,Bbx,a[abs(x)].y,a[abs(x)].Y,x);
            while(tr[1].mx)fl[tr[1].mx]=1,ans++,modify(1,1,Bbx,a[tr[1].mx].y,a[tr[1].mx].Y,0);
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