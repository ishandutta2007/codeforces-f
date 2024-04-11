// Contest: Ozon Tech Challenge 2020 (Div.1 + Div.2, Rated, T-shirts + prizes!) (https://codeforces.com/contest/1305)
// Problem: F: Kuroni and the Punishment (https://codeforces.com/contest/1305/problem/F)


// region {{{ boilerplate
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
//endregion }}}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vl a(n);
    int mn = 0;
    trav(ai, a) cin >> ai, mn += ai % 2;

    auto check_single = [&](ll d) {
        ll cost = 0;
        trav(ai, a) {
            cost += min(ai >= d ? ai % d : INFL, d - ai % d);
            if (cost >= mn)
                break;
        }
        if (cost < mn)
            mn = cost;
    };

    auto check = [&](ll g) {
        for (ll i = 2; i * i <= g; ++i) {
            if (g % i)
                continue;
            check_single(i);
            while (!(g % i))
                g /= i;
        }
        if (g > 1)
            check_single(g);
    };

    uniform_int_distribution<int> dist(0, n - 1);
    rep(i, 25) {
        ll x = a[dist(rng)];
        if (x > 1)
            check(x - 1);
        check(x);
        check(x + 1);
    }

    cout << mn << '\n';
    return 0;
}