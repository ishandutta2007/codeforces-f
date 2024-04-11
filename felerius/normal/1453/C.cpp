// Triangles (https://codeforces.com/contest/1453/problem/C)

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <chrono>
#include <cstdint>
#include <deque>
#include <exception>
#include <forward_list>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#if __cplusplus >= 201703L
#   include <optional>
#   include <string_view>
#   include <variant>
#endif

using namespace std;

#if __cplusplus >= 201703L
#   define all(a)      ::begin(a),::end(a)
#   define sz(x)       ((int)::size(x))
#else
#   define all(a)      (a).begin(),(a).end()
#   define sz(x)       ((int)(x).size())
#endif

#define _choose(_1, _2, _3, chosen, ...) chosen
#define _rep0(i, r)       for (int i = 0; i < r; ++i)
#define _repn(i, l, r)    for (int i = l; i < r; ++i)
#define _repr0(i, r)      for (int i = r; i >= 0; --i)
#define _reprn(i, r, l)   for (int i = r; i >= l; --i)
#define rep(...)          _choose(__VA_ARGS__, _repn, _rep0, suppress_warning)(__VA_ARGS__)
#define repr(...)         _choose(__VA_ARGS__, _reprn, _repr0, suppress_warning)(__VA_ARGS__)
#define trav(a, b)        for(auto& a : b)

using ll = long long;
using ld = long double;

#if __cplusplus >= 201703L
#   define MAYBE_UNUSED [[maybe_unused]]
#else
#   define MAYBE_UNUSED
#endif

MAYBE_UNUSED static constexpr int INF = (int)1e9 + 5;
MAYBE_UNUSED static constexpr ll INFL = (ll)INF * INF;
MAYBE_UNUSED static mt19937 rng((uint32_t)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());

namespace cp_lib {}

using namespace cp_lib;

constexpr int N = 2005;
int d[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    string line;
    while (t--) {
        int n; cin >> n;
        rep(i, n) {
            cin >> line;
            rep(j, n) d[i][j] = line[j] - '0';
        }

        array<int, 10> leftmost{}, rightmost{}, topmost{}, bottommost{};
        leftmost.fill(n), topmost.fill(n);
        rep(i, n) rep(j, n) {
            int c = d[i][j];
            leftmost[c] = min(leftmost[c], j);
            rightmost[c] = max(rightmost[c], j);
            topmost[c] = min(topmost[c], i);
            bottommost[c] = max(bottommost[c], i);
        }

        array<int, 10> res{};

        rep(i, n) {
            array<int, 10> l{};
            l.fill(-1);
            rep(j, n) {
                int c = d[i][j];
                if (l[c] == -1)
                    l[c] = j;
                else
                    res[c] = max(res[c], (j - l[c]) * max(i, n - i - 1));

                int mx_h = max(i - topmost[c], bottommost[c] - i);
                res[c] = max(res[c], mx_h * max(j, n - j - 1));
            }
        }

        rep(j, n) {
            array<int, 10> t{};
            t.fill(-1);
            rep(i, n) {
                int c = d[i][j];
                if (t[c] == -1)
                    t[c] = i;
                else
                    res[c] = max(res[c], (i - t[c]) * max(j, n - j - 1));

                int mx_w = max(j - leftmost[c], rightmost[c] - j);
                res[c] = max(res[c], mx_w * max(i, n - i - 1));
            }
        }

        rep(i, 10)
            cout << res[i] << ' ';
        cout << '\n';
    }

    return 0;
}