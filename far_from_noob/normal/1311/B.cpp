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
        cin>>n>>m;
        ll a[n];
        fo(i,n)cin>>a[i];
        ll p[m];
        fo(i,m){
            cin>>p[i];
        }
        sort(p,p+m);
        ll temp=0;
        fo(i,m){
            if(i<m-1){
                if(p[i+1]==p[i]+1)temp++;
                else{
                    sort(a+p[i]-1-temp,a+p[i]+1);
                    temp=0;
                
                }
            }
            else sort(a+p[i]-1-temp,a+p[i]+1);

        }
        flag=0;
        fo(i,n-1){
            //cout<<a[i+1];
            if(a[i+1]>=a[i]);
            else flag=1;
        }
        if(flag==1)cout<<"NO";
        else cout<<"YES";
        cout<<endl;
    }

    return 0;
}