//2019.9.2 by ljz
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
const int N=2000+10;
namespace MAIN{
    int n;
    char s[N],t[N],S[N],T[N];
    int ans[N*5],ansx;
    int buc[26+10],Buc[26+10];
    inline void MAIN(){
        n=read(),scanf("%s%s",s+1,t+1);
        for(res i=1;i<=n;i++)buc[s[i]-'a']++,Buc[t[i]-'a']++,T[i]=s[i];
        for(res i=0;i<26;i++)if(buc[i]!=Buc[i]){puts("-1");return;}
        res p=0;
        while(233){
            if(p==n)break;
            res ch=t[p+1],id=0;
            for(res i=n-p;i;i--)if(s[i]==ch){id=i;break;}
            ans[++ansx]=n-id,ans[++ansx]=1,ans[++ansx]=n;
            for(res i=1;i<id;i++)S[i]=s[id-i];
            for(res i=id;i<n;i++)S[i]=s[i+1];
            S[n]=s[id];
            for(res i=1;i<=n;i++)s[i]=S[i];
            p++;
        }
        printf("%d\n",ansx);
        for(res i=1;i<=ansx;i++)printf("%d ",ans[i]);
//        for(res i=1;i<=ansx;i++){
//            for(res j=1;j<=ans[i];j++)S[j]=T[n-j+1];
//            for(res j=ans[i]+1;j<=n;j++)S[j]=T[j-ans[i]];
//            for(res j=1;j<=n;j++)T[j]=S[j];
//        }
//        printf("%s\n",T+1);
    }
}
int main(){
//    srand(19260817);
//    freopen("signin.in","r",stdin);
//    freopen("signin.out","w",stdout);
    MAIN::MAIN();
    return 0;
}