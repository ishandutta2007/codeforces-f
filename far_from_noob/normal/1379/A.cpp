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
        cin>>n;
        string s;
        cin>>s;
        vll v;
        ll count=0;
        string s1="abacaba";
        fo(i,s.size()-6){
            flag=0;
            ll is=0;
            fo(j,7){
                
                
                if(s[i+j]!=s1[j])is=1;
                
            }
            if(is==0){
                count++;
            }
        }
        if(count>=1){
            if(count==1){
                cout<<"YES"<<endl;
                fo(i,s.size()){
                    if(s[i]=='?')cout<<'z';
                    else cout<<s[i];
                }
                cout<<endl;
            }
            else cout<<"NO"<<endl;
            continue;
        }
        ll pos=0;
        fo(i,s.size()-6){
            vll v;
            ll is=0;
            fo(j,7){
                if(s[i+j]!='?'){if(s[i+j]!=s1[j])is=1;}
                else v.pb(i+j);
            }
            if(is==1){
                if(s[i]=='?')s[i]='z';
                continue;
            }
            flag=0;
            for(int j=i+7; j<= i+10; j++){
                if(j>=s.size()){flag=1; break;}
                if(s[j]!=s1[j- i-4]){flag=1; break;}
            }
            if(flag==0){
                if(v[0]-i>=4){
                fo(j,v.size()){s[v[j]]='z';}}
                else{
                    fo(j,v.size()){if(v[j]-i<4)s[v[j]]='z';}
                }
            }
            else{
                pos=1;
                //cout<<i<<endl;
                fo(j,v.size())s[v[j]]=s1[v[j]-i];
                break;
            }


        }
        if(pos==0){cout<<"NO"<<endl;}
        else{
            cout<<"YES"<<endl;
                fo(i,s.size()){
                    if(s[i]=='?')cout<<'z';
                    else cout<<s[i];
                }
                cout<<endl;
        }









        
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}