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
        ll l ,r;
        cin>>n>>l>>r;
        map<ll,ll>m1;
        fo(i,l){
            cin>>k;
            m1[k]++;
        }
        fo(i,r){
            cin>>k;
            m1[k]--;
        }
        ll x=0,y=0;
        ll ans=0;
        ll x1=0,y1=0;
        fo1(i,n){
            if(m1[i]<0){
                m1[i]=-1*m1[i];
                x1+=(m1[i]/2)*2;
                x+= m1[i];
            }
            else{
                y1+=(m1[i]/2)*2;
                y+= m1[i];
            }
        }

        if(x>=y){
            if(x-y <=x1){
                ans+= (x+y)/2;
            }
            else{ 
                ans+= y + x1/2 + (x-y - x1);
            }
        }
        else{
            if(y-x <=y1){
                ans+= (x+y)/2;
            }
            else{ 
                ans+= x + y1/2 + (y-x - y1);
            }
        }
        cout<<ans<<endl;




        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}