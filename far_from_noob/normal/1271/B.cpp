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
        string s;
        cin>>s;
        ll a=0,b=0;
        fo(i,s.size()){
            if(s[i]=='B')b++;
            else a++;
        }
        if(a%2==1 && b%2==1){cout<<-1;return 0;}
        vector<ll>ans;
        if(a%2==0){
            fo(i,s.size()-1){
                if(s[i]=='W'){ans.pb(i+1);
                s[i]='B';
                if(s[i+1]=='B')s[1+i]='W';
                else s[i+1]='B';}
            }
        }
        else {
            //cout<<"SDc";
            fo(i,s.size()-1){
                //cout<<s[i];
                if(s[i]=='B'){ans.pb(i+1);
                s[i]='W';
                if(s[i+1]=='W')s[1+i]='B';
                else s[i+1]='W';
            }
            }
        }
        cout<<ans.size();
        cout<<endl;
        fo(i,ans.size())cout<<ans[i]<<" ";

        
    }

    return 0;
}