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

#define MAX 101010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

//var

//

void solve() {
	int N, M;
	string s1, s2;
	cin >> N >> M;
	cin >> s1 >> s2;
	if (M == N) {
		if (s1 == s2) cout << yes << ln;
		else cout << no << ln;
		return;
	}
	int mn, mx;
	int i;
	for (i = 1; i < M; i++) {
		if (s2[i] != s1[i + N - M]) {
			cout << no << ln;
			return;
		}
	}
	mn = 1, mx = 0;
	for (i = 0; i <= N - M; i++) mn = min(mn, (int)s1[i] - '0');
	for (i = 0; i <= N - M; i++) mx = max(mx, (int)s1[i] - '0');
	if (mn <= s2[0] - '0' && s2[0] - '0' <= mx) cout << yes << ln;
	else cout << no << ln;
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