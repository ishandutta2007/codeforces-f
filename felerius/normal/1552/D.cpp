// Array Differentiation (https://codeforces.com/contest/1552/problem/D)
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

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector a(n, 0);
        trav(ai, a) cin >> ai;

        bool any = false;
        vector t(n, 0);
        while (1) {
            int sum = 0;
            rep(i, n)
                sum += (t[i] == 1 ? a[i] : (t[i] == 2 ? -a[i]: 0));
            rep(i, n)
                if (t[i] == 0)
                    any |= (sum == a[i]);

            int i = 0;
            while (i < n && t[i] == 2)
                t[i] = 0, ++i;
            if (i == n)
                break;
            t[i]++;
        }

        cout << (any ? "YES\n" : "NO\n");
    }
}