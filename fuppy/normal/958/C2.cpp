//#include "stdafx.h";


#include "bits/stdc++.h"

using namespace std;

#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cout<<" "<<v[i]; cout<<endl

typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
const int inf = 1000000001;
const ll INF = 2e18;
const ll MOD = 1000000007;
//const ll mod = 1000000009;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p <<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };

#define vlll vector<vll>

int main() {
	int n, k, p;
	cin >> n >> k >> p;
	vl a(n);
	rep(i, n) {
		cin >> a[i];
		a[i] %= p;
	}
	vlll dp(2, vll(k, vl(p, -INF)));
	dp[0][0][0] = 0;
	rep(i0, n) {
		int i = i0 % 2;
		rep(j, k) {
			rep(l, p) {
				dp[1 - i][j][l] = -INF;
			}
		}
		rep(j, k) {
			rep(l, p) {
				dp[1 - i][j][(l + a[i0]) % p] = max(dp[1 - i][j][(l + a[i0]) % p], dp[i][j][l]);
				if (i0 != 0 && j != k - 1) {
					dp[1 - i][j + 1][a[i0]] = max(dp[1 - i][j + 1][a[i0]], dp[i][j][l] + l);
				}
			}
		}
	}
	ll ans = 0;
	rep(l, p) {
		ans = max(ans, dp[n % 2][k - 1][l] + l);
	}
	cout << ans << endl;
}