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
#define fo(i,n) for(int i=0;i<n;i++)
#define fo1(i,n) for(int i=1;i<=n;i++)
ll mod=1000000007;
ll n,k,t,m,q,flag=0;
ll po(ll k ,ll n,ll ans,ll temp,ll ans1){
    if(n==0)return ans;
    while(temp<=n){
        ans*=ans1;ans%=mod;ans1=ans1*ans1;ans1%=mod;n=n-temp;temp*=2;
    }
    return po(k,n,ans,1,k)%mod;
    //eg. po(2,78,1,1,2);
}
ll min(ll a,ll b){if(a>b)return b;else return a;}
ll max(ll a,ll b){if(a>b)return a;else return b;}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin>>t;
    //t=1;
    while(t--){
    	cin>>n;
    	ll a[n];
    	fo(i,n)cin>>a[i];
    	vector<ll>v;
    	ll mini=0;
    	fo(i,n){
    		if(a[i]==-1){
    			if(i>0)if(a[i-1]!=-1)v.pb(a[i-1]);
    			if(i<n-1)if(a[i+1]!=-1)v.pb(a[i+1]);
    		}
    		 else if(i<n-1)if(a[i+1]!=-1)mini=max(mini,abs(a[i+1]- a[i]));
    	}
    	sort(all(v));
    	if(v.size()==0)cout<<"0 0"<<endl;
    	else cout<<max(mini, (v[v.size()-1]- v[0]+1)/2 )<<" "<<(v[0]+v[v.size()-1] )/2<<endl;
    	
    }

    return 0;
}