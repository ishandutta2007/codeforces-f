/*

*/

#include <bits/stdc++.h>
#include <cassert>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'
#define Ln '\n'

#define MAX 101010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

vector<ll> asdf;

void solve() {
	ll N, K;
	cin >> N >> K;
	ll i;
	ll a;
	ll mx = -1010101010101010;
	vector<ll> v;
	for (i = 1; i <= N; i++) {
		cin >> a;
		v.push_back(a);
	}
	ll j;
	for (i = max(0LL, N - K - 10); i < N; i++) {
		for (j = i + 1; j < N; j++) {
			mx = max(mx, (i + 1) * (j + 1) - K * (v[i] | v[j]));
		}
	}
	cout << mx << ln;
}

void init() {

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll T;
	tmode;
	while (T--) {
		init();
		solve();
	}
}