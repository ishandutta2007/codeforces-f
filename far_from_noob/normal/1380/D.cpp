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
    //cin>>t;
    t=1;
    while(t--){
        cin>>n>>m;
        ll x,k,y;
        cin>>x>>k>>y;
        ll a[n+1],b[m+2];
        fo(i,n)cin>>a[i+1];
        fo(i,m)cin>>b[i+1];
        a[0]=0;
        b[0]=0;
        b[m+1]=0;
        ll maxi=0;
        ll last=0;
        ll ans=0;
        ll temp=1;
        flag=0;
        fo1(i,n){
            if(a[i]==b[temp]){
                ll val=i-last-1;
                //cout<<val<<" "<<maxi<<" ";
                last=i;
                if(maxi> b[temp-1] && maxi>b[temp]){
                    if(val<k){cout<<-1; return 0;}
                    ans+=x;
                    val-=k;
                    if(k*y < x){
                        ans+=val*y;
                    }
                    else{
                        ans+=val/k *x;
                        ans+=(val%k)*y; 
                    }
                    //cout<<ans;

                }
                else{
                    if(k*y < x){
                        ans+=val*y;
                    }
                    else{
                        ans+=val/k *x;
                        ans+=(val%k)*y; 
                    }
                }
                temp++;
                maxi=0;
                //cout<<ans<<endl;
            }
            else maxi=max(maxi, a[i]);
        }
        if(temp!=m+1){cout<<-1; return 0;}
        ll val=n+1-last-1;
        //cout<<val;
        if(maxi> b[temp-1] && maxi>b[temp]){
                    if(val<k){cout<<-1; return 0;}
                    ans+=x;
                    val-=k;
                    if(k*y < x){
                        ans+=val*y;
                    }
                    else{
                        ans+=val/k *x;
                        ans+=(val%k)*y; 
                    }

                }
                else{
                    if(k*y < x){
                        ans+=val*y;
                    }
                    else{
                        ans+=val/k *x;
                        ans+=(val%k)*y; 
                    }
                    //cout<<ans;
                }
                temp++;
                maxi=0;
        cout<<ans;





        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}