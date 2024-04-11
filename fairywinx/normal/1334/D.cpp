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
#include <cmath>

#include <algorithm>
#define int long long
#define SOLVE int t; cin >> t; while(t--) solve();
// #define double long double

// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma optimize("O3");

using namespace std;

void setup() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);
	#endif

	srand(time(0));
}

const int MOD = 1e9 + 7;
const int N = 2e5 + 228;

int pow(int a, int b) {
	if (b == 0)
		return 1;
	if (b % 2 == 1)
		return (a * pow(a, b - 1)) % MOD;
	int z = pow(a, b / 2);
	return (z * z) % MOD;
}

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

void solve() {
	int n, l, r;
	cin >> n >> l >> r;
	vector<int> ans;
	int sum = 0;
	for(int i = 0; i < (n - 1); ++i) {
		if (sum + 2 * (n - i - 1) < l) {
			sum += 2 * (n - i - 1);
			continue;
		}
		if (sum > r)
			continue;
		for(int j = 1; j <= 2 * (n - i - 1); ++j) {
			sum++;
			if (sum < l)
				continue;
			if (sum > r)
				continue;
			else {
				if (j % 2 == 1) 
					ans.push_back(i + 1);
				else 
					ans.push_back(j / 2 + i + 1);
			}
		}
	}
	if (sum < r)
		ans.push_back(1);
	assert(ans.size() == r - l + 1);
	for(auto i: ans)
		cout << i << ' ';
	cout << '\n';
}

signed main() {
	setup();
	SOLVE;

	

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}