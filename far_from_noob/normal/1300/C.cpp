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
    //cin>>t;
    t=1;
    while(t--){
    	cin>>n;
    	ll a[n];
    	ll pre[n],suf[n];
    	fo(i,n)cin>>a[i];
    	pre[0]=a[0];
    	suf[0]=a[n-1];
    	fo1(i,n-1){
    		pre[i]=pre[i-1]|a[i];
    		suf[i]=suf[i-1]|a[n-1-i];
    	}
    	ll ans=0;
    	ll index=0;
    	fo(i,n){
    		if(i==0){
    			ll kk=(a[i]|suf[n-2]) - suf[n-2];
    		if(ans<kk)index=i;
    		 ans=max(ans, kk);
    		 //cout<<ans;
    		}
    		else if(i==n-1){
    			ll kk=(a[i]|pre[n-2]) - pre[n-2];
    			if(ans<kk)index=i;
    			ans=max(ans,kk);
    			//cout<<ans;
    		}
    		else {
    			ll temp=pre[i-1]| suf[n-2-i];
    			ll kk=(a[i]|temp )- temp;
    			if(ans<kk)index=i;
    			ans=max(ans,kk);
    			//cout<<ans;
    		} 
    	}
    	//cout<<pre[0];
    	cout<<a[index]<<" ";
    	fo(i,n){
    		if(i==index);
    		else cout<<a[i]<<" ";
    	}

    	
    }

    return 0;
}