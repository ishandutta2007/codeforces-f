// Interesting Story (https://codeforces.com/contest/1551/problem/C)
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
        int n; cin >> n;
        vector<string> w(n);
        trav(wi, w) cin >> wi;
        int mx = 0;
        rep(c, 5) {
            vector<int> d(n, 0);
            rep(i, n)
                trav(ch, w[i])
                    d[i] += (ch - 'a' == c ? 1 : -1);
            sort(all(d));
            int sum = 0;
            while (sz(d) && sum + d.back() > 0)
                sum += d.back(), d.pop_back();
            mx = max(mx, n - sz(d));
        }

        cout << mx << '\n';
    }
}