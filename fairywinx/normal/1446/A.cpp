#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ctime>
#include <queue>
#include <assert.h>
#include <iomanip>
#include <deque>
#include <map>
#include <random>
#include <cmath>
#include <bitset>
#include <complex>

#include <algorithm>
#define int long long 
#define SOLVE int t; cin >> t; while(t--) solve();
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma optimize("O3")

using namespace std;

void setup() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	#endif
		srand(time(0));
}

void solve() {
	int n, w;
	cin >> n >> w;
	int mn = (w + 1) / 2;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		if (a[i] >= mn && a[i] <= w) {
			cout << 1 << '\n' << i + 1 << '\n';
			return;
		}
	}
	vector<int> ans;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] + sum <= w) {
			sum += a[i];
			ans.push_back(i);
			if (sum >= mn) {
				cout << ans.size() << '\n';
				for (int i : ans)
					cout << i + 1 << ' ';
				return;
			}
		}
	}
	cout << -1 << '\n';
}

signed main() {
	setup();
	SOLVE;
	
	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s  ";
	#endif
}