// Fixed Points (https://codeforces.com/contest/1551/problem/E)
#pragma GCC optimize("fast-math")
// begin "cp-lib/boilerplate.hpp"
#include <bits/stdc++.h>
#ifdef LOCAL
#  include <dbg.h>
#else
#  define dbg(...) do {} while (0)
#endif

#define _choose(_1, _2, _3, x, ...)     x
#define _rep(i, l, r)                   for (int i = l; i < r; ++i)
#define _rep0(i, r)                     _rep(i, 0, r)
#define rep(...)                        _choose(__VA_ARGS__, _rep, _rep0, _)(__VA_ARGS__)
#define _repr(i, r, l, ...)             for (int i = r; i >= l; --i)
#define repr(...)                       _repr(__VA_ARGS__, 0)
#define all(a)                          ::begin(a),::end(a)
#define trav(a, b)                      for (auto&& a : b)

using namespace std;
namespace cp_lib {}

using ll = long long;
using ld = long double;
[[maybe_unused]] static constexpr int INF = int(1e9 + 5);
[[maybe_unused]] static constexpr ll INFL = ll(INF) * INF;
template <class C> int sz(const C& c) { return int(::size(c)); }
// end "cp-lib/boilerplate.hpp"

using namespace cp_lib;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector a(n, 0);
        trav(ai, a)
            cin >> ai;

        // dp[i][j]: maximum number of matched elements when creating
        // a sequence of length j from the first i elements
        vector dp(n + 1, vector(n + 1, -INF));
        dp[0][0] = 0;
        rep(i, n) {
            auto& row = dp[i + 1], prev_row = dp[i];
            row[0] = 0;
            rep(l, 1, n + 1)
                row[l] = max(prev_row[l], prev_row[l - 1] + (a[i] == l));
        }

        int l = n;
        while (l > 0 && dp[n][l] < k)
            --l;
        cout << (l ? n - l : -1) << '\n';
    }
}