#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
#define fi first
#define se second
#define vll vector<ll>
#define pll pair<ll,ll>
#define fo(i,n) for(int i=0;i<n;i++)
#define fo1(i,n) for(int i=1;i<=n;i++)
ll mod=1000000007;
ll n,k,t,m,q,flag=0;
ll power(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// ordered_set s ; s.order_of_key(a) -- no. of elements strictly less than a
// s.find_by_order(i) -- itertor to ith element (0 indexed)
ll min(ll a,ll b){if(a>b)return b;else return a;}
ll max(ll a,ll b){if(a>b)return a;else return b;}
ll gcd(ll a , ll b){ if(b > a) return gcd(b , a) ; if(b == 0) return a ; return gcd(b , a%b) ;}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef NOOBxCODER
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else 
    #define NOOBxCODER 0
    #endif
    cin>>t;
    //t=1;
    while(t--){
        cin>>n>>m;
        ll a[n];
        fo(i,n)cin>>a[i];
        fo(i,n)a[i]--;
        ll count[n];fo(i,n)count[i]=0;
        fo(i,n){
            count[ (i-a[i] +n)%n ] ++;
        }
        vll ans;
        fo(j,n){
            if(count[j]>=(n- 2*m)){
                //cout<<j<<"xx"<<endl;
                ll b[n];
                fo(i,n)b[i]= a[(i+j)%n];
                //fo(i,n)cout<<b[i];cout<<endl;
                ll val=0;
                ll c[n];fo(i,n)c[i]=0;
                fo(i,n){
                    if(b[i]==i)continue;
                    if(c[i] == 1) continue;
                    ll curr = b[i];
                    c[i]=1;
                    c[curr]=1;
                    val++;
                    while(1){
                        //cout<<curr<<endl;
                        if(b[curr]==i )break;
                        c[b[curr]]=1;
                        curr=b[curr];
                        //b[temp]=-1;
                        val++;
                    }
                }
                //cout<<val<<endl;

                if(val <=m) ans.pb(j);

            }
        }
        cout<<ans.size()<<" ";
        fo(i,ans.size())cout<<ans[i]<< " ";cout<<endl;




        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}