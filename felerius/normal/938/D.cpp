// region boilerplate
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
#   define all(a)      begin(a),end(a)
#   define sz(x)       ((int)size(x))
#else
#   define all(a)      (a).begin(),(a).end()
#   define sz(x)       ((int)(x).size())
#endif

#define rep(a, b)      for(int a = 0; a < (b); ++a)
#define reps(a, b, c)  for(int a = (b); a < (c); ++a)
#define trav(a, b)     for(auto& a : b)

using ll = long long;
using ld = long double;
using u64 = uint64_t;
using u32 = uint32_t;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vpi = vector<pi>;

#if __cplusplus >= 201703L
#   define MAYBE_UNUSED [[maybe_unused]]
#else
#   define MAYBE_UNUSED
#endif

MAYBE_UNUSED static constexpr int INF = (int)1e9 + 5;
MAYBE_UNUSED static constexpr ll INFL = (ll)1e18 + 5;
MAYBE_UNUSED static mt19937 rng((u32)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
//endregion

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<tuple<int, int, ll>> e(m);
    vector<vector<pair<int, ll>>> adj(n);
    rep(i, m) {
        int u, v; ll w; cin >> u >> v >> w; --u, --v;
        adj[u].emplace_back(v, 2 * w);
        adj[v].emplace_back(u, 2 * w);
    }
    vl a(n);
    trav(ai, a) cin >> ai;

    priority_queue<pair<ll, int>> q;
    rep(i, n)
        q.emplace(-a[i], i);
    while (sz(q)) {
        auto [dist, v] = q.top(); q.pop();
        if (-dist != a[v])
            continue;
        for (auto [v2, w] : adj[v])
            if (-dist + w < a[v2])
                a[v2] = -dist + w, q.emplace(-a[v2], v2);
    }

    rep(i, n)
        cout << a[i] << ' ';
    cout << '\n';

    return 0;
}