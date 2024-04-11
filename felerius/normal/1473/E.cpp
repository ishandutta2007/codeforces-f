// Minimum path (https://codeforces.com/contest/1473/problem/E)

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <chrono>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#if __cplusplus >= 201703L
#   include <optional>
#   include <string_view>
#   define all(a)      ::begin(a),::end(a)
#   define sz(x)       ((int)::size(x))
#   define MAYBE_UNUSED [[maybe_unused]]
#else
#   define all(a)      (a).begin(),(a).end()
#   define sz(x)       ((int)(x).size())
#   define MAYBE_UNUSED
#endif

#define _choose(_1, _2, _3, chosen, ...) chosen
#define _rep0(i, r)       for (int i = 0; i < r; ++i)
#define _repn(i, l, r)    for (int i = l; i < r; ++i)
#define _repr0(i, r)      for (int i = r; i >= 0; --i)
#define _reprn(i, r, l)   for (int i = r; i >= l; --i)
#define rep(...)          _choose(__VA_ARGS__, _repn, _rep0, suppress_warning)(__VA_ARGS__)
#define repr(...)         _choose(__VA_ARGS__, _reprn, _repr0, suppress_warning)(__VA_ARGS__)
#define trav(a, b)        for(auto& a : b)

using namespace std;

using ll = long long;
using ld = long double;
using u128 = unsigned __int128;
using u64 = uint64_t;
using u32 = uint32_t;

MAYBE_UNUSED static constexpr int INF = (int)1e9 + 5;
MAYBE_UNUSED static constexpr ll INFL = (ll)INF * INF;
MAYBE_UNUSED static mt19937 rng((u32)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());

namespace cp_lib {}

using namespace cp_lib;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    auto adj = vector(n, vector(0, pair(0, 0)));
    rep(_, m) {
        int u, v, w; cin >> u >> v >> w; --u, --v;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vector dist(4 * n, INFL);
    dist[0] = 0;
    priority_queue<pair<ll, int>> q;
    q.emplace(0, 0);

    while (sz(q)) {
        auto [d, x] = q.top(); q.pop(); d = -d;
        int u = x / 4, a = x / 2 % 2, b = x % 2;
        if (d > dist[x])
            continue;
        for (auto [y, w] : adj[u]) {
            int v1 = 4 * y + 2 * a + b, v2 = 4 * y + 2 + b, v3 = 4 * y + 2 * a + 1;
            if (dist[v1] > dist[x] + w)
                q.emplace(-(dist[v1] = dist[x] + w), v1);
            if (!a && dist[v2] > dist[x])
                q.emplace(-(dist[v2] = dist[x]), v2);
            if (!b && dist[v3] > dist[x] + 2 * w)
                q.emplace(-(dist[v3] = dist[x] + 2 * w), v3);
        }
    }

    rep(i, 1, n)
        cout << min(dist[4 * i], dist[4 * i + 3]) << ' ';
    cout << '\n';

    return 0;
}