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
        cin>>n>>k;
        map<ll,ll>m1;
        ll a[n];
        fo(i,n){
            cin>>m;
            a[i]=m;
            m1[m]++;
        }
        ll ans=0;
        vll v;  
        fo1(i,n){
            ans+= min(k , m1[i]);
            fo(j,min(k,m1[i]))v.pb(i);
        }
        vll v1[n+1];
        //cout<<v.size();
        //cout<<ans/ k *k<<endl;
        fo(i, (ans/k )* k) {
            //cout<<v[i]<< " " ;
            v1[v[i]].pb(i%k +1);
        }
        ll last[n+1];fo(i,n+1)last[i]=0;
        fo(i,n){
            if(last[a[i]]< v1[a[i]].size()){
                cout<<v1[a[i]][last[a[i]]]<<" ";
                last[a[i]]++;
            }
            else{
                cout<<0<< " ";
            }
        } 
        cout<<endl;







        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}