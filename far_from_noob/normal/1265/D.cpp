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
    	ll a,b,c,d;
    	cin>>a>>b>>c>>d;
    	//ll flag1=0,flag2=0;
    	if(a<=b && d<=c){
    		if(b-a==c-d){
    			cout<<"YES"<<endl;
    			fo(i,a)cout<<"0 1 ";
    			fo(i,b-a)cout<<"2 1 ";
    			fo(i,d)cout<<"2 3 ";
    		}
    		else if(b-a==c-d+1){
    			cout<<"YES"<<endl;
    			cout<<1<<" ";
    			fo(i,a)cout<<"0 1 ";
    			fo(i,c-d)cout<<"2 1 ";
    			fo(i,d)cout<<"2 3 ";
    		}
    		else if(b-a+1==c-d){
    			cout<<"YES"<<endl;
    			fo(i,a)cout<<"0 1 ";
    			fo(i,b-a)cout<<"2 1 ";
    			fo(i,d)cout<<"2 3 ";
    			cout<<2;
    		}
    		else {cout<<"NO"; return 0;}
    	}
    	else if(a-b==1 && d==0&&c==0){
    		cout<<"YES"<<endl;
    		fo(i,b)cout<<"0 1 ";cout<<0;
    	}
    	else if(d-c==1 && b==0&&a==0){
    		cout<<"YES"<<endl;
    		fo(i,c)cout<<"3 2 ";cout<<3;
    	}
    	else {cout<<"NO"; return 0;}




    	



    	
    }

    return 0;
}