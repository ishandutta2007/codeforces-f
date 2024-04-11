// #define GLIBCXX_DEBUG

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
// #include <cmath>
#include <bitset>

#include <algorithm>
#define int long long

// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma optimize("O3");

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

const int MOD = 998244353;
const int INF = 2e18;

int pow(int a, int b) {
	if (b == 0)
		return 1;
	if (b % 2 == 1)
		return (a * pow(a, b - 1)) % MOD;
	int z = pow(a, b / 2);
	return (z * z) % MOD;
}

signed main() {
	setup();
	
	int n;
	cin >> n;
	int res = 1;
	vector<int> nd(5000);
	nd[1] = 2;
	nd[0] = 1;
	n -= 2;
	for(int i = 2; i < 5000; ++i) {
		nd[i] = 2;
		for(int j = 0; j < i - 1; ++j) {
			nd[i] += nd[j];
			if (nd[i] > INF)
				break;
		}
	}
	// for(int i = 0; i < 10; ++i)
	// 	cout << nd[i] << ' ';
	// cout << '\n';
	while(true) {
		if (nd[res - 1] <= n) {
			n -= (nd[res - 1]);
			++res;
		}
		else
			break;
	}
	cout << res;

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}