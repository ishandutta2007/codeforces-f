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
int arr[MAX];

void solve() {
	int N, M;
	cin >> N >> M;
	int i;
	if (N > M) {
		cout << "No" << ln;
		return;
	}
	if (N & 1) {
		cout << "Yes" << ln;
		for (i = 1; i < N; i++) cout << 1 << bb;
		cout << M - N + 1 << ln;
	}
	else if (N % 2 == 0 && M % 2 == 0) {
		cout << "Yes" << ln;
		for (i = 1; i <= N - 2; i++) cout << 1 << bb;
		cout << (M - N + 2) / 2 << bb;
		cout << (M - N + 2) / 2 << ln;
	}
	else if (M % N == 0) {
		cout << "Yes" << ln;
		for (i = 1; i <= N; i++) cout << M / N << bb;
		cout << Ln;
	}
	else {
		cout << "No" << Ln;
	}
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