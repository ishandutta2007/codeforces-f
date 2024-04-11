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
typedef pair<int, int> pii;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'
#define Ln '\n'

#define MAX 201010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

int arr[MAX];

void solve() {
	int N;
	cin >> N;
	int i;
	for (i = 1; i <= N; i++) cin >> arr[i];
	if (N & 1) {
		cout << -1 << Ln;
		return;
	}
	vector<pii> vpi;
	for (i = 1; i <= N; i += 2) {
		if (arr[i] == arr[i + 1]) vpi.emplace_back(pii(i, i + 1));
		else vpi.emplace_back(pii(i, i)), vpi.emplace_back(pii(i + 1, i + 1));
	}
	cout << vpi.size() << ln;
	for (auto& [a, b] : vpi) cout << a << bb << b << ln;
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