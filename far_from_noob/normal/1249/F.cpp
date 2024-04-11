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

ll a[205];
vll v[205];
ll dp[205][205];

void dfs(ll node, ll root){
    fo1(i,k+1)dp[node][i]=0;
    dp[node][1]=a[node];
    ll sum[k+2],maxi[k+2];
    fo1(i,k+1)sum[i]=0,maxi[i]=0;
    fo(i,v[node].size()){
        if(v[node][i]==root)continue;
        dfs(v[node][i],node);
        fo1(j,k+1){
            sum[j]+=dp[v[node][i]][j];
            maxi[j]=max(maxi[j] , dp[v[node][i]][j] - dp[v[node][i]][max(k+1-j,j)] );
        }
    }
    dp[node][1]+=sum[k+1];
    for(int i=2;i<=k+1;i++){
        dp[node][i]= maxi[i-1]+ sum[max(k+1-i+1,i-1)];
    }
    for(int i=k;i>=1;i--){dp[node][i]= max(dp[node][i], dp[node][i+1]);}
    // cout<<node<<endl;
    // fo1(i,k+1)cout<<dp[node][i]<<" ";cout<<endl;

    return;

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef NOOBxCODER
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else 
    #define NOOBxCODER 0
    #endif
    //cin>>t;
    t=1;
    while(t--){
        cin>>n>>k;
        ll mm=0;
        fo(i,n)cin>>a[i+1],mm=max(mm,a[i+1]);
        fo(i,n-1){
            ll x,y;
            cin>>x>>y;
            v[x].pb(y);
            v[y].pb(x);
        }
        if(k>=n-1){cout<<mm; return 0;}
        dfs(1,1);
        fo1(i,k+1)mm=max(dp[1][i],mm);
        cout<<mm;




        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}